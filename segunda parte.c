#include <stdio.h>
#define TAM 10

extern int comparaciones;
extern int intercambios;

// Esta función muestra el arreglo (debe estar definida en el otro archivo)
void mostrarArray(int a[]);

void selectionSort(int a[]) {
    int i, j, min, aux;

    for (i = 0; i < TAM - 1; i++) {
        min = i;
        for (j = i + 1; j < TAM; j++) {
            comparaciones++;
            if (a[j] < a[min]) {
                min = j;
            }
        }

        // Intercambio si se encontró un valor menor
        if (min != i) {
            aux = a[i];
            a[i] = a[min];
            a[min] = aux;
            intercambios++;
        }

        // Mostrar el arreglo después de cada paso
        printf("Paso %d: ", i + 1);
        mostrarArray(a);
    }
}
