#include <stdio.h>

// -------------------- Estructura --------------------
// Commit: feat: estructura de datos y arreglo de estudiantes
struct Estudiante {
    int codigo;
    float nota;
};

struct Estudiante estudiantes[] = {
    {2024101, 4.5},
    {2024102, 3.2},
    {2024103, 4.0},
    {2024104, 2.8},
    {2024105, 3.9}
};

int total = sizeof(estudiantes) / sizeof(estudiantes[0]);

// -------------------- Menú --------------------
// Commit: feat: menú interactivo
void mostrarMenu() {
    printf("\n--- MENÚ ---\n");
    printf("1. Buscar Nota Máxima (Recursivo)\n");
    printf("2. Calcular Promedio (Recursivo)\n");
    printf("3. Ordenar por Código (Recursivo)\n");
    printf("4. Salir\n");
}

// -------------------- Punto 1: Nota Máxima --------------------
// Commit: feat: nota máxima recursiva
float notaMaxima(struct Estudiante est[], int index, int total, float max) {
    if (index >= total) return max;
    if (est[index].nota > max) max = est[index].nota;
    return notaMaxima(est, index + 1, total, max);
}

// -------------------- Punto 2: Promedio --------------------
// Commit: feat: promedio recursivo
float sumaNotas(struct Estudiante est[], int index, int total) {
    if (index == total) return 0;
    return est[index].nota + sumaNotas(est, index + 1, total);
}

float promedioCurso(struct Estudiante est[], int total) {
    return sumaNotas(est, 0, total) / total;
}

// -------------------- Punto 3: Ordenamiento --------------------
// Commit: feat: ordenamiento recursivo por código
void intercambiar(struct Estudiante *a, struct Estudiante *b) {
    struct Estudiante temp = *a;
    *a = *b;
    *b = temp;
}

int buscarMinimo(struct Estudiante est[], int inicio, int total, int minIndex) {
    if (inicio == total) return minIndex;
    if (est[inicio].codigo < est[minIndex].codigo) minIndex = inicio;
    return buscarMinimo(est, inicio + 1, total, minIndex);
}

void ordenarPorCodigo(struct Estudiante est[], int inicio, int total) {
    if (inicio >= total - 1) return;
    int minIndex = buscarMinimo(est, inicio, total, inicio);
    if (minIndex != inicio) {
        intercambiar(&est[inicio], &est[minIndex]);
    }
    ordenarPorCodigo(est, inicio + 1, total);
}

// -------------------- Mostrar Estudiantes --------------------
// Commit: feat: impresión recursiva de estudiantes
void mostrarEstudiantes(struct Estudiante est[], int index, int total) {
    if (index == total) return;
    printf("Código: %d, Nota: %.2f\n", est[index].codigo, est[index].nota);
    mostrarEstudiantes(est, index + 1, total);
}

// -------------------- Ejecución del Menú --------------------
// Commit: feat: ejecución del menú con validación
void ejecutarMenu(int opcion) {
    if (opcion == 1) {
        float max = notaMaxima(estudiantes, 0, total, estudiantes[0].nota);
        printf("Nota máxima: %.2f\n", max);
    } else if (opcion == 2) {
        float promedio = promedioCurso(estudiantes, total);
        printf("Promedio del curso: %.2f\n", promedio);
    } else if (opcion == 3) {
        ordenarPorCodigo(estudiantes, 0, total);
        printf("Estudiantes ordenados:\n");
        mostrarEstudiantes(estudiantes, 0, total);
    } else if (opcion == 4) {
        printf("Saliendo...\n");
    } else {
        printf("Opción inválida.\n");
    }
}

// -------------------- Main --------------------
// Commit: feat: función principal y flujo completo
void iniciarPrograma() {
    int opcion;
    printf("Seleccione una opción: ");
    if (scanf("%d", &opcion) != 1) {
        printf("Entrada inválida. Intente de nuevo.\n");
        while (getchar() != '\n'); // limpia el buffer
        iniciarPrograma();
        return;
    }
    ejecutarMenu(opcion);
    if (opcion != 4) iniciarPrograma();
}

int main() {
    mostrarMenu();
    iniciarPrograma();
    return 0;
}