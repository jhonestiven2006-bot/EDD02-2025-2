  #include <stdio.h>
#include <stdlib.h>

#define TAM 10   // tamaño fijo del arreglo

// funciones
void llenarArray(int a[], int n);
void mostrarArray(int a[], int n);
void copiarArray(int origen[], int destino[], int n);
void ordenarSelectionAscendente(int a[], int n);
void ordenarInsertionDescendente(int a[], int n);

// llenar el arreglo con enteros positivos
void llenarArray(int a[], int n) {
    int num, i = 0;
    printf("Ingresa %d numeros enteros positivos:\n", n);

    while (i < n) {
        printf("Numero %d: ", i + 1);
        if (scanf("%d", &num) == 1) {
            if (num >= 0) {  // solo positivos
                a[i] = num;
                i++;
            } else {
                printf("Error: el numero debe ser positivo.\n");
            }
        } else {
            printf("Entrada invalida. Ingresa un numero entero.\n");
            while (getchar() != '\n'); // limpiar buffer
        }
    }
}

// mostrar el arreglo en una línea
void mostrarArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// copiar el arreglo original a otro
void copiarArray(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

// selection sort ascendente (menor a mayor)
void ordenarSelectionAscendente(int a[], int n) {
    printf("\n--- Selection Sort Ascendente ---\n");

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // intercambio
            int tmp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = tmp;

            // mostrar solo cuando hubo intercambio
            printf("Paso %d: ", i + 1);
            mostrarArray(a, n);
        }
    }

    printf("Arreglo ordenado (ascendente):\n");
    mostrarArray(a, n);
}

// insertion sort descendente (mayor a menor)
void ordenarInsertionDescendente(int a[], int n) {
    printf("\n--- Insertion Sort Descendente ---\n");

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        // mover elementos si son menores que la clave
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        printf("Paso %d: ", i);
        mostrarArray(a, n);
    }

    printf("Arreglo ordenado (descendente):\n");
    mostrarArray(a, n);
}

// programa principal con menú
int main() {
    int arreglo[TAM];   // arreglo original
    int copia[TAM];     // copia para ordenar sin perder el original
    int opcion;
    int datosIngresados = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Registrar datos\n");
        printf("2. Mostrar arreglo original\n");
        printf("3. Ordenar con Selection Sort (ascendente)\n");
        printf("4. Ordenar con Insertion Sort (descendente)\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                llenarArray(arreglo, TAM);
                datosIngresados = 1;
                break;
            case 2:
                if (datosIngresados) {
                    printf("Arreglo original:\n");
                    mostrarArray(arreglo, TAM);
                } else {
                    printf("Primero debes ingresar los datos.\n");
                }
                break;
            case 3:
                if (datosIngresados) {
                    copiarArray(arreglo, copia, TAM);
                    ordenarSelectionAscendente(copia, TAM);
                } else {
                    printf("Primero debes ingresar los datos.\n");
                }
                break;
            case 4:
                if (datosIngresados) {
                    copiarArray(arreglo, copia, TAM);
                    ordenarInsertionDescendente(copia, TAM);
                } else {
                    printf("Primero debes ingresar los datos.\n");
                }
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}