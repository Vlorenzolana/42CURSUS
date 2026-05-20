================================================================================
                    CPP06 - GUIA PASO A PASO (estilo 42)
                    C++ Casts: static, reinterpret, dynamic
================================================================================

    El modulo 06 trata sobre los CASTS de C++. En C hacias (int)variable y ya.
    En C++ hay 4 tipos de cast, cada uno con un proposito claro:

    - static_cast<T>()      -> conversiones "normales" entre tipos compatibles
    - reinterpret_cast<T>() -> reinterpretar bits crudos (puntero <-> entero)
    - dynamic_cast<T>()     -> cast seguro en jerarquias polimorficas (runtime)
    - const_cast<T>()       -> quitar/poner const (no se usa en este modulo)

    Cada ejercicio te obliga a usar uno diferente. Vamos de menor a mayor.

================================================================================
================================================================================


================================================================================
  EXERCISE 00 - ScalarConverter (static_cast)
================================================================================

  CONCEPTO CENTRAL:
    Recibes un string ("42", "4.2f", "nan", "a"...) y lo conviertes a los
    4 tipos escalares: char, int, float, double. Usas static_cast para las
    conversiones explicitas entre tipos numericos.

  Que es static_cast?
    Es el cast "educado" de C++. Lo usas cuando los tipos son compatibles:
      double d = 4.2;
      int i = static_cast<int>(d);    // trunca a 4
      char c = static_cast<char>(65); // 'A'
    El compilador verifica en COMPILACION que la conversion es valida.

  ---------------------------------------------------------------------------
  |  PASO 1: ScalarConverter.hpp - La clase no-instanciable                 |
  ---------------------------------------------------------------------------

    La clase NO almacena nada, solo tiene un metodo estatico. Para que nadie
    pueda crear un objeto, metes TODOS los constructores en private:

      class ScalarConverter
      {
        private:
          ScalarConverter();                                  // Constructor
          ScalarConverter(ScalarConverter const &original);   // Copia
          ~ScalarConverter();                                 // Destructor
          ScalarConverter& operator=(ScalarConverter const &other);  // Asign.

        public:
          static void convert(const std::string &literal);   // EL unico metodo
      };

    Por que static? Porque se llama SIN objeto:
      ScalarConverter::convert("42");  // <- asi, directamente con la clase
      // ScalarConverter obj;          // <- ESTO NO COMPILA (constructor private)

    Headers que necesitas: <iostream>, <limits>, <cstdlib>

    NOTA: En tu .hpp actual tienes:
      ScalarConverter& operator=(ScalarConverter const &other) const;
                                                              ^^^^^
    Ese "const" al final del operator= es un error. El operator= modifica
    el objeto, no puede ser const. Quitalo:
      ScalarConverter& operator=(ScalarConverter const &other);

  ---------------------------------------------------------------------------
  |  PASO 2: Entender los tipos de literal que puedes recibir              |
  ---------------------------------------------------------------------------

    El string que recibes puede ser una de estas 5 cosas:

    TIPO          EJEMPLOS              COMO DETECTARLO
    ---------     ----------------      -----------------------------------
    pseudo-lit    nan, +inf, -inff...   Comparar con strings conocidos
    char          a, *, Z               length==1 && !isdigit
    int           0, -42, 42            solo digitos (con posible signo)
    float         4.2f, 0.0f            tiene punto Y termina en 'f'
    double        4.2, 0.0              tiene punto, NO termina en 'f'

    ORDEN DE DETECCION (importa):
      1. Es un pseudo-literal? (nan, nanf, inf, inff, +inf, +inff, -inf, -inff)
      2. Es un char? (un solo caracter no-digito)
      3. Es un int? (solo digitos, posible signo al inicio)
      4. Es un float? (tiene '.', termina en 'f')
      5. Es un double? (tiene '.', no termina en 'f')
      6. Si no es nada -> input invalido

  ---------------------------------------------------------------------------
  |  PASO 3: ScalarConverter.cpp - La funcion convert paso a paso          |
  ---------------------------------------------------------------------------

    La logica dentro de convert() sigue este flujo:

    -- 3a. Pseudo-literales --------------------------------------------------

      if (literal == "nan" || literal == "nanf")
        -> char: impossible
        -> int:  impossible
        -> float:  nanf
        -> double: nan

      if (literal == "inf"/"+inf"/"inff"/"+inff" y sus negativos)
        -> char: impossible
        -> int:  impossible
        -> float:  inff / -inff
        -> double: inf / -inf

      Estos son valores especiales de IEEE 754 (el estandar de punto flotante).
      No tienen representacion como char ni como int -> "impossible".
      Usas std::numeric_limits<float>::quiet_NaN() y ::infinity().

    -- 3b. Char literal -------------------------------------------------------

      if (literal.length() == 1 && !isdigit(literal[0]))
      {
          char c = literal[0];
          // Convierte CON static_cast a los otros 3 tipos:
          static_cast<int>(c)       -> valor ASCII
          static_cast<float>(c)     -> valor ASCII como float
          static_cast<double>(c)    -> valor ASCII como double
      }

      Ejemplo: input "a"
        char:   'a'
        int:    97
        float:  97.0f
        double: 97.0

    -- 3c. Conversion numerica (int / float / double) -------------------------

      Para int, float y double, primero conviertes el string a su valor real.
      Puedes usar atof(), strtod(), o std::stod() (c++11).

      Con atof (C++98 compatible):
        double value = atof(literal.c_str());

      Luego conviertes ESE valor a los otros tipos con static_cast:

      -> CHAR:
        if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
            "impossible"
        else if (!isprint(static_cast<int>(value)))
            "Non displayable"
        else
            static_cast<char>(value)

      -> INT:
        if (value > INT_MAX || value < INT_MIN || isnan(value) || isinf(value))
            "impossible"
        else
            static_cast<int>(value)

      -> FLOAT:
        static_cast<float>(value)
        (siempre imprime con ".0f" si no tiene decimales)

      -> DOUBLE:
        value directamente (ya es double)
        (siempre imprime con ".0" si no tiene decimales)

    -- 3d. El truco del ".0" / ".0f" ------------------------------------------

      El subject exige imprimir "0.0f" y no "0f". Para forzar el punto decimal:

        if (value == static_cast<int>(value))
            std::cout << value << ".0f"     // para float
            std::cout << value << ".0"      // para double
        else
            std::cout << value << "f"       // float con decimales normales
            std::cout << value              // double con decimales normales

      CUIDADO: esta comparacion falla con nan/inf (porque nan != nan).
      Por eso los pseudo-literales se manejan ANTES, aparte.

  ---------------------------------------------------------------------------
  |  PASO 4: main.cpp - Validacion de input                                |
  ---------------------------------------------------------------------------

    El main recibe argv[1] y hace 3 cosas:

      1. Verificar argc == 2
      2. Comprobar si es pseudo-literal (nan, inf, etc.) -> manejar y salir
      3. Validar que el string tiene formato numerico valido -> si no, error
      4. Llamar a ScalarConverter::convert(literal)

    Tu funcion evaluate_shitty_input() valida correctamente:
      - Un solo char no-digito -> OK
      - Solo digitos con maximo un punto y signo al inicio -> OK
      - Todo lo demas -> ERROR

    PROBLEMA EN TU CODIGO ACTUAL: No aceptas floats (ej: "4.2f") porque
    evaluate_shitty_input() rechaza la 'f' final. Necesitas anadir:

      else if (literal[i] == 'f' && i == literal.length() - 1 && has_dot)
          continue;    // La 'f' final de un float literal es valida

  ---------------------------------------------------------------------------
  |  PASO 5: Tests esperados                                               |
  ---------------------------------------------------------------------------

      ./convert 0        -> char: Non displayable | int: 0 | float: 0.0f | double: 0.0
      ./convert nan      -> char: impossible | int: impossible | float: nanf | double: nan
      ./convert 42.0f    -> char: '*' | int: 42 | float: 42.0f | double: 42.0
      ./convert -42      -> char: impossible | int: -42 | float: -42.0f | double: -42.0
      ./convert a        -> char: 'a' | int: 97 | float: 97.0f | double: 97.0
      ./convert 2147483648 -> char: impossible | int: impossible | float: ... | double: ...

  ---------------------------------------------------------------------------
  |  RESUMEN EX00: Que deberias entender                                   |
  ---------------------------------------------------------------------------

    [x] static_cast<T>() convierte entre tipos escalares compatibles
    [x] Una clase con todo en private = no instanciable
    [x] Un metodo static se llama con Clase::metodo() sin crear objeto
    [x] std::numeric_limits te da los limites de cada tipo + nan/inf
    [x] Detectar el tipo del literal ANTES de convertir
    [x] Manejar overflows y valores imposibles con mensajes claros


================================================================================
================================================================================


================================================================================
  EXERCISE 01 - Serializer (reinterpret_cast)
================================================================================

  CONCEPTO CENTRAL:
    Convertir un puntero a un numero entero y viceversa. La direccion de
    memoria ES un numero. reinterpret_cast te deja tratarlo como tal.

  Que es reinterpret_cast?
    El cast mas "bruto" de C++. Reinterpreta los BITS de un tipo como si
    fueran otro tipo completamente distinto. No transforma el valor, solo
    cambia como el compilador lo interpreta.

      int *ptr = &x;
      uintptr_t num = reinterpret_cast<uintptr_t>(ptr);  // puntero -> entero
      int *ptr2 = reinterpret_cast<int*>(num);            // entero -> puntero
      // ptr == ptr2 (misma direccion, mismos bits)

  Que es uintptr_t?
    Un entero sin signo GARANTIZADO de ser lo bastante grande para almacenar
    cualquier direccion de memoria. En un sistema de 64 bits = 8 bytes.
    Se define en <stdint.h> (C) o <cstdint> (C++).

  ---------------------------------------------------------------------------
  |  PASO 1: Data.hpp - Una estructura con datos                           |
  ---------------------------------------------------------------------------

    El subject dice "non-empty Data structure". Cualquier struct con miembros
    vale. Tu implementacion es correcta:

      typedef struct s_Data
      {
          std::string  first_name;
          std::string  last_name;
          int          age;
          float        money;
          bool         has_job;
      } Data;

    Nota 42: el typedef es estilo C. En C++ puedes poner directamente:
      struct Data { ... };
    Ambos son validos, pero el typedef es mas "clasico" y lo aceptan.

  ---------------------------------------------------------------------------
  |  PASO 2: Serializer.hpp - Otra clase no-instanciable                   |
  ---------------------------------------------------------------------------

    Misma receta que ex00: constructores en private, metodos static.

      class Serializer
      {
        private:
          Serializer();
          Serializer(const Serializer &original);
          ~Serializer();
          Serializer& operator=(const Serializer &other);  // SIN const final

        public:
          static uintptr_t serialize(Data* ptr);
          static Data*     deserialize(uintptr_t raw);
      };

    NOTA: mismo error que en ex00, tu operator= tiene "const" al final.
    Quitalo tambien aqui.

  ---------------------------------------------------------------------------
  |  PASO 3: Serializer.cpp - Dos lineas de codigo                        |
  ---------------------------------------------------------------------------

    Es el ejercicio mas corto del modulo:

      uintptr_t Serializer::serialize(Data* ptr)
      {
          return reinterpret_cast<uintptr_t>(ptr);
      }

      Data* Serializer::deserialize(uintptr_t raw)
      {
          return reinterpret_cast<Data*>(raw);
      }

    Que pasa aqui?
      ptr                 = 0x7ffd5a3b4c80  (direccion de memoria)
      serialize(ptr)      = 140726194142336  (esos mismos bits como numero)
      deserialize(num)    = 0x7ffd5a3b4c80  (de vuelta a puntero)

    Los BITS no cambian nunca. Solo cambia como los interpreta el compilador.

  ---------------------------------------------------------------------------
  |  PASO 4: main.cpp - Demostrar que funciona                            |
  ---------------------------------------------------------------------------

    El test debe demostrar que:
      serialize() -> deserialize() -> puntero original

    Tu main ya lo hace bien:
      1. Crea un Data con valores
      2. Serializa la direccion a uintptr_t
      3. Deserializa de vuelta a Data*
      4. Comprueba que el puntero recuperado == puntero original
      5. Accede a los datos a traves del puntero recuperado -> siguen ahi

    MEJORA: Podrias anadir una comparacion explicita:
      if (recovered_ptr == &card)
          std::cout << "Punteros iguales: OK" << std::endl;

  ---------------------------------------------------------------------------
  |  RESUMEN EX01: Que deberias entender                                   |
  ---------------------------------------------------------------------------

    [x] reinterpret_cast reinterpreta bits, no transforma valores
    [x] Un puntero y un entero pueden contener la misma informacion (direccion)
    [x] uintptr_t es el tipo entero perfecto para almacenar direcciones
    [x] serialize/deserialize son operaciones inversas y simetricas
    [x] Los datos NO se copian, solo se reinterpreta la direccion


================================================================================
================================================================================


================================================================================
  EXERCISE 02 - Identify real type (dynamic_cast)
================================================================================

  CONCEPTO CENTRAL:
    Tienes un puntero Base* que apunta a un A, B o C. Como saber cual es
    SIN usar typeid? Con dynamic_cast, que verifica el tipo REAL en runtime.

  Que es dynamic_cast?
    El cast "inteligente". Funciona SOLO con clases polimorficas (que tienen
    al menos un metodo virtual). Verifica en TIEMPO DE EJECUCION si el
    objeto realmente es del tipo al que intentas castear.

      Base *ptr = new A();
      A *a = dynamic_cast<A*>(ptr);  // a != NULL -> ES un A
      B *b = dynamic_cast<B*>(ptr);  // b == NULL -> NO es un B

    Con referencias:
      Base &ref = *ptr;
      A &a = dynamic_cast<A&>(ref);  // OK si es A
      B &b = dynamic_cast<B&>(ref);  // LANZA std::bad_cast si no es B

    REGLA CLAVE:
      - Con PUNTEROS: falla -> devuelve NULL
      - Con REFERENCIAS: falla -> lanza excepcion std::bad_cast

  Por que necesita virtual?
    dynamic_cast necesita la vtable (tabla de funciones virtuales) para
    saber el tipo real del objeto en runtime. Sin al menos un metodo virtual,
    no hay vtable -> no compila.
    Por eso Base tiene: virtual ~Base();

  ---------------------------------------------------------------------------
  |  PASO 1: Base.hpp / Base.cpp - La clase base polimorfica              |
  ---------------------------------------------------------------------------

    Lo minimo posible. Solo un destructor virtual:

      class Base
      {
        public:
          virtual ~Base();   // <- hace la clase POLIMORFICA
      };

      Base::~Base() {}

    Por que virtual el destructor? Dos razones:
      1. Necesitas polimorfismo para que dynamic_cast funcione
      2. Si haces "delete base_ptr" y apunta a un A, necesitas que se
         llame al destructor de A, no solo al de Base

  ---------------------------------------------------------------------------
  |  PASO 2: A.hpp, B.hpp, C.hpp - Clases hijas vacias                    |
  ---------------------------------------------------------------------------

    Tres clases que heredan de Base. No necesitan nada dentro:

      class A : public Base {};
      class B : public Base {};
      class C : public Base {};

    El subject dice que NO necesitan Orthodox Canonical Form
    (no hacen falta constructor copia, operator=, etc.).

    Tu implementacion tiene constructor y destructor definidos.
    No es incorrecto, pero tampoco es necesario. El subject permite
    dejarlo vacio.

  ---------------------------------------------------------------------------
  |  PASO 3: generate() - Creacion aleatoria                              |
  ---------------------------------------------------------------------------

      Base* generate(void)
      {
          int r = rand() % 3;

          if (r == 0) return new A();
          if (r == 1) return new B();
          return new C();
      }

    Devuelve un Base* -> el TIPO REAL se pierde en el puntero.
    Solo dynamic_cast puede recuperarlo.

    Tu codigo usa switch, que es igual de valido.

    NOTA: srand() debe llamarse UNA sola vez al inicio de main().
    Si lo llamas dentro de generate(), al ejecutarse varias veces seguidas
    en el mismo segundo, rand() dara el mismo numero siempre.
    Tu lo tienes en main() -> correcto.

  ---------------------------------------------------------------------------
  |  PASO 4: identify(Base* p) - Identificar por puntero                  |
  ---------------------------------------------------------------------------

    Con punteros, dynamic_cast devuelve NULL si falla:

      void identify(Base* p)
      {
          if (dynamic_cast<A*>(p))
              std::cout << "A" << std::endl;
          else if (dynamic_cast<B*>(p))
              std::cout << "B" << std::endl;
          else if (dynamic_cast<C*>(p))
              std::cout << "C" << std::endl;
      }

    Internamente:
      1. El compilador mira la vtable del objeto apuntado por p
      2. Compara con la vtable de A -> coincide? -> devuelve puntero valido
      3. Si no coincide -> devuelve NULL -> prueba con B, luego C

  ---------------------------------------------------------------------------
  |  PASO 5: identify(Base& p) - Identificar por referencia               |
  ---------------------------------------------------------------------------

    Con referencias NO puedes comparar con NULL (una referencia nunca es NULL).
    Si el cast falla, LANZA una excepcion std::bad_cast -> usas try/catch:

      void identify(Base& p)
      {
          try {
              (void)dynamic_cast<A&>(p);
              std::cout << "A" << std::endl;
              return;
          } catch (...) {}

          try {
              (void)dynamic_cast<B&>(p);
              std::cout << "B" << std::endl;
              return;
          } catch (...) {}

          try {
              (void)dynamic_cast<C&>(p);
              std::cout << "C" << std::endl;
          } catch (...) {
              std::cout << "Unknown" << std::endl;
          }
      }

    PROHIBIDO usar punteros dentro de esta funcion (el subject lo dice).
    El (void) silencia el warning de variable no usada.

    Tu codigo usa std::exception& en el catch, que es igual de correcto.

  ---------------------------------------------------------------------------
  |  PASO 6: main.cpp - Test                                              |
  ---------------------------------------------------------------------------

    Tu main genera 5 objetos aleatorios, los identifica por puntero y por
    referencia, y luego los borra. Esta bien.

    PROBLEMA: al final haces:
      Base *wtest = 0;
      identify(wtest);      // OK -> imprime "NULL"
      identify(*wtest);     // SEGFAULT cp /sgoinfre/students/vlorenzo/42CURSUS/CPP/cpp06/readme.mc /sgoinfre/students/vlorenzo/42CURSUS/CPP/cpp06/readme.mc.bak Desreferenciar NULL = crash

    Desreferenciar un puntero NULL es comportamiento indefinido. Quita esa
    linea o ponla dentro de un check:
      if (wtest)
          identify(*wtest);

  ---------------------------------------------------------------------------
  |  RESUMEN EX02: Que deberias entender                                   |
  ---------------------------------------------------------------------------

    [x] dynamic_cast verifica tipos en RUNTIME (no en compilacion)
    [x] Necesita polimorfismo (al menos un metodo virtual en la base)
    [x] Con punteros: falla -> NULL. Con referencias: falla -> excepcion
    [x] Sirve para "descubrir" el tipo real detras de un puntero base
    [x] Es el cast MAS seguro de C++ (tiene comprobacion en runtime)
    [x] PROHIBIDO usar typeinfo - dynamic_cast es la alternativa


================================================================================
================================================================================


================================================================================
  RESUMEN GLOBAL - Los 3 casts del modulo 06
================================================================================

  | CAST              | USO                                                  |
  |-------------------|------------------------------------------------------|
  | static_cast       | Conversiones entre tipos compatibles (int<->double,  |
  |   (ex00)          | char<->int). Verificado en COMPILACION.              |
  |-------------------|------------------------------------------------------|
  | reinterpret_cast  | Reinterpretar bits puros (puntero<->entero).         |
  |   (ex01)          | SIN verificacion. El mas peligroso.                  |
  |-------------------|------------------------------------------------------|
  | dynamic_cast      | Downcast seguro en herencia polimorfica.             |
  |   (ex02)          | Verificado en RUNTIME. Necesita virtual.             |
  |-------------------|------------------------------------------------------|

  Los 3 ejercicios comparten un patron: clase no-instanciable con metodos
  static (ex00 y ex01) o funciones libres que operan sobre polimorfismo
  (ex02). Cada uno te ensena un cast diferente.

================================================================================


================================================================================
  ERRORES A CORREGIR EN TU CODIGO ACTUAL
================================================================================

  1. ex00/ScalarConverter.hpp linea 28:
     operator=(ScalarConverter const &other) const;  <- QUITAR ese const final

  2. ex01/Serializer.hpp linea 28:
     operator=(const Serializer &other) const;  <- QUITAR ese const final

  3. ex00/main.cpp -> evaluate_shitty_input():
     No acepta floats ("4.2f") porque la 'f' es rechazada.
     Anadir excepcion para 'f' final cuando hay punto decimal.

  4. ex00/ScalarConverter.cpp -> convert():
     No maneja nan/inf (llama a atof que devuelve nan/inf y luego intenta
     comparar con int, lo cual es UB). Los pseudo-literales deben cortarse
     ANTES de llegar a convert(), o manejarse dentro de convert() al inicio.

  5. ex02/main.cpp linea final:
     identify(*wtest) con wtest=NULL -> SEGFAULT. Eliminar o proteger.

================================================================================
