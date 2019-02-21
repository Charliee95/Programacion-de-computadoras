#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

struct  AlumnoEstructura;

typedef struct AlumnoEstructura * Alumno;

Alumno crearAlumno();

void mostrarAlumno (Alumno a);

#endif // ALUMNO_H_INCLUDED
