#include <stdio.h>

void Alfil();
void Torre();

int main(){
    short opcion=0;

    while (1) {

        printf("\n\t *** MOVIMIENTOS VALIDOS DE AJEDREZ ***\n");
        printf("1. Alfi \n");
        printf("2. Torre \n");
        printf("3. Salir \n ");
        printf("¿para cual quieres ver?: ");
        scanf ("%i", &opcion);
        
        switch (opcion){

            case 1:
                Alfil ();
                break;
            
            case 2:
                Torre();
                break;

            case 3:
                return 0;
                break;

            default:
                printf("\nIngresaste algo incorrecto\n");

        }
    }
    return 0;
}
void Alfil(){
    	int x, y, f , c;
	char tablero[8][8];
	
	printf(" *** ALFIL ***");
	
	printf("\nIngrese las coordenadas para poosicionar la pieza\n");
	printf("Fila: ");
	scanf("%i", &x);
	printf("\nColumna: ");
	scanf("%i", &y);
	printf("---------------------------------------------------\n");
    printf ("    1   2   3   4   5   6   7   8\n ");
	printf ("  _______________________________\n");
	
    for(f=1;f<=8;f++){
        
        printf("%i |",f);
    
        for(c=1;c<=8;c++){
            
            if(f==x && c==y)
			    printf(" A ");
			    
			    else
		            if ((f+c)==(x+y)||(f-c)==(x-y))
				        printf(" X ");
					
			            else 
			                if ((f+c)%2==0)
					            printf (" - ");
					    
				             else
					            printf (" - ");
					            
			printf("|");
        }
        printf("\n");
    }
    printf ("  _______________________________\n");
}

void Torre(){
   int x, y, f , c;
	char tablero[8][8];
	
	printf(" *** ALFIL ***");
	
	printf("\nIngrese las coordenadas para poosicionar la pieza\n");
	printf("Fila: ");
	scanf("%i", &x);
	printf("\nColumna: ");
	scanf("%i", &y);
	printf("---------------------------------------------------\n");
    printf ("    1   2   3   4   5   6   7   8\n ");
	printf ("  _______________________________\n");
	
    for(f=1;f<=8;f++){
        
        printf("%i |",f);
    
        for(c=1;c<=8;c++){
            
            if(f==x && c==y)
			    printf(" T ");
			    
			    else
		            if (f==x||c==y)
				        printf(" X ");
					
			            else 
			                if ((f+c)%2==0)
					            printf (" - ");
					    
				             else
					            printf (" - ");
					            
			printf("|");
        }
        printf("\n");
    }
    printf ("  _______________________________\n");
}
        