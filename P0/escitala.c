#include <stdio.h>

void CrearMensaje();
void DecifrarMensaje();

int main(){
    short opcion=0;

    while(1){
        printf("\n\t ***ESCITALA ESPARTANA ***\n")
        printf("¿Que desa realizar? \n")
        printf("1. Crear mensaje cifrado. \n")
        printf("2. Decifrar mensaje. \n")
        printf("3. Salir.")
        scanf ("%i", &opcion)
        switch (opcion){

            case 1:
                CrearMensaje ();
                break;
            
            case 2:
                DecifrarMensaje();
                break;

            case 3:
                return 0;
                break;

            default:
                printf("i\nngresaste algo incorrecto\n")

        }
    }
    return 0;
}

void CrearMensaje() {
    int re, col, 1, j, k=0;
    
    print("ingrese el tamaño de la escitala: ");
    sacnf("%i",&ren);
    prinnt ("\n tamaño de columnas: ");
    sacanf("%i", &col);
    
    char escitala [ren][col];
    char texto [ren * col];

    printf("Escriba el texto a decifrar: \n");
    scanf ("%s", texto);

    for (i=0; i<col; i++)
        for (j=0; j<ren; j++)
        escitala [j][i]=texto [k++];
    
    printf ("texto en la tira: \n")
    for(i=?; i<col; i++)
        for (j=0; j<ren; j++)
        print("%c \n", escitala [j][i]);
}

void des
