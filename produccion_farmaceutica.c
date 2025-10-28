#include <stdio.h>
#include <string.h>

// ==============================
// Declaración de constantes y variables globales
// ==============================
#define MAX_LOTES 5

typedef struct {
    char nombre[50];
    int cantidad;
    float pureza;
} Lote;

Lote produccion[MAX_LOTES];
int totalLotes = 0;

// ==============================
// Prototipos de funciones (esto es clave)
// ==============================
void menu();
void registrarLote();
void mostrarLotes();
void controlCalidad();

// ==============================
// Función principal
// ==============================
int main() {
    int opcion;
    do {
        menu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: registrarLote(); break;
            case 2: mostrarLotes(); break;
            case 3: controlCalidad(); break;
            case 4: printf("Saliendo del sistema...\n"); break;
            default: printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    return 0;
}

// ==============================
// Definición de funciones
// ==============================
void menu() {
    printf("\n=== SISTEMA DE PRODUCCIÓN FARMACÉUTICA ===\n");
    printf("1. Registrar nuevo lote\n");
    printf("2. Mostrar lotes registrados\n");
    printf("3. Control de calidad\n");
    printf("4. Salir\n");
}

void registrarLote() {
    if (totalLotes >= MAX_LOTES) {
        printf("Capacidad máxima alcanzada.\n");
        return;
    }

    printf("Ingrese el nombre del lote: ");
    scanf("%s", produccion[totalLotes].nombre);
    printf("Ingrese la cantidad producida: ");
    scanf("%d", &produccion[totalLotes].cantidad);
    printf("Ingrese el porcentaje de pureza: ");
    scanf("%f", &produccion[totalLotes].pureza);

    totalLotes++;
    printf("✅ Lote registrado con éxito.\n");
}

void mostrarLotes() {
    if (totalLotes == 0) {
        printf("No hay lotes registrados.\n");
        return;
    }

    printf("\n--- Lotes registrados ---\n");
    for (int i = 0; i < totalLotes; i++) {
        printf("Lote %d: %s | Cantidad: %d | Pureza: %.2f%%\n",
               i + 1,
               produccion[i].nombre,
               produccion[i].cantidad,
               produccion[i].pureza);
    }
}

void controlCalidad() {
    if (totalLotes == 0) {
        printf("No hay lotes para verificar.\n");
        return;
    }

    printf("\n--- Control de calidad ---\n");
    for (int i = 0; i < totalLotes; i++) {
        if (produccion[i].pureza >= 98.0)
            printf("Lote %s: APROBADO (%.2f%%)\n", produccion[i].nombre, produccion[i].pureza);
        else
            printf("Lote %s: RECHAZADO (%.2f%%)\n", produccion[i].nombre, produccion[i].pureza);
    }
}
