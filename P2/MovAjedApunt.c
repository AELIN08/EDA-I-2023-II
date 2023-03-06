#include <stdio.h>

void Queen();
void King();

int main(){
    short opcion=0;

    while (1) {

        printf("\n\t *** MOVIMIENTOS VALIDOS DE AJEDREZ ***\n");
        printf("1. Reina \n");
        printf("2. Rey \n");
        printf("3. Salir \n ");
        printf("¿para cual quieres ver?: ");
        scanf ("%hi", &opcion);
        
        switch (opcion){

            case 1:
                Queen ();
                break;
            
            case 2:
                King();
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
void Queen(){
    int x, y, f , c;
    int *aptx, *apty ;
	char tablero[8][8];
	
	printf(" *** REINA ***");
	
	printf("\nIngrese las coordenadas para poosicionar la pieza\n");
	printf("Fila: ");
	scanf("%i", &x);
	printf("\nColumna: ");
	scanf("%i", &y);
	printf("---------------------------------------------------\n");
    printf ("    1   2   3   4   5   6   7   8\n ");
	printf ("  _______________________________\n");
	
    aptx=&x;
    apty=&y;

    for(f=1;f<=8;f++){
        
        printf("%i |",f);

        for(c=1;c<=8;c++){
            
            // uso de * antes del nombre para acceder al valor almacenado
            if(f==*aptx && c==*apty)
			    printf(" Q ");
			    
			    else
                    // sentencia para el rango del movimiento de la reina
		            if ((f+c)==(*aptx+*apty) || (f-c)==(*aptx-*apty) || (f==*aptx||c==*apty))
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

void King(){
    int x, y, f , c;
    int *aptx, *apty ; //declaracion de los apuntadores

	int tablero[8][8];
	
	printf(" *** R E Y ***");
	
	printf("\nIngrese las coordenadas para poosicionar la pieza\n");
	printf("Fila: ");
	scanf("%i", &x);
	printf("\nColumna: ");
	scanf("%i", &y);
	
    /*acceder a la direccion de la
    variable de tal forma obtiene el valor*/
	aptx=&x;
    apty=&y;
    
	printf("---------------------------------------------------\n");
    printf ("    1   2   3   4   5   6   7   8\n ");
	printf ("  _______________________________\n");
	
    for(f=1;f<=8;f++){
        
        printf("%i |",f);
    
        for(c=1;c<=8;c++){
            // uso de * antes del nombre para acceder al valor almacenado
            if(f==*aptx && c==*apty)
			    printf(" R ");
			   
			    else
                    // sentencia para el rango del movimiento del rey
		            if((abs(f - *aptx) <= 1) && (abs(c - *apty) <= 1))
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

        