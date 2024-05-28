#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir la estructura
struct Animal {
    char *nombre;
    char tipo[50];
    int edad;
};

int calcular_edad_humana(struct Animal mascota) {
    return mascota.edad * 7;
}

int main() {
    // Crear la variable de la estructura y asignar valores
    struct Animal mascota;
    int edad_humana;

    // Asignar memoria para el nombre
    mascota.nombre = (char *)malloc(50 * sizeof(char));

    // Asignar valores a los campos de la estructura
    strcpy(mascota.nombre, "Bella");
    strcpy(mascota.tipo, "Gato");
    mascota.edad = 5;

    // Imprimir los valores para verificar
    printf("Nombre: %s\n", mascota.nombre);
    printf("Tipo: %s\n", mascota.tipo);
    printf("Edad: %d\n", mascota.edad);

    edad_humana = calcular_edad_humana(mascota);
    printf("La Edad Humana es: %d\n", edad_humana);

    return 0;
}
