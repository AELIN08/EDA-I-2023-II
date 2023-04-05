#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//ESTRUCTURAS PARA CREAR PILA E INICIALIZARLAS
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

//ESTRUCTURAS PARA CREAR COLA E INICIALIZARLAS
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue
		= (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	queue->rear = capacity - 1;
	queue->array
		= (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

//OPEREACIONES A UTILIZAR PARA PILA
// La pila esta llena cuando el tope es igual al ultimo indice
int isStackFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

// La pila esta vacia cuando el tope es igual a -1
int isStackEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

// Funcion para agregar un elemento a la pila. Incrementa el tope en 1
void push(struct Stack* stack, int item)
{
	if (isStackFull(stack))
		return;
	stack->array[++stack->top] = item;
}

// Funcion para quitar un elemento de la pila. Decrementa el tope en 1
int pop(struct Stack* stack)
{
	if (isStackEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

// Funcion para regresar el valor del tope de la pila sin quitarlo
int peek(struct Stack* stack)
{
	if (isStackEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

//OPERACIONES PARA COLA
// La cola esta llena cuando se vuelve
// igual a la capacidad
int isQueueFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

// La cola esta vacia cuando su tamano es cero
int isQueueEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

// Funcion para agregar un elemento a la cola.
// Cambia la parte trasera y el tamano.

void enqueue(struct Queue* queue, int item)
{
	if (isQueueFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	
}

// Funcion para eliminar un elemento de la cola.
// Cambia el frente y el tamano.
int dequeue(struct Queue* queue)
{
	if (isQueueEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Funcion para obtener el frente de la cola.
int front(struct Queue* queue)
{
	if (isQueueEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Funcion para obtener la parte trasera de la cola
int rear(struct Queue* queue)
{
	if (isQueueEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

main(){
	int i, lastItem;

    struct Stack* stack = createStack(10);
	for(i=10;i>0;i--){
        push(stack, i);
    }

	struct Queue* queue = createQueue(10);

    short opcion=0;

    while (1) {

        printf("\n\t *** BIENVENIDX AL SISTEMA DE TURNOS ***\n\n");
        printf("1. AGREGAR \n");
        printf("2. SALIR \n");
        printf("¿Que opcion desea?: ");
        scanf ("%hi", &opcion);
        
        switch (opcion){

            case 1:
				printf("\n************************************************************************\n\n");
                if (isStackEmpty (stack)) {
					printf("ya no hay turnos disponibles :c");
				}
				else{
					//Para obtener el ultimo elemento de la pila y agregarlo a cla cola
					lastItem=pop(stack);
					enqueue(queue, lastItem);
					printf("El elemento se encuentra formado en la cola con el turno: %d", lastItem);
				}
				printf("\n\n************************************************************************\n");
                break;
            
            case 2:
				printf("\n************************************************************************\n\n");
				if (isStackEmpty (stack)) {
					printf("Ultimo elemento en tope de la pila: vacio");
				}
				else
                	printf("Ultimo elemento en tope de la pila: %d\n", peek(stack));
				
				printf("Ultimo elemento formado en la cola: %d\n", rear(queue));
				printf("\n\n************************************************************************\n");
                return 0;
                break;

            default:
                printf("\nIngresaste algo incorrecto\n");

        }
    }
    return 0;
}
    