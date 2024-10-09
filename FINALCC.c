#include <stdio.h>
#include <stdlib.h>

#define capacidad_reservas 2

enum Cancha { PEQUENA, MEDIANA, GRANDE };

union Detalle {
    int tiempo;
    int cant_personas;
};

struct Reservacion {
    int documento;
    enum Cancha tip_cancha;
    union Detalle det_res;
    float precio;
};

struct Reservacion res[capacidad_reservas];
int contador = 0;

void agregar_Reservacion() {
    if (contador >= capacidad_reservas) {
        printf("\nNo se pueden agregar más reservaciones.\n");
        return;
    }

    struct Reservacion *nueva_res = &res[contador++];
    
    printf("\nIngrese el documento: ");
    scanf("%d", &nueva_res->documento);

    printf("\nIngrese el precio base: ");
    scanf("%f", &nueva_res->precio);

    int cancha;
    printf("\nIngrese el tipo de cancha (0 Pequeña, 1 Mediana, 2 Grande): ");
    scanf("%d", &cancha);
    nueva_res->tip_cancha = (enum Cancha)cancha;

    printf("\nIngrese el tiempo: ");
    scanf("%d", &nueva_res->det_res.tiempo);

    printf("\nIngrese la cantidad de personas: ");
    scanf("%d", &nueva_res->det_res.cant_personas);

    printf("\nReservación agregada con éxito.\n");
}

void mostrar_Reservaciones() {
    if (contador == 0) {
        printf("\nNo hay reservaciones.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        printf("\nReservación %d:\n", i + 1);
        printf("Documento: %d\n", res[i].documento);
        printf("Precio: %.2f\n", res[i].precio);
        printf("Tipo de cancha: %d\n", res[i].tip_cancha);
        printf("Tiempo reservado: %d\n", res[i].det_res.tiempo);
        printf("Cantidad de personas: %d\n", res[i].det_res.cant_personas);
    }
}

void total_Recaudado() {
    float total = 0;
    for (int i = 0; i < contador; i++) {
        total += res[i].precio;
    }
    printf("\nTotal recaudado: %.2f\n", total);
}

int main() {
    int opcion;

    do {
        printf("\nIngrese la operación a realizar:");
        printf("\n(1) Agregar reservación de cancha");
        printf("\n(2) Mostrar reservaciones");
        printf("\n(3) Calcular el total recaudado");
        printf("\n(0) Para finalizar\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregar_Reservacion();
                break;
            case 2:
                mostrar_Reservaciones();
                break;
            case 3:
                total_Recaudado();
                break;
            case 0:
                printf("\nSaliendo del programa.\n");
                break;
            default:
                printf("\nOpción inválida.\n");
        }
    } while (opcion != 0);

    return 0;
}
