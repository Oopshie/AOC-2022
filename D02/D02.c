//A ROCA
//B PAPEL
//C TIJERAS
//X ROCA 1
//Y PAPEL 2
//Z TIJERAS 3
//lost 0
//empate 3
//win 6
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    FILE *archivo;
    char elfo, yo;
    int puntos = 0;
    int puntos2 = 0;


    archivo = fopen(argv[1], "r");
     if (archivo==NULL){
        printf("Error al abrir el archivo\n");
    }
    printf("Se abrio el archivo correctamente\n");

    while (!feof(archivo)){
        fscanf(archivo, " %c %c ", &elfo, &yo);
        if (yo == 'X'){// si elijo piedra o tengo que perder
            puntos = puntos +  1;
            puntos2 = puntos2 + 0;

            if (elfo == 'A'){ //Si elije roca
                puntos = puntos + 3;
                puntos2 = puntos2 + 3;
            }

            else if (elfo == 'B'){//si elije papel
                puntos = puntos + 0;
                puntos2 = puntos2 + 1;
            }

            else if(elfo == 'C'){ //si elije tijera
                puntos = puntos + 6;
                puntos2 = puntos2 + 2; 
            }
        }
        else if(yo == 'Y'){ // si elijo papel o tengo que empatar
            puntos = puntos + 2;
            puntos2 = puntos2 + 3;

            if (elfo == 'A'){ //Si elije roca
                puntos = puntos + 6;
                puntos2 = puntos2 + 1;
            }

            else if (elfo == 'B'){//si elije papel
                puntos = puntos + 3;
                puntos2 = puntos2 + 2;
            }
            else if(elfo == 'C'){ //si elije tijera
                puntos = puntos + 0;
                puntos2 = puntos2 + 3;
            }
        }

        else if(yo == 'Z'){ //si elijo tijeras o tengo que ganar
            puntos = puntos + 3;
            puntos2 = puntos2 + 6;

            if (elfo == 'A'){ //Si elije roca
                puntos = puntos + 0;
                puntos2 = puntos2 + 2;
            }

            else if (elfo == 'B'){//si elije papel
                puntos = puntos + 6;
                puntos2 = puntos2 + 3;
            }   

            else if(elfo == 'C'){ //si elije tijera
                puntos = puntos + 3;
                puntos2 = puntos2 + 1;
            }
        }
    }

    printf("Con la primera estrategia obtengo %d puntos\n", puntos);
    printf("Con la segunda estrategia obtengo %d puntos", puntos2);
    fclose(archivo);
    return 0;
}


