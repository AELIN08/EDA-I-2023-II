//03.02.23
//ejemplo1 p2

#include <stdio.h>
//programa cres apuntador de tipo csarcter

int main(){
    char *ap, c;
    c='x';
    ap=&c;

    printf("caracter: %c\n",*ap);
    printf("Codigo ASCII : %d\n",*ap);
    printf("Direccion de memoria %p\n", ap);

    return 0;
}
