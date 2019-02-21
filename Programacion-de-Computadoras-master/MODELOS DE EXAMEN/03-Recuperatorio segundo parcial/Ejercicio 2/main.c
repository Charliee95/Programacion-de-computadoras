#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

int main()
{

    Alumno alumnos[5];
    int i;
    for(i=0; i<5; i++) {
    alumnos[i] = crearAlumno();
    }
    for(i=0;i<5;i++){
    mostrarAlumno(alumnos[i]);
    printf("\n");
    }
    return 0;
}
