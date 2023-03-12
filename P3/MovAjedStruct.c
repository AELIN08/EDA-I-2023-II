#include <stdio.h>
#include <stdlib.h>

struct coordenadas{
    int x;
    int y;
};

void Alfil(struct coordenadas );
void Torre(struct coordenadas );
void Queen(struct coordenadas );
void King(struct coordenadas );
void Caballo(struct coordenadas );

int main(){
    short opcion=0;

    while (1) {

        printf("\n\t *** MOVIMIENTOS VALIDOS DE AJEDREZ ***\n");
        printf("1. Caballo \n");
        printf("2. Alfi \n");
        printf("3. Torre \n");
        printf("4. Reina \n");
        printf("5. Rey \n");
        printf("6. Salir \n ");
        printf("¿para cual quieres ver?: ");
        scanf ("%hi", &opcion);
        
        struct coordenadas coordenadasPieza; // Creacion de una instancia de la estructura coordenadas

        switch (opcion){

            case 1:
                Caballo (coordenadasPieza);
                break;
            
            case 2:
                Alfil(coordenadasPieza);
                break;

            case 3:
                Torre(coordenadasPieza);
                break;
            
            case 4:
                Queen(coordenadasPieza);
                break;

            case 5:
                King(coordenadasPieza);
                break;

            case 6: 
                return 0;
                break;

            default:
                printf("\nIngresaste algo incorrecto\n");

        }
    }
    return 0;
}


void Caballo(struct coordenadas coordenadasPieza){
    int x, y, f , c;
	int tablero[8][8];

    printf("\n *** CABALLO ***");

    printf("\nIngrese las coordenadas para poosicionar la pieza\n");
    printf("Fila: ");
    setbuf(stdin, NULL);
    scanf("%d", &coordenadasPieza.x); // Asignacion de la coordenada x a la instancia de la estructura
    getchar();
    printf("\nColumna: ");
    setbuf(stdin, NULL);
    scanf("%d", &coordenadasPieza.y); // Asignacion de la coordenada x a la instancia de la estructura
    getchar();

    printf("---------------------------------------------------\n");
    printf("    1   2   3   4   5   6   7   8\n ");
    printf("  _______________________________\n");

    for (f = 1; f <= 8; f++) {

        printf("%i |", f);

        for (c = 1; c <= 8; c++) {

            // Asignacion de la coordenada x y y a la instancia de la estructura en las sentencias
            if (f == coordenadasPieza.x && c == coordenadasPieza.y)
                printf(" C ");

            else if ((abs(f - coordenadasPieza.x) == 1 && abs(c - coordenadasPieza.y) == 2) || (abs(f - coordenadasPieza.x) == 2 && abs(c - coordenadasPieza.y) == 1))
                printf(" X ");

            else
                if ((f + c) % 2 == 0)
                    printf(" - ");

                else
                    printf(" - ");

            printf("|");
        }
        printf("\n");
    }
    printf("  _______________________________\n");
}

void Alfil(struct  coordenadas coordenadasPieza){
    int x, y, f , c;
	char tablero[8][8];
	
	printf(" \n*** ALFIL ***");
	
	printf("\nIngrese las coordenadas para poosicionar la pieza\n");
	printf("Fila: ");
    setbuf(stdin, NULL);
    scanf("%d", &coordenadasPieza.x);
    getchar();
    printf("\nColumna: ");
    setbuf(stdin, NULL);
    scanf("%d", &coordenadasPieza.y);
    getchar();

	printf("---------------------------------------------------\n");
    printf ("    1   2   3   4   5   6   7   8\n ");
	printf ("  _______________________________\n");
	
    for(f=1;f<=8;f++){
        
        printf("%i |",f);
    
        for(c=1;c<=8;c++){
            
            if(f==coordenadasPieza.x && c==coordenadasPieza.y)
			    printf(" A ");
			    
			    else
		            if ((f+c)==(coordenadasPieza.x+coordenadasPieza.y)||(f-c)==(coordenadasPieza.x-coordenadasPieza.y))
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

void Torre(struct  coordenadas coordenadasPieza){
    int x, y, f , c;
	int tablero[8][8];
	
	printf("\n *** ALFIL ***");
	
	printf("\nIngrese las coordenadas para poosicionar la pieza\n");
	printf("Fila: ");
    setbuf(stdin, NULL);
    scanf("%i", &coordenadasPieza.x);
    getchar();
    printf("\nColumna: ");
    setbuf(stdin, NULL);
    scanf("%i", &coordenadasPieza.y);
    getchar();

	printf("---------------------------------------------------\n");
    printf ("    1   2   3   4   5   6   7   8\n ");
	printf ("  _______________________________\n");
	
    for(f=1;f<=8;f++){
        
        printf("%i |",f);
    
        for(c=1;c<=8;c++){
            
            if(f==coordenadasPieza.x && c==coordenadasPieza.y)
			    printf(" T ");
			    
			    else
		            if (f==coordenadasPieza.x||c==coordenadasPieza.y)
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

void Queen(struct  coordenadas coordenadasPieza){
    int x, y, f , c;
	char tablero[8][8];
	
	printf(" \n*** REINA ***");

    printf("\nIngrese las coordenadas para poosicionar la pieza\n");
	printf("Fila: ");
    setbuf(stdin, NULL);
    scanf("%i", &coordenadasPieza.x);
    getchar();
    printf("\nColumna: ");
    setbuf(stdin, NULL);
    scanf("%i", &coordenadasPieza.y);
    getchar();

	printf("---------------------------------------------------\n");
    printf ("    1   2   3   4   5   6   7   8\n ");
	printf ("  _______________________________\n");


    for(f=1;f<=8;f++){
        
        printf("%i |",f);

        for(c=1;c<=8;c++){
            
            
            if(f==coordenadasPieza.x && c==coordenadasPieza.y)
			    printf(" Q ");
			    
			    else
                    
		            if ((f+c)==(coordenadasPieza.x+coordenadasPieza.y) || (f-c)==(coordenadasPieza.x-coordenadasPieza.y) || (f==coordenadasPieza.x||c==coordenadasPieza.y))
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

void King(struct  coordenadas coordenadasPieza){
    int x, y, f , c;
    int tablero[8][8];
	
	printf("\n *** R E Y ***");
	
	printf("\nIngrese las coordenadas para poosicionar la pieza\n");
	printf("Fila: ");
    setbuf(stdin, NULL);
    scanf("%i", &coordenadasPieza.x);
    getchar();
    printf("\nColumna: ");
    setbuf(stdin, NULL);
    scanf("%i", &coordenadasPieza.y);
    getchar();
    
	printf("---------------------------------------------------\n");
    printf ("    1   2   3   4   5   6   7   8\n ");
	printf ("  _______________________________\n");
	
    for(f=1;f<=8;f++){
        
        printf("%i |",f);
    
        for(c=1;c<=8;c++){
            
            if(f==coordenadasPieza.x && c==coordenadasPieza.y)
			    printf(" R ");
			   
			    else
                    
		            if((abs(f - coordenadasPieza.x) <= 1) && (abs(c - coordenadasPieza.y) <= 1))
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