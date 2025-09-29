# My Awesome PhoneBook — README (ex01)

> **C++ Module 00 – Exercise 01**
> Namespaces, classes, member functions, stdio streams, initialization lists, static, const…

Este documento explica **paso a paso** cómo compilar y usar el programa, con especial énfasis en **público/privado** y en **constructor/destructor** (y **cuándo** se usa el destructor).

En este proyecto (y en C++ en general) vemos .hpp y .cpp porque separamos declaraciones y definiciones. (Como .h y .c)

****OJO: no admite ñ, Ñ o acentos.. comportamiento imprevisible (no se pide por subject). Ver UFT-8 o 16 +info.

---

## 1) Estructura del proyecto

```
ex01/
├── Makefile
├── Contact.hpp
├── Contact.cpp
├── PhoneBook.hpp
├── PhoneBook.cpp
└── main.cpp
```

- **Sin asignación dinámica propia**: no se usa `new/delete` (se permite `std::string`).
- **Capacidad fija**: hasta **8 contactos** (se sobreescribe el más antiguo al añadir el 9º).
- **C++98**: compilar con `-std=c++98`.

---

## 2) Compilación y ejecución (Terminal)

Desde la carpeta `ex01`:

```bash
make        # compila y genera el ejecutable 'phonebook'
./phonebook # ejecuta
```

Objetivos útiles del Makefile:
```bash
make clean   # borra .o
make fclean  # borra .o y el ejecutable
make re      # limpia y recompila
```

> ⚠️ Las líneas de comandos en el Makefile deben empezar con **TAB**, no espacios.

---

## 3) Cómo usar el programa (flujo en Terminal)

Al ejecutar, verás un prompt con tres comandos válidos: `ADD`, `SEARCH`, `EXIT`.

### A) `ADD` — añadir un contacto
Se piden los campos **uno por uno**. **No se admiten vacíos**.
```text
> ADD
Enter your first name
Ada
Enter your last name
Lovelace
Enter your nickname
AdaL
Enter your phonenumber
+8900000000
Enter your darkest secret
Inventé bugs
contact has been added successfully
```

### B) `SEARCH` — listar y mostrar detalle
- Muestra una **tabla** con 4 columnas: `Index | First Name | Last Name | Nickname`.
- Cada columna se muestra con **ancho 10**, **alineada a la derecha** y con **punto final** si se trunca (ej. `Supercal.`).
- Luego pide un **índice 0–7** para mostrar el contacto completo (todos los campos).
```text
> SEARCH
|   Index  |First Name| Last Name| Nickname |
---------------------------------------------
|         0|       Ada|  Lovelace|      AdaL|
---------------------------------------------
Enter the index of the contact to display: 0
First Name: Ada
Last  Name: Lovelace
Nickname: AdaL
Phone Number: +89000000000
Darkest Secret: Inventé bugs
```

### C) `EXIT` — salir
Termina el programa. También puedes salir con **Ctrl+D** (EOF) cuando se espera entrada.

---

## 4) Clases y encapsulación: **público vs. privado**

### `Contact`
```cpp
class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

public:
    Contact();             // constructor
    ~Contact();            // destructor (vacío; ver sección 5)
    // setters y getters públicos
    void set_first_name(const std::string&);
    void set_last_name(const std::string&);
    void set_nickname(const std::string&);
    void set_phone_number(const std::string&);
    void set_darksecret(const std::string&);

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_number_phone() const;
    std::string get_darksecret() const;
};
```
- **Privado (`private`)**: datos internos que **no deben ser accesibles** ni modificables directamente desde fuera. Mantiene **invariantes** (p. ej., que el contacto no tenga campos vacíos al guardarse).
- **Público (`public`)**: la **interfaz** que el resto del programa puede usar: constructores, destructores y **métodos** (getters/setters).

### `Phonebook`
```cpp
#define MAX_CONTACTS 8

class Phonebook {
private:
    Contact _phonebook[MAX_CONTACTS]; // almacenamiento fijo (sin new/delete)

public:
    Phonebook();               // constructor
    ~Phonebook();              // destructor (vacío; ver sección 5)
    int add_contact(std::string input);    // añade (sobrescribe el más viejo)
    int search_contact(std::string input); // lista y muestra detalle
};
```
- La **lista de contactos** es **privada**: no se expone directamente.
- El uso externo se realiza mediante **métodos públicos** controlados (`add_contact`, `search_contact`).

> **Conclusión**: *todo lo que solo use internamente la clase debe ser `private`; lo que deban usar otros módulos (o `main`) debe ser `public`.*

---

## 5) Constructores y **destructores** (¿dónde se usan?)

### Constructor
- `Contact::Contact()` y `Phonebook::Phonebook()` inicializan objetos.
- Se ejecutan **automáticamente** al **crear** un objeto:
  - `Phonebook pb;` en `main.cpp` llama a `Phonebook::Phonebook()`.
  - `Contact newcontact;` dentro de `add_contact()` llama a `Contact::Contact()`.

### Destructor (¿cuándo se ejecuta?)
- `Contact::~Contact()` y `Phonebook::~Phonebook()` están **definidos (vacíos)**. Aunque no hagas nada dentro, su **llamada sí ocurre** automáticamente en los siguientes casos:
  1. **Fin de vida de un objeto automático (stack)**:  
     - Al salir de `add_contact()`, el **`Contact newcontact` local** se **destruye** (llama a `~Contact()`).
     - Al terminar `main()`, el **`Phonebook pb`** se **destruye** (llama a `~Phonebook()`).
  2. **Destrucción de miembros**:  
     - Cuando se destruye un `Contact`, **sus miembros `std::string`** también destruyen su memoria interna (RAII).
     - Cuando se destruye `Phonebook`, **se destruye su array** `_phonebook[]`; es decir, se invoca el destructor de cada `Contact` almacenado.
  3. **Temporales** y objetos intermedios:  
     - Cualquier objeto temporal creado durante asignaciones/copies se destruye al final de la expresión o del bloque.

> **Importante**: no usamos memoria dinámica manual; por tanto, los destructores están **vacíos**. Aun así, **se usan** para liberar recursos de sus **miembros** (como `std::string`) de forma automática.  
> Esto es **RAII**: *la vida del objeto gestiona la vida de sus recursos*.

---

## 6) Formato y límites del PhoneBook

- **Capacidad**: máximo **8** contactos. El 9º **sobrescribe el más antiguo** (índice circular).
- **Tabla `SEARCH`**:
  - Ancho **10** por columna, alineado a la derecha.
  - Si el texto **>10**, se trunca a **9** y se añade `.` (ej. `Supercal.`).
- **Campos vacíos**: no se admiten al crear el contacto.
- **Teléfono**: se guarda como `std::string`; **no se valida el formato** (puedes guardar `+89620371038`, `1234`, etc.).

---

## 7) Ejemplo de sesión completa

```text
$ ./phonebook
Wellcome to the Phonebook
---------------------------
         USAGE
ADD (add a new contact)
SEARCH (search a contact)
EXIT (exit program)
---------------------------
type here > ADD
Enter your first name
VanVan
Enter your last name
Lana
Enter your nickname
Van
Enter your phonenumber
+890000000
Enter your darkest secret
Valgrind
contact has been added successfully

type here > SEARCH
|   Index  |First Name| Last Name| Nickname |
---------------------------------------------
|         0|   VanVan|      Lana|        Van|
---------------------------------------------
Enter the index of the contact to display: 0
First Name: VanVan
Last  Name: Lana
Nickname: Van
Phone Number: +8900000000
Darkest Secret: Valgrind

type here > EXIT
program finished
```

---

## 8) Errores comunes

- **`-Werror -Wunused-parameter`**: si un parámetro no se usa, siléncialo con `(void)param;`.
- **Makefile**: recetas con **TAB**; en 42 se usa `-std=c++98`.
- **UTF-8/acentos**: ñ,Ñ y acentos varios. La truncación cuenta **bytes**, no grafemas (dos o más bytes); para el proyecto, es suficiente.

---

## 9) Resumen rápido (TL;DR)

- **Encapsulación**: datos `private`, interfaz `public`.
- **RAII**: los destructores **se usan automáticamente** al salir de ámbito; liberan recursos de los miembros.
- **Sin `new/delete`**: array fijo de 8 `Contact` en `Phonebook`.
- **Comandos**: `ADD`, `SEARCH`, `EXIT`.
- **Compilar**: `make` → `./phonebook`.