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
	
    for(f=1;f<=8;f++){
        
        printf("%i |",f);
    
        for(c=1;c<=8;c++){
            
            if(f==x && c==y)
			    printf(" Q ");
			    
			    else
		            if (((f+c)==(x+y)||(f-c)==(x-y)) || (f==x||c==y))
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
	int tablero[8][8];
	
	printf(" *** R E Y ***");
	
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
			    printf(" R ");
			   
			    else
		            if((abs(f - x) <= 1) && (abs(c - y) <= 1))
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
        