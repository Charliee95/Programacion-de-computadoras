#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

struct AlumnoEstructura{
    int dni;
    char nombre[20];
    char apellido[20];
    //float promedio;
};

Alumno crearAlumno() {

    struct AlumnoEstructura * alumnoCreado = malloc(sizeof(struct AlumnoEstructura));
    printf("Ingrese el dni del alumno: ");
    scanf("%d",&alumnoCreado->dni);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(alumnoCreado->nombre);

    printf("Ingrese el apellido: ");
    gets(alumnoCreado->apellido);
    return alumnoCreado;

    //alumnoCreado->promedio = 13.32;

}

void mostrarAlumno(Alumno a) {
    printf("DNI: %d", a->dni);
    printf("\nNombre y Apellido: %s %s", a->nombre, a->apellido);
    printf("\n\n");
    //printf("\nPromedio: %f", a->promedio);
}
