#include <stdio.h>
#include <stdlib.h>

// Definición de un nodo
typedef struct Nodo {
    int campo;
    struct Nodo* siguiente;
} Nodo;
// Comentario 2
// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->campo = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista
void insertarFinal(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    Nodo* temp = *cabeza;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo;
}

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

// Función para liberar la memoria de la lista
void liberarLista(Nodo* cabeza) {
    Nodo* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    Nodo* cabeza = NULL;

    insertarFinal(&cabeza, 1);
    insertarFinal(&cabeza, 2);
    insertarFinal(&cabeza, 3);

    printf("Lista enlazada: ");
    imprimirLista(cabeza);

    liberarLista(cabeza);
    return 0;
}
