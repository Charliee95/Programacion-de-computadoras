#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "jugador.h"




struct JugadorEstructura{
char nombre[20]; char apellido[20]; int codigoEquipo;};


Jugador crearJugador(char nombre[20], char apellido[20], int codigoEquipo){

        Jugador j = malloc(sizeof(struct JugadorEstructura));


        strcpy(j->nombre, nombre);
        strcpy(j->apellido, apellido);
        j->codigoEquipo = codigoEquipo;

        return j;
}

void mostrarJugador(Jugador j){


printf("Jugador: %s, %s  , que pertenece al Equipo numero:  %d \n", j->apellido, j->nombre, j->codigoEquipo);

}


int getCodigoEquipo(Jugador j){return j->codigoEquipo;};
