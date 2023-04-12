// Implementacion de una cola doble en C

#include <stdio.h>

#define MAX 10

// Implementacion de una cola doble en C

#include <stdio.h>

#define MAX 10

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
  int c = 0, i;

  for (i = 0; i < MAX; i++) {
    if (arr[i] != 0)
      c++;
  }
  return c;
}

int main() {
  char arr[MAX]; // arreglo para almacenar la palabra
  int front, rear, i, n;

  front = rear = -1;
  for (i = 0; i < MAX; i++)
    arr[i] = '\0'; // inicializar el arreglo con el carácter nulo

  // agregar caracteres al frente y al final de la cola doble
  addRear(arr, 'o', &front, &rear);
  addFront(arr, 'h', &front, &rear);
  addRear(arr, 'l', &front, &rear);
  addFront(arr, 'e', &front, &rear);
  addRear(arr, '!', &front, &rear);

  printf("Palabra en la cola doble: %s\n", arr);

  // eliminar un carácter del frente y mostrar la palabra actualizada
  i = delFront(arr, &front, &rear);
  printf("Caracter eliminado del frente: %c\n", i);
  printf("Palabra en la cola doble: %s\n", arr);

  // agregar un carácter al final de la cola doble y mostrar la palabra actualizada
  addRear(arr, 'y', &front, &rear);
  printf("Palabra en la cola doble: %s\n", arr);
  printf("cola:\n");
    display(arr);
  // contar el número de caracteres en la cola doble
  n = count(arr);
  printf("Numero total de caracteres en la cola doble: %d\n", n);

  return 0;
}
