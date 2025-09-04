#include <stdio.h>

#define N 10   // tamaño del arreglo

void mostrar(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void copiar(int o[], int d[], int n) {
    for (int i = 0; i < n; i++) {
        d[i] = o[i];
    }
}

void selectionAsc(int v[], int n) {
    int i, j, pos, aux;
    for (i = 0; i < n - 1; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[pos]) {
                pos = j;
            }
        }
        if (pos != i) { // solo si hay cambio
            aux = v[i];
            v[i] = v[pos];
            v[pos] = aux;
        }
        printf("Paso %d: ", i + 1);
        mostrar(v, n);
    }
    printf("Orden final (asc): ");
    mostrar(v, n);
}

void insertionDesc(int v[], int n) {
    int i, j, clave;
    for (i = 1; i < n; i++) {
        clave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] < clave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = clave;

        printf("Paso %d: ", i);
        mostrar(v, n);
    }
    printf("Orden final (desc): ");
    mostrar(v, n);
}

void llenar(int v[], int n) {
    int num;
    for (int i = 0; i < n; i++) {
        do {
            printf("Número [%d]: ", i + 1);
            scanf("%d", &num);
            if (num <= 0) {
                printf("Debe ser positivo!\n");
            }
        } while (num <= 0);
        v[i] = num;
    }
}

int main() {
    int op, vec[N], copia[N];
    int cargado = 0;

    do {
        printf("\n** MENÚ PRINCIPAL **\n");
        printf("1. Ingresar datos\n");
        printf("2. Ver datos originales\n");
        printf("3. Ordenar con Selection (asc)\n");
        printf("4. Ordenar con Insertion (desc)\n");
        printf("5. Salir\n");
        printf("Elija: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                llenar(vec, N);
                cargado = 1;
                break;
            case 2:
                if (cargado) mostrar(vec, N);
                else printf("Primero ingrese los datos.\n");
                break;
            case 3:
                if (cargado) {
                    copiar(vec, copia, N);
                    selectionAsc(copia, N);
                } else printf("Primero ingrese los datos.\n");
                break;
            case 4:
                if (cargado) {
                    copiar(vec, copia, N);
                    insertionDesc(copia, N);
                } else printf("Primero ingrese los datos.\n");
                break;
            case 5:
                printf("Adiós!\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(op != 5);

    return 0;
}