#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED



struct JugadorEstructura;
typedef struct JugadorEstructura * Jugador;


Jugador crearJugador (char nombre[20], char apellido[20], int codigoEuipo);
void mostrarJugador (Jugador j);


int getCodigoJugador(Jugador j);





#endif // EMPLEADO_H_INCLUDED
