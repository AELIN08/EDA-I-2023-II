#include <stdio.h>

void CrearMensaje();
void DecifrarMensaje();

int main(){
	
    short opcion=0;

    while (1) {
        printf("\n\t ***ESCITALA ESPARTANA ***\n");
        printf("1. Crear mensaje cifrado. \n");
        printf("2. Decifrar mensaje. \n");
        printf("3. Salir.\n ");
        printf("¿Que desa realizar?: ");
        scanf ("%hi", &opcion);
        
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
                printf("i\nngresaste algo incorrecto\n");

        }
    }
    return 0;
}

void CrearMensaje() {
    int ren, col, i, j, k=0;
    
    printf("ingrese el tamaño de la escitala:\n ");
    printf("renglones: ");
    scanf("%i",&ren);
    printf("\n  columnas: ");
    scanf("%i", &col);
    
    char escitala [ren][col];
    char texto [ren * col];

    printf("Escriba el texto a decifrar: ");
    scanf("%s", texto);

    for (i=0; i<col; i++)
        for (j=0; j<ren; j++)
            escitala [j][i]=texto [k++];
    
    printf ("texto en la tira: \n");
    for(i=0; i<col; i++)
        for (j=0; j<ren; j++)
        printf("%c \n", escitala [j][i]);
}

void DecifrarMensaje(){
    int ren, col, i, j, k=0;

    printf("ingresa el tamaño de la escitala:\n ");
    printf("renglones: ");
    scanf("%i",&ren);
    printf("\n columnas: ");
    scanf("%i", &col);
    
    char escitala[ren][col];
    char texto[ren * col];

    printf("Escriba el texto a descifrar: ");
    scanf("%s", texto);
    for (i=0; i<col; i++)
        for (j=0; j<ren; j++)
            escitala [j][i]=texto [k++];
    printf("el texto decifrado es:\n\t");
    for(i=0; i<ren; i++)
        for(j=0; j<col; j++)
        printf("%c", escitala[i][j]);

}

