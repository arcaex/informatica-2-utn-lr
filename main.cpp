#include <stdio.h>
#include <stdlib.h>

// Definición de un nodo de la cola
typedef struct Nodo {
    char descripcion[50];
    int cantidad;
    float precio;
    struct Nodo* siguiente;
} Nodo;

// Definición de la cola
typedef struct Cola {
    Nodo* frente;
    Nodo* trasero;
} Cola;

// Función para crear un nuevo nodo
Nodo* crearNodo(char descripcion[50], int cantidad, float precio) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->descripcion = descripcion;
    nuevoNodo->cantidad = cantidad;
    nuevoNodo->precio = precio;
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
void encolar(Cola* cola, char descripcion[50], int cantidad, float precio) {
    Nodo* nuevoNodo = crearNodo(descripcion,cantidad,precio);
    if (cola->trasero == NULL) {
        cola->frente = nuevoNodo;
        cola->trasero = nuevoNodo;
        return;
    }
    cola->trasero->siguiente = nuevoNodo;
    cola->trasero = nuevoNodo;
}

// Función para desencolar (eliminar) un elemento de la cola
void desencolar(Cola* cola) {
    if (cola->frente == NULL) {
        printf("Cola vacía\n");
        return -1;
    }
    Nodo* temp = cola->frente;
    cola->frente = cola->frente->siguiente;
    if (cola->frente == NULL) {
        cola->trasero = NULL;
    }
    free(temp);
    return;
}

// Función para imprimir la cola
void imprimirCola(Cola* cola) {
    Nodo* temp = cola->frente;
    while (temp != NULL) {
        printf("%s -> ", temp->descripcion);
        printf("%d -> ", temp->cantidad);
        printf("%f.2 -> ", temp->precio);
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

    encolar(cola, "Mayonesa",5,500);
    encolar(cola, "Pancho",3,5000);
    encolar(cola, "Carne",300,2500);

    printf("Cola: ");
    imprimirCola(cola);

    desencolar(cola);
    printf("Cola después de desencolar: ");
    imprimirCola(cola);

    liberarCola(cola);
    return 0;
}
