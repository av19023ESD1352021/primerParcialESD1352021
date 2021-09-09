#include <string.h>
#include "prueba.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int * retornarAlgo(char *archivo) {
    FILE *flujo; 
        flujo = fopen(archivo, "r");
    if (flujo == NULL) {
        printf("Error en la apertura del archivo");
        
    }   
    int columnasF = 6;
    int filasF = 59;
    int *matriz = (int *) malloc(columnasF * filasF * sizeof (int));
    char valor[100];
    char *valorOb;
    char *test;
    int fila = 0;
    char ignore;
    
   
    
   
    rewind(flujo);
    
    do {
       
        while (ignore != '\n') {
            ignore = fgetc(flujo);
        }
        int contador = 0;
        fgets(valor, 100, flujo);
        test = valor;

        strtok(test, ",");
        while (contador < columnasF) {
            valorOb = strtok(NULL, ",");
           *(matriz + fila * columnasF + contador) = atoi(valorOb);
            contador++;
            
        }
        fila++;
            
    } while (feof(flujo) == 0);
    
    fclose(flujo);

    return matriz;



}

int * transpuestaM(int *array, int filas, int columnas) {
    int i;
    int j;
    int *transpuesta= (int *) malloc(columnas * filas * sizeof (int));
    for (i = 0; i < filas; i++) {

        for (j = 0; j < columnas; j++) {
            *(transpuesta + j * filas + i) = *(array + i * columnas + j);
            
        }
    }
   

    return transpuesta;
}

int *multiplicacionM(int *primerA, int fila_uno, int columnauno, int *arreglo, int filasdos, int columnados) {

    if (columnauno == filasdos) {
        int aux;
        int *resp = (int*) malloc(fila_uno * columnados * sizeof (int));
        for (int i = 0; i < fila_uno; i++) {
            for (int j = 0; j < columnados; j++) {
                aux = 0;
                for (int x = 0; x < columnauno; x++) {
                    aux += (*(primerA + i * columnauno + x)) * (*(arreglo + x * columnados + j));
                }
                *(resp + i * columnados + j) = aux;
            }
        }
        return resp;
    } else {
        puts("error");
        exit(0);
    }
}


const char * integrantes() {
    static char grupo[] = {"AV19023"};
    return grupo;
}




