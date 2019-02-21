#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED

#include "jugador.h"


struct EquipoEstructura;
typedef struct EquipoEstructura * Equipo;


Equipo crearEquipo (char nombre[20], int cantHinchas, int codigo);
void mostrarEquipo(Equipo e);


char *getNombre(Equipo e);
int getCantHinchas(Equipo e);
int getCodigo(Equipo e);
int getJugadoresCargados(Equipo e);



void setNombre(Equipo e, char nombre[20]);
void setCantHinchas(Equipo e, int cantInvitados);
void setCodigo(Equipo e, int codigo);





#endif // EVENTO_H_INCLUDED
