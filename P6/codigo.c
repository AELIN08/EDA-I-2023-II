// Implementacion de una cola doble en C

#include <stdio.h>
#include <string.h>

#define MAX 30

void addFront(char *, char, int *, int *);
void addRear(char *, char, int *, int *);
char delFront(char *, int *, int *);
char delRear(char *, int *, int *);
void display(char *);
int count(char *);

void addFront(char *arr, char item, int *pfront, int *prear) {
  int i, k, c;

  if (*pfront == 0 && *prear == MAX - 1) {
    printf("\nDeque esta llena.\n");
    return;
  }

  if (*pfront == -1) {
    *pfront = *prear = 0;
    arr[*pfront] = item;
    return;
  }

  if (*prear != MAX - 1) {
    c = count(arr);
    k = *prear + 1;
    for (i = 1; i <= c; i++) {
      arr[k] = arr[k - 1];
      k--;
    }
    arr[k] = item;
    *pfront = k;
    (*prear)++;
  } else {
    (*pfront)--;
    arr[*pfront] = item;
  }
}

void addRear(char *arr, char item, int *pfront, int *prear) {
  int i, k;

  if (*pfront == 0 && *prear == MAX - 1) {
    printf("\nDeque esta llena.\n");
    return;
  }

  if (*pfront == -1) {
    *prear = *pfront = 0;
    arr[*prear] = item;
    return;
  }

  if (*prear == MAX - 1) {
    k = *pfront - 1;
    for (i = *pfront - 1; i < *prear; i++) {
      k = i;
      if (k == MAX - 1)
        arr[k] = ' ';
      else
        arr[k] = arr[i + 1];
    }
    (*prear)--;
    (*pfront)--;
  }
  (*prear)++;
  arr[*prear] = item;
}

char delFront(char *arr, int *pfront, int *prear) {
  char item;

  if (*pfront == -1) {
    printf("\nDeque esta vacia.\n");
    return ' ';
  }

  item = arr[*pfront];
  arr[*pfront] = ' ';

  if (*pfront == *prear)
    *pfront = *prear = -1;
  else
    (*pfront)++;

  return item;
}

char delRear(char *arr, int *pfront, int *prear) {
  char item;

  if (*pfront == -1) {
    printf("\nDeque esta vacia.\n");
    return 0;
  }

  item = arr[*prear];
  arr[*prear] = 0;
  (*prear)--;
  if (*prear == -1)
    *pfront = -1;
  return item;
}

void display(char *arr) {
  int i;

  printf("\n frente:  ");
  for (i = 0; i < MAX; i++)
    printf("  %c", arr[i]);
    printf("  :parte trasera");
}

int count(char *arr) {
  int c = 1 , i;

  for (i = 0; i < MAX; i++) {
    if (arr[i] != 0)
      c++;
  }
  return c;
}

int main() {
  char arr[MAX], word[MAX]; // arreglo para almacenar la palabra
  int front, rear, i, n, size;

  front = rear = -1;
  for (i = 0; i < MAX; i++)
    arr[i] = ' ';// inicializar el arreglo con el carácter nulo

  printf("Ingrese la palabra");
  scanf("%s",word);
  size=strlen(word);

  //agrega los caracteres de la palabra al arreglo
  for(i=0;i<size;i++)
    addFront(arr,word, &front, &rear);
  //para finalizar la entrada de caracteres
  arr[size]='0';


  printf("Palabra en la cola doble: %s\n", arr);

  printf("cola:\n");
    display(arr);
  // contar el número de caracteres en la cola doble
  n = count(arr);
  printf("Numero total de caracteres en la cola doble: %d\n", n);

  return 0;
}
