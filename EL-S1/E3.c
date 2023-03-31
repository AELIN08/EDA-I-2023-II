
//03.02.23
//ejemplo2 p2
#include <stdio.h>
int main(){
    short arr[5], *apArr;
    apArr=&arr[0];
    printf ("Direccion del arreglo en la primera pos¡cion: %x\n",&arr[0]);
    printf ("Direccion del Arreglo : %x\n",&arr);
    printf("Direccion del apuntador: %x\n",apArr);

    return 0;
}