#include "agenda.h"
#include <stdio.h>

int main() {
    Agenda agenda;
    iniciar_agenda(&agenda);
    
    int opcion;
    char nombre[30];
    char telefono[15];
    
    do {
        printf("\n--- AGENDA DE CONTACTOS ---\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar todos los contactos\n");
        printf("3. Buscar contacto por nombre\n");
        printf("4. Buscar contacto por teléfono\n");
        printf("5. Ordenar contactos (A-Z)\n");
        printf("6. Ordenar contactos (Z-A)\n");
        printf("7. Guardar contactos en archivo\n");
        printf("8. Cargar contactos desde archivo\n");
        printf("9. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1: {
                Contacto nuevo;
                leer_contacto(&nuevo);
                agregar_contacto(&agenda, nuevo);
                printf("Contacto agregado exitosamente.\n");
                break;
            }
            case 2:
                imprimir_agenda(agenda);
                break;
            case 3:
                printf("Nombre a buscar: ");
                scanf("%s", nombre);
                int pos = buscar_contacto(&agenda, nombre);
                if(pos != -1) {
                    printf("Contacto encontrado:\n");
                    mostrar_contacto(agenda.contactos[pos]);
                } else {
                    printf("Contacto no encontrado.\n");
                }
                break;
            case 4:
                printf("Teléfono a buscar: ");
                scanf("%s", telefono);
                pos = buscar_contacto_x_telefono(&agenda, telefono);
                if(pos != -1) {
                    printf("Contacto encontrado:\n");
                    mostrar_contacto(agenda.contactos[pos]);
                } else {
                    printf("Contacto no encontrado.\n");
                }
                break;
            case 5:
                ordenar_contactos(&agenda);
                printf("Contactos ordenados A-Z:\n");
                imprimir_agenda(agenda);
                break;
            case 6:
                ordenar_contactos_inv(&agenda);
                printf("Contactos ordenados Z-A:\n");
                imprimir_agenda(agenda);
                break;
            case 7:
                guardar_contactos("agenda.txt", agenda);
                printf("Contactos guardados en agenda.txt\n");
                break;
            case 8:
                cargar_contactos("agenda.txt", &agenda);
                printf("Contactos cargados desde agenda.txt\n");
                break;
            case 9:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while(opcion != 9);
    
    return 0;
}
