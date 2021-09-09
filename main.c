#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    char PATH[] = ("peliculasFavoritasESD135_2021.csv");
    int *g;
    g = retornarAlgo(PATH);
    
    for (int i = 0; i < 59; i++) {
        
        for (int j = 0; j < 6; j++) {

            printf("%d ,", *(g + i * 6 + j));
            

        }
        printf("\n");
    }
    return 0;
}

