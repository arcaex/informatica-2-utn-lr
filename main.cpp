#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de un nodo de la cola
typedef struct Nodo {
    char* descripcion;
    int cantidad;
    int codigo;
    float precio;
    struct Nodo* siguiente;
} Nodo;

// Definición de la cola
typedef struct Cola {
    Nodo* frente;
    Nodo* trasero;
} Cola;

// Función para crear un nuevo nodo
Nodo* crearNodo(char* descripcion, int cantidad, float precio, int codigo) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->descripcion = descripcion;
    nuevoNodo->cantidad = cantidad;
    nuevoNodo->precio = precio;
    nuevoNodo->codigo = codigo;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para inicializar la cola
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->frente = cola->trasero = NULL;
    return cola;
}

// Cantidad de Nodos
int cantidadElementos(Cola* cola) {
    int c = 0;
    Nodo* temp = cola->frente;
    while (temp != NULL) {
        c++;
        temp = temp->siguiente;
    }
    return c;
}

// Función para encolar (agregar) un elemento a la cola
void encolar(Cola* cola, char* descripcion, int cantidad, float precio) {
    int codigo = cantidadElementos(cola) + 1;
    Nodo* nuevoNodo = crearNodo(descripcion,cantidad,precio,codigo);
    if (cola->trasero == NULL) {
        cola->frente = nuevoNodo;
        cola->trasero = nuevoNodo;
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
    cola->frente = cola->frente->siguiente;
    if (cola->frente == NULL) {
        cola->trasero = NULL;
    }
    free(temp);
    return 1;
}

// Función para imprimir la cola
void imprimirCola(Cola* cola) {
    Nodo* temp = cola->frente;
    while (temp != NULL) {
        printf("%s -> ", temp->descripcion);
        printf("%d -> ", temp->cantidad);
        printf("%d -> ", temp->codigo);
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

    char* descripcion;
    int cantidad;
    float precio;

    printf("Ingrese Nombre del Producto");
    scanf("%s",descripcion);

    printf("Ingresar Cantidad");
    scanf("%d",&cantidad);

    printf("Ingresar Precio");
    scanf("%f",&precio);

    encolar(cola, descripcion,cantidad,precio);

    printf("Cola: ");
    imprimirCola(cola);

    desencolar(cola);
    printf("Cola después de desencolar: ");
    imprimirCola(cola);

    printf("La cantidad de nodos es %d",cantidadElementos(cola));
    liberarCola(cola);
    return 0;
}
