#include <stdio.h>
#include <stdlib.h>

// Definición de un nodo de la cola
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Definición de la cola
typedef struct Cola {
    Nodo* frente;
    Nodo* trasero;
} Cola;

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para inicializar la cola
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->frente = cola->trasero = NULL;
    return cola;
}

// Función para encolar (agregar) un elemento a la cola
void encolar(Cola* cola, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (cola->trasero == NULL) {
        cola->frente = cola->trasero = nuevoNodo;
        return;
    }
    cola->trasero->siguiente = nuevoNodo;
    cola->trasero = nuevoNodo;
}

// Función para desencolar (eliminar) un elemento de la cola
int desencolar(Cola* cola) {
    if (cola->frente == NULL) {
        printf("Cola vacía\n");
        return -1;
    }
    Nodo* temp = cola->frente;
    int dato = temp->dato;
    cola->frente = cola->frente->siguiente;
    if (cola->frente == NULL) {
        cola->trasero = NULL;
    }
    free(temp);
    return dato;
}

// Función para imprimir la cola
void imprimirCola(Cola* cola) {
    Nodo* temp = cola->frente;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

// Función para liberar la memoria de la cola
void liberarCola(Cola* cola) {
    Nodo* temp;
    while (cola->frente != NULL) {
        temp = cola->frente;
        cola->frente = cola->frente->siguiente;
        free(temp);
    }
    free(cola);
}

int main() {
    Cola* cola = crearCola();

    encolar(cola, 1);
    encolar(cola, 2);
    encolar(cola, 3);

    printf("Cola: ");
    imprimirCola(cola);

    printf("Desencolado: %d\n", desencolar(cola));
    printf("Cola después de desencolar: ");
    imprimirCola(cola);

    liberarCola(cola);
    return 0;
}
