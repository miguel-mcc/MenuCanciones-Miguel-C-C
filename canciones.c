#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canciones.h"
#include "treemap.h"

typedef struct {
    int id;
    char artista[100];
    char album[100];
    char titulo[100];
    float tempo;
    char genero[50];
} Cancion;

TreeMap* mapaCanciones = NULL;

void inicializarMapa() {
    mapaCanciones = createTreeMap(lower_than_int);
}

void imprimirCancion(Cancion* c) {
    printf("ID: %d | Artista: %s | Album: %s | Titulo: %s | Tempo: %.1f | Genero: %s\n",
           c->id, c->artista, c->album, c->titulo, c->tempo, c->genero);
}

void cargarCanciones(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("Error al abrir el archivo %s\n", nombreArchivo);
        return;
    }

    char linea[2048];
    fgets(linea, sizeof(linea), archivo);

    while (fgets(linea, sizeof(linea), archivo)) {
        Cancion* c = malloc(sizeof(Cancion));
        if (!c) continue;

        char* token = strtok(linea, ",");
        int col = 0;

        while (token) {
            switch(col) {
                case 0: 
                    c->id = atoi(token); 
                    break;
                case 2: 
                    strncpy(c->artista, token, sizeof(c->artista)-1); 
                    c->artista[sizeof(c->artista)-1]='\0'; 
                    break;
                case 3: 
                    strncpy(c->album, token, sizeof(c->album)-1); 
                    c->album[sizeof(c->album)-1]='\0'; 
                    break;
                case 4: 
                    strncpy(c->titulo, token, sizeof(c->titulo)-1); 
                    c->titulo[sizeof(c->titulo)-1]='\0'; 
                    break;
                case 18: 
                    
                    c->tempo = atof(token); 
                    break;
                case 20: 
                    strncpy(c->genero, token, sizeof(c->genero)-1); 
                    c->genero[sizeof(c->genero)-1]='\0'; 
                    c->genero[strcspn(c->genero, "\r\n")] = 0;
                    break;
            }
            token = strtok(NULL, ",");
            col++;
        }

        int* idClave = malloc(sizeof(int));
        *idClave = c->id;
        insertTreeMap(mapaCanciones, idClave, c);
    }

    fclose(archivo);
    printf("Canciones cargadas exitosamente.\n");
}

void buscarPorID() {
    int id;
    printf("Ingrese ID: ");
    scanf("%d", &id);
    getchar();

    Cancion* c = searchTreeMap(mapaCanciones, &id);
    if (c) imprimirCancion(c);
    else printf("No se encontro cancion con ID %d\n", id);
}

void buscarPorArtista() {
    char artista[100];
    printf("Ingrese el nombre del artista: ");
    fgets(artista, sizeof(artista), stdin);
    artista[strcspn(artista, "\n")] = 0;

    for (Cancion* c = firstTreeMap(mapaCanciones); c != NULL; c = nextTreeMap(mapaCanciones)) {
        if (strcasecmp(c->artista, artista) == 0) imprimirCancion(c);
    }
}

void buscarPorGenero() {
    char genero[50];
    printf("Ingrese el genero de la cancion: ");
    fgets(genero, sizeof(genero), stdin);
    genero[strcspn(genero, "\n")] = 0;

    for (Cancion* c = firstTreeMap(mapaCanciones); c != NULL; c = nextTreeMap(mapaCanciones)) {
        if (strcasecmp(c->genero, genero) == 0) imprimirCancion(c);
    }
}

void buscarPorTempo() {
    int opcion;
    printf("Seleccione categoria:\n1. Lentas presione (1) (<80)\n2. Moderadas presione (2) (80-120)\n3. Rapidas presione (3) (>120)\nOpcion: ");
    scanf("%d", &opcion);
    getchar();

    for (Cancion* c = firstTreeMap(mapaCanciones); c != NULL; c = nextTreeMap(mapaCanciones)) {
        if ((opcion == 1 && c->tempo < 80) ||
            (opcion == 2 && c->tempo >= 80 && c->tempo <= 120) ||
            (opcion == 3 && c->tempo > 120))
            imprimirCancion(c);
    }
}