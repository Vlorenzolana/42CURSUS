# CPP Module 04 - Polimorfismo, clases abstractas e interfaces

*Este módulo forma parte del currículum de **42** y tiene como objetivo profundizar en el uso de **polimorfismo**, **herencia**, **clases abstractas** y el manejo adecuado de la memoria en C++98.*

---

## 📋 Normas de 42

| Regla | Descripción |
|-------|-------------|
| **Makefile** | Debe compilar con `c++`, flags `-Wall -Wextra -Werror`, y reglas `all`, `clean`, `fclean`, `re` |
| **Estándar** | C++98 obligatorio (`-std=c++98`) |
| **Memoria** | No memory leaks; toda memoria dinámica debe liberarse correctamente |
| **Forma canónica** | Todas las clases deben seguir la forma canónica ortodoxa (constructor, destructor, copy constructor, operator=) |
| **Encapsulamiento** | Atributos privados o protegidos; getters/setters cuando sea necesario |
| **Virtual destructor** | Los destructores de clases base polimórficas deben ser `virtual` |
| **Namespace/friend/using** | Prohibido usar `using namespace`, `friend` (excepto sobrecarga de operadores), y librerías externas (excepto STL cuando se indique) |
| **Headers** | Deben tener include guards (`#pragma once` o `#ifndef`) |

---

## 🗂️ Estructura del proyecto

```
CPP004/
├── ex00/   # Polymorphism
├── ex01/   # I don't want to set the world on fire (Brain)
├── ex02/   # Abstract class
└── README.md
```

---

## 🧪 Ejercicios

### ex00 - Polymorphism

**Objetivo:** Implementar una jerarquía de clases `Animal` → `Dog` / `Cat` con polimorfismo básico.

| Clase | Descripción |
|-------|-------------|
| `Animal` | Clase base con atributo `_type` protegido y método virtual `makeSound()` |
| `Dog` | Hereda de `Animal`, `_type = "Dog"`, sonido específico |
| `Cat` | Hereda de `Animal`, `_type = "Cat"`, sonido específico |
| `WrongAnimal` | Clase base **sin** métodos virtuales (comportamiento incorrecto) |
| `WrongCat` | Hereda de `WrongAnimal` (demuestra el fallo sin polimorfismo) |

```bash
cd ex00
make
./animal
```

---

### ex01 - I don't want to set the world on fire

**Objetivo:** Añadir un atributo `Brain*` a `Dog` y `Cat` con gestión de memoria dinámica y **deep copy**.

| Clase | Descripción |
|-------|-------------|
| `Brain` | Contiene un array de 100 `std::string ideas` |
| `Dog` | Tiene un `Brain*` que se crea en el constructor y se destruye correctamente |
| `Cat` | Igual que `Dog`, con su propio `Brain*` |

⚠️ **Importante:** Las copias deben ser **profundas** (deep copy), no shallow copy.

```bash
cd ex01
make
./animal
```

---

### ex02 - Abstract class

**Objetivo:** Convertir `Animal` en una **clase abstracta** para evitar su instanciación directa.

| Cambio | Descripción |
|--------|-------------|
| `makeSound() = 0` | Método **puro virtual** que hace la clase abstracta |
| Constructor protegido | Previene instanciación directa de `Animal` |

```bash
cd ex02
make
./animal
```

> 💡 Intentar crear un objeto `Animal` directamente generará error de compilación.

---

## 🛠️ Compilación

Cada ejercicio tiene su propio `Makefile`:

```bash
make        # Compila el ejecutable
make clean  # Elimina archivos objeto
make fclean # Elimina todo (objetos + ejecutable)
make re     # Recompila desde cero
```

**Flags de compilación:**
```
c++ -Wall -Wextra -Werror -std=c++98
```

---

## 📝 Conceptos clave

| Concepto | Explicación |
|----------|-------------|
| **Polimorfismo** | Permite que objetos de clases derivadas se traten como objetos de la clase base |
| **Virtual** | Keyword que permite sobreescribir métodos en clases derivadas |
| **Clase abstracta** | Clase con al menos un método puro virtual (`= 0`), no puede instanciarse |
| **Deep copy** | Copia de un objeto donde los punteros apuntan a nuevas copias de los datos, no a los originales |
| **Destructor virtual** | Necesario para liberar correctamente la memoria cuando se elimina un objeto a través de un puntero base |

---

## 👤 Autor

**vlorenzo** - *42 Student*

---

## 📄 Licencia

Este proyecto es parte del currículum de 42 y está sujeto a las normas académicas de la escuela.
