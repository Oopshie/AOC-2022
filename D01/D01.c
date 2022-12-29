#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *archivo; 
    char linea[10]; 
    int num_elf = 1; //cantidad de elfos
    int num_mayor = 0; //numero del elfo con mayor calorias 
    int cal_acum = 0; // calorias acumuladas por el elfo actual
    int cal_mayor = 0; //calorias acumuladas por el elfo mayor
    int mayor2 = 0;
    int mayor3 = 0;

    //abrir archivo
    archivo = fopen(argv[1], "r");
    if (archivo==NULL){
        printf("Error al abrir el archivo");
    }
    printf("Se abrio el archivo correctamente\n");

    //leer linea por linea
    while(fgets(linea, 10, archivo)){
        if (linea[0] == '\n'|| linea[0]=='\r'){ //si encuentra un espacio vacio
            if (cal_acum > cal_mayor){ //si el acumulado es mayor al mayor encontrado
                num_mayor = num_elf; //actualizar elfo mayor
                mayor3 = mayor2; 
                mayor2 = cal_mayor;
                cal_mayor = cal_acum; //actualizar monto mayor
            }
            //al actualizar todos los mayores estamos corriendo la lista de mayores

            else if(cal_acum > mayor2){
                mayor3 = mayor2;
                mayor2 = cal_acum;
            }

            else if(cal_acum > mayor3){
                mayor3 = cal_acum;
            }

            cal_acum = 0;
            num_elf ++;
        
        }

        else{
            cal_acum = cal_acum + atoi(linea);
        }
    }

    printf("\nEl elfo acarraeando mas calorias es el numero %d con %d calorias", num_mayor, cal_mayor);
    printf("\nEl segundo elfo acarraeando mas calorias tiene %d calorias", mayor2);
    printf("\nEl tercer elfo acarraeando mas calorias tiene %d calorias", mayor3);
    printf("\n\nLa suma de las calorias acarreadas por los tres mejores elfos es: %d", cal_mayor+mayor2+mayor3);

    fclose(archivo);
    return 0;
}