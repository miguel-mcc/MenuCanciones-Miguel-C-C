# Spotifind - Sistema de Busqueda de Canciones

## Descripcion
Spotifind es un programa en C que permite cargar y buscar canciones desde un archivo CSV. El sistema utiliza un **TreeMap** para almacenar las canciones de manera ordenada y eficiente segun el ID de cada cancion.

Las canciones contienen los siguientes datos:
- ID
- Artista
- Album
- Titulo
- Tempo
- Genero

## Opciones del Programa
Al ejecutar el programa, se muestra el siguiente menu:

1) Cargar Canciones  
2) Buscar por ID  
3) Buscar por Artista  
4) Buscar por Genero  
5) Buscar por Tempo (lento, moderado, rapido)  
6) Salir  

### Notas sobre las opciones
- **Cargar Canciones:** Lee el archivo `canciones.csv` y almacena o almacena cada cancion en el TreeMap.
- **Buscar por ID:** Permite ingresar un ID y muestra la cancion correspondiente.
- **Buscar por Artista:** Permite ingresar un nombre de artista y muestra todas sus canciones.
- **Buscar por Genero:** Permite ingresar un genero y muestra todas las canciones de ese genero.
- **Buscar por Tempo:** Permite ingresar `lento`, `moderado` o `rapido` y muestra las canciones de esa categoria.
- **Salir:** Cierra el programa.

**Opciones que no funcionan correctamente:** ninguna, todas las funciones implementadas muestran los resultados esperados.

## Ejecucion del Programa
Para compilar y ejecutar el programa en un entorno con GCC, se deben ejecutar los siguientes comandos en la terminal:

```bash
gcc main.c canciones.c treemap.c -o spotifind
./spotifind

## Ejemplo de uso

=====================================
        Spotifind - Canciones
=====================================
1) Cargar Canciones
2) Buscar por ID
3) Buscar por Artista
4) Buscar por Genero
5) Buscar por Tempo (lentas, moderadas, rapidas)
6) Salir
Ingrese su opcion: 1
Canciones cargadas exitosamente.

Ingrese su opcion: 2
Ingrese ID: 0
ID: 0 | Artista: Gen Hoshino | Album: Comedy | Titulo: Comedy | Tempo: 73.0 | Genero: acoustic

Ingrese su opcion: 3
Ingrese el nombre del artista: Gen Hoshino
ID: 0 | Artista: Gen Hoshino | Album: Comedy | Titulo: Comedy | Tempo: 73.0 | Genero: acoustic

Ingrese su opcion: 4
Ingrese el genero: acoustic
ID: 0 | Artista: Gen Hoshino | Album: Comedy | Titulo: Comedy | Tempo: 73.0 | Genero: acoustic

Ingrese su opcion: 5
Ingrese la categoria de tempo (lentas, moderadas, rapidas): lentas (1)
ID: 0 | Artista: Gen Hoshino | Album: Comedy | Titulo: Comedy | Tempo: 73.0 | Genero: acoustic
