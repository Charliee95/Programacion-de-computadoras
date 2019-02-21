//TODOS LOS ORDENAMIENTOS ESTAN HECHOS CON EL METODO BURBUJA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OrdenaDNI();
void MostrarEmpleados();

struct fechas {
    char fechaNacimiento[20];
    char fechaIngreso[20];

};

struct datosempleado {
    char nombre[20];
    char apellido[20];
    int dni;
    struct fechas fecha_empleados;

}empleados[3],aux;


int main()
{
    int i;
    char opc;
    for(i=0; i<3; i++) {
        printf("%i. Digite su nombre: ",i+1);
        gets(empleados[i].nombre);
        printf("Ingrese su apellido: ");
        gets(empleados[i].apellido);
        printf("Ingrese su dni: ");
        scanf("%i",&empleados[i].dni);
        fflush(stdin);
        printf("Digite su fecha de nacimiento: ");
        gets(empleados[i].fecha_empleados.fechaNacimiento);
        printf("Digite su fecha de ingreso al trabajo: ");
        gets(empleados[i].fecha_empleados.fechaIngreso);
    }

    do {
        printf("a- Mostrar empleados");
        printf("\nb- Ordenar por DNI");
        printf("\nc- Ordenar por apellido");
        printf("\nd- Ordenar por nombre");
        printf("\ne- Salir\n");
        scanf("%c",&opc);

        switch(opc) {
            case 'a': MostrarEmpleados();break;
            case 'b': OrdenaDNI();break;
            case 'c': OrdenaApellido();break;
            case 'd': OrdenaNombre();break;


        }
    }while(opc != 'e');

    return 0;
}


void MostrarEmpleados() {
    int i;
    for(i=0; i<3; i++) {
        printf("%d.Nombre empleado: %s",i+1,empleados[i].nombre);
        printf("\nApellido: %s",empleados[i].apellido);
        printf("\nDNI: %d",empleados[i].dni);
        printf("\nFecha de nacimiento: %s",empleados[i].fecha_empleados.fechaNacimiento);
        printf("\nFecha de ingreso: %s",empleados[i].fecha_empleados.fechaIngreso);
        printf("\n\n");
    }
}

void OrdenaDNI() {
    int i,j;
    int n=3;
    for(i=1;i<n;i++) {
        for(j=0;j<n-i;j++) {
            if(empleados[j].dni > empleados[j+1].dni){
                aux.dni = empleados[j].dni;
                empleados[j].dni = empleados[j+1].dni;
                empleados[j+1].dni = aux.dni;

                strcpy(aux.nombre, empleados[j].nombre);
                strcpy(empleados[j].nombre, empleados[j+1].nombre);
                strcpy(empleados[j+1].nombre, aux.nombre);

                strcpy(aux.apellido, empleados[j].apellido);
                strcpy(empleados[j].apellido, empleados[j+1].apellido);
                strcpy(empleados[j+1].apellido, aux.apellido);
            }
        }
    }

    for(i=0;i<3;i++){
        printf(" %d,",empleados[i].dni);
        printf(" %s %s",empleados[i].nombre,empleados[i].apellido);
        printf("\n");
    }
    printf("\n\n");
}

void OrdenaNombre() {
    int i,j;
    int n=3;
    for(i=1;i<n;i++) {
        for(j=0;j<n-i;j++) {
            if(strcmp(empleados[j].nombre, empleados[j+1].nombre) >0){
                aux.dni = empleados[j].dni;
                empleados[j].dni = empleados[j+1].dni;
                empleados[j+1].dni = aux.dni;

                strcpy(aux.nombre, empleados[j].nombre);
                strcpy(empleados[j].nombre, empleados[j+1].nombre);
                strcpy(empleados[j+1].nombre, aux.nombre);

                strcpy(aux.apellido, empleados[j].apellido);
                strcpy(empleados[j].apellido, empleados[j+1].apellido);
                strcpy(empleados[j+1].apellido, aux.apellido);
            }
        }
    }

    for(i=0;i<3;i++){
        printf(" %d,",empleados[i].dni);
        printf(" %s %s",empleados[i].nombre,empleados[i].apellido);
        printf("\n");
    }
    printf("\n\n");
}

void OrdenaApellido() {
    int i,j;
    int n=3;
    for(i=1;i<n;i++) {
        for(j=0;j<n-i;j++) {
            if(strcmp(empleados[j].apellido, empleados[j+1].apellido) >0){
                aux.dni = empleados[j].dni;
                empleados[j].dni = empleados[j+1].dni;
                empleados[j+1].dni = aux.dni;

                strcpy(aux.nombre, empleados[j].nombre);
                strcpy(empleados[j].nombre, empleados[j+1].nombre);
                strcpy(empleados[j+1].nombre, aux.nombre);

                strcpy(aux.apellido, empleados[j].apellido);
                strcpy(empleados[j].apellido, empleados[j+1].apellido);
                strcpy(empleados[j+1].apellido, aux.apellido);
            }
        }
    }

    for(i=0;i<3;i++){
        printf(" %d,",empleados[i].dni);
        printf(" %s %s",empleados[i].nombre,empleados[i].apellido);
        printf("\n\n");
    }
    printf("\n\n");
}


