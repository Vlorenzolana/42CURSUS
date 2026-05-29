La arquitectura común de un Webserv en 42 es **dirigida por eventos** y **no bloqueante**. Como está prohibido usar hilos para manejar clientes, todo el servidor suele ejecutarse en un único bucle monohilo que monitoriza múltiples “eventos” a la vez.

Aquí tienes el desglose arquitectónico y un plan estratégico para dividir el trabajo en un equipo de tres personas.

# **La Arquitectura: “El Event Loop”**

En lugar de “un hilo por cliente”, usas **multiplexación por proceso**.

### **El Bucle Maestro:**

Usa `select()`, `poll()` o `epoll()` para preguntarle al kernel: **“¿Cuál de mis 100+ sockets tiene datos listos para leer, o está listo para recibir datos?”**

### **El Gestor de Sockets:**

Gestiona el ciclo de vida de una conexión: **Aceptar → Leer → Procesar → Escribir → Cerrar**

### **La Máquina de Estados:**

Como `read()` puede recibir solo medio header, cada cliente debe tener un **estado**, por ejemplo:

- READING_HEADER
    
- READING_BODY
    
- GENERATING_RESPONSE
    
- FINISHED
    

# **División del Equipo: El Plan de los 3 Pilares**

Para evitar pisarse el trabajo, divide el proyecto en estos tres dominios lógicos:

## **Miembro 1: El “Motor” (Infraestructura de I/O y Sockets)**

Esta persona construye el **corazón** del servidor. Es la parte más difícil técnicamente en cuanto a llamadas al sistema.

### **Tareas:**

- Implementar el bucle `poll()/select()/epoll()`

- Manejar `socket()`, `bind()`, `listen()` y `accept()`

- Configurar todos los FDs como `O_NONBLOCK`

- Gestionar el registro de clientes (un mapa de FDs a objetos Client)


### **Habilidad reutilizada:**

NetPractice (IP/puertos) y Philosophers (flujo lógico, aunque sin hilos)

## **Miembro 2: El “Parser” (Configuración y Lógica de Peticiones)**

Esta persona maneja la **entrada**. Se asegura de que el servidor entienda lo que el usuario quiere.

### **Tareas:**

- **Parser de configuración:** Leer el archivo `.conf` (estilo Nginx) y almacenarlo en un objeto `ServerConfig`

- **Parser de peticiones:** Convertir cadenas crudas del socket en un objeto `HttpRequest` (Método, Ruta, Headers, Cuerpo)

- **Chunked Encoding:** Manejar subidas HTTP especiales
    

### **Habilidad reutilizada:**

Minishell (lexer/parser) y C++ Modules (estructuras complejas como `std::map`)

## **Miembro 3: El “Responder” (Respuestas y CGI)**

Esta persona maneja la **salida**. Conecta el servidor con el sistema de archivos y los scripts externos.

### **Tareas:**

- **Constructor de respuestas:** Crear objetos `HttpResponse` (códigos de estado, Content-Type, headers)
    
- **Archivos estáticos:** Leer archivos del disco y manejar GET y DELETE
    
- **CGI Handler:** Gestionar `fork()`, `pipe()` y `execve()` para ejecutar scripts Python/PHP
    

### **Habilidad reutilizada:**

Pipex y Minishell (gestión de procesos y redirecciones)

# **Cómo Coordinarse (Las Interfaces)**

Para trabajar eficazmente, debéis acordar **desde el principio** los objetos que se pasarán entre vosotros:

### **1. Objeto** `ServerConfig`

El Miembro 2 se lo entrega al Miembro 1 para que el Motor sepa qué puertos abrir.

### **2. Objeto** `HttpRequest`

El Miembro 2 lo construye; el Miembro 3 lo usa para decidir qué hacer.

### **3. Clase** `Client`

Este es el **punto de encuentro**:

- Miembro 1 actualiza el socket del cliente
    
- Miembro 2 actualiza el buffer de petición
    
- Miembro 3 actualiza el buffer de respuesta
    

# **Consejo Profesional para el Equipo**

Comenzad construyendo un **servidor web estático** primero (solo GET y 200 OK). Cuando el Motor, el Parser y el Responder funcionen juntos para servir un archivo HTML o una imagen, añadir POST, DELETE y CGI será muchísimo más fácil.