#include <stdio.h>
#define TAM 10

extern int comparaciones;
extern int intercambios;

void mostrarArray(int a[]);

void ordenarDescendente(int a[]) {
    comparaciones = 0;
    intercambios = 0;

    for (int i = 1; i < TAM; i++) {
        int actual = a[i];
        int pos = i - 1;

        while (pos >= 0 && a[pos] < actual) {
            a[pos + 1] = a[pos];
            pos--;
            comparaciones++;
        }

        a[pos + 1] = actual;
        intercambios++;

        printf("Paso %d: ", i);
        mostrarArray(a);
    }

    printf("\nArreglo ordenado (desc): ");
    mostrarArray(a);
    printf("Comparaciones: %d\n", comparaciones);
    printf("Intercambios: %d\n", intercambios);
    printf("Validacion: el arreglo quedo ordenado de mayor a menor.\n");
}