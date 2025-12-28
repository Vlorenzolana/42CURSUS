# CPP02

Ejercicios de C++: manejo de clases, operadores, constructores, copias y funciones miembro.

Este README está basado en el formato de `CPP01` y describe los ejercicios contenidos en esta carpeta (`ex00`..`ex03`).

## Cómo compilar
Cada ejercicio tiene su propio `Makefile`. Para compilar ejecuta en la carpeta del ejercicio:

```bash
make -C ex00
make -C ex01
make -C ex02
make -C ex03
```

Flags recomendadas (ya usadas en los Makefiles incluidos):
- Compilador: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98`

Para limpiar (eliminar objetos y binarios) usa:

```bash
make -C ex00 fclean
make -C ex01 fclean
make -C ex02 fclean
make -C ex03 fclean
```

## Ex00
- Archivos principales: `main.cpp`, `Fixed.cpp`, `Fixed.hpp`.
- Objetivo: implementar una clase `Fixed` con constructor por defecto, constructor de copia, operador de asignación, destructor y métodos básicos (`getRawBits`, `setRawBits`).
- Ejecutable: `./fixed` (generado en la carpeta del ejercicio).
- Comportamiento observado (ejemplo): llamadas a constructores/destructores y `getRawBits`/`setRawBits`.

## Ex01
- Archivos principales: `main.cpp`, `Fixed.cpp`, `Fixed.hpp`.
- Objetivo: añadir constructores que permitan crear `Fixed` desde `int` y `float`, manejo correcto de conversiones y `toInt()` / `toFloat()`.
- Ejecutable: `./fixed`.
- Comportamiento observado (ejemplo): impresión de valores en float/int y uso correcto de constructores y operadores.

## Ex02
- Archivos principales: `main.cpp`, `Fixed.cpp`, `Fixed.hpp`.
- Objetivo: implementar operadores aritméticos (+, -, *, /), operadores de comparación, operadores de incremento/decremento (pre y post) y funciones `min`/`max` estáticas.
- Ejecutable: `./fixed`.
- Comportamiento observado (ejemplo): operaciones aritméticas, comparaciones y comportamiento de pre/post-incremento.

## Ex03
- Archivos principales: `main.cpp`, `Fixed.cpp`, `Fixed.hpp`, `Point.cpp`, `Point.hpp`.
- Objetivo: añadir la clase `Point` y el programa `bsp` que determina si un punto está dentro de un triángulo (función `bsp`).
- Ejecutable: `./bsp`.
- Comportamiento observado (ejemplo): salida como `Point (3,3) is INSIDE the triangle a-b-c`.

## Notas sobre el autor / headers
Los archivos de cabecera (comentarios de cabecera al inicio de cada fichero) contienen la línea de autor con el nombre:

```
/*   By: vlorenzo <vlorenzo@student.42.fr> */
```

He verificado que `vlorenzo` aparece en los archivos relevantes de `ex00`..`ex03`.

## Calidad y pruebas opcionales
- Puedes ejecutar `valgrind --leak-check=full ./fixed` (o el ejecutable correspondiente) para comprobar que no hay fugas de memoria.
- Si quieres comprobar estilo, ejecuta tu linter/`norminette` local (si aplica en tu entorno).

## Uso de IA y buenas prácticas
Este repositorio se desarrolló con asistencia (revisión/sugerencias) por herramientas de IA. Buenas prácticas seguidas:
- Revisar manualmente todas las sugerencias de IA antes de aplicarlas.
- Probar los binarios generados y verificar la ausencia de fugas de memoria cuando aplica.
- Mantener el código compatible con `-std=c++98` tal como exige la materia.

## Próximos pasos sugeridos
- Añadir pruebas automáticas simples (scripts) que compilen y ejecuten los binarios para asegurar regresiones mínimas.
- Ejecutar `valgrind` sobre cada ejecutable y adjuntar un reporte en `docs/` si se desea evidencia de ausencia de leaks.

---

Si quieres que ajuste el contenido (más detalles por ejercicio, ejemplos de entrada/salida completos, o traducción a inglés), dímelo y lo actualizo.
