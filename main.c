#include <stdio.h>
#include <stdlib.h>
#include "canciones.h"

int main() {
    int opcion;

    inicializarMapa();

    do {
        printf("=====================================\n");
        printf("        Spotifind - Canciones        \n");
        printf("=====================================\n");
        printf("1) Cargar Canciones\n");
        printf("2) Buscar por ID\n");
        printf("3) Buscar por Artista\n");
        printf("4) Buscar por Genero\n");
        printf("5) Buscar por Tempo (lento, moderado, rapido)\n");
        printf("6) Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: cargarCanciones("canciones.csv"); break;
            case 2: buscarPorID(); break;
            case 3: buscarPorArtista(); break;
            case 4: buscarPorGenero(); break;
            case 5: buscarPorTempo(); break;
            case 6: printf("Saliendo del menu...\n"); break;
            default: printf("Opcion invalida\n"); break;
        }
    } while(opcion != 6);

    return 0;
}
