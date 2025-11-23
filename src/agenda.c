#include "agenda.h"

//Esta función se encarga de iniciar el número de contactos a cero
void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}

//Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

//Esta función sirve para agregar un contacto nuevo en la agenda
void agregar_contacto(Agenda *agenda, Contacto c){
    if(agenda->num_contactos < MAX_CONTACTOS){
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    }
}
//Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
//En caso contrario retorna -1
int buscar_contacto(Agenda *agenda, char *nombre){
    for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].nombre, nombre) == 0){
            return i;
        }
    }
    return -1;
}

//Esta función  sirve para buscar un contacto por su número de telefono en la agenda
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].telefono, telefono) == 0){
            return i;
        }
    }
    return -1;
}


//Esta función sirve para ordenar los contactos por nombres de forma ascendente
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

//Esta función sirve para ordenar los contactos por nombres de forma descendente
void ordenar_contactos_inv(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            //Completar basandose en la función anterior
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) < 0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

//Función auxiliar para imprimir un contacto
void mostrar_contacto(Contacto c){
    printf("\t%s\t%s\t%d\t%d\t%s\t%d\n", 
           c.nombre, 
           c.apellido, 
           c.dia_nacimiento, 
           c.mes_nacimiento, 
           c.telefono, 
           c.tipo_telefono);
}


//Función auxiliar para leer un contacto
void leer_contacto(Contacto *c){
    int mes, tipo;
    
    printf("Nombre: ");
    scanf("%s", c->nombre);
    printf("Apellido: ");
    scanf("%s", c->apellido);
    printf("Día nacimiento: ");
    scanf("%d", &c->dia_nacimiento);
    printf("Mes nacimiento (1-12): ");
    scanf("%d", &mes);
    c->mes_nacimiento = mes;
    
    printf("Tipo de teléfono (1-Casa 2-Movil 3-Oficina 4-Otro):\n");
    printf("Seleccione (1-4): ");
    scanf("%d", &tipo);
    c->tipo_telefono = tipo;
    
    printf("Teléfono: ");
    scanf("%s", c->telefono);
}

//Función que imprime todos los contactos de la agenda en pantalla
void imprimir_agenda(Agenda agenda){
    printf("Nombre\tApellido\tDia\tMes\tTelefono\tTipo\n");
    for(int i=0; i<agenda.num_contactos; i++){
        mostrar_contacto(agenda.contactos[i]);
    }
}

//Función que sirve para cargar contactos escritos en un archivo a la agenda
void cargar_contactos(char *filename, Agenda *agenda){
    FILE *file = fopen(filename, "r");
    if(file == NULL) return;
    
    Contacto c;
    int mes, tipo;
    while(fscanf(file, "%s %s %d %d %s %d", 
                 c.nombre, c.apellido, &c.dia_nacimiento, 
                 &mes, c.telefono, &tipo) == 6) {
        c.mes_nacimiento = mes ;
        c.tipo_telefono = tipo ;
        agregar_contacto(agenda, c);
    }
    fclose(file);
}

//Función que sirve para guardar todos los contactos de la agenda en un archivo
void guardar_contactos(char *filename, Agenda agenda){
    FILE *file = fopen(filename, "w");
    if(file == NULL) return;
    
    for(int i = 0; i < agenda.num_contactos; i++){
        fprintf(file, "%s %s %d %d %s %d\n",
                agenda.contactos[i].nombre,
                agenda.contactos[i].apellido,
                agenda.contactos[i].dia_nacimiento,
                agenda.contactos[i].mes_nacimiento ,
                agenda.contactos[i].telefono,
                agenda.contactos[i].tipo_telefono );
    }
    fclose(file);
}

