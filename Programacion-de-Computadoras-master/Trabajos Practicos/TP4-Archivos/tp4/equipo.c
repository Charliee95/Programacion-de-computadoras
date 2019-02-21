#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "equipo.h"
#include "jugador.h"




struct EquipoEstructura{

    char nombre[20];
    int cantHinchas;
    int codigo;
    Jugador jugadores[25];
    int jugadoresCargados;

};



Equipo crearEquipo (char nombre[20], int cantHinchas, int codigo){


    Equipo e = malloc(sizeof(struct EquipoEstructura));

    e->cantHinchas = cantHinchas;
    e->codigo = codigo;
    strcpy(e->nombre, nombre);

    //Cantidad de empleados en el vector, inicialmente 0
    e->jugadoresCargados = 0;



    /////////
    FILE * jugador;
    jugador = fopen("jugador.txt","r");


    while(!feof(jugador)){

        char auxJugador[100] = " ";

        fgets(auxJugador, 100, jugador);


        Jugador j=crearJugadorDesdeChar(auxJugador);

        if (getCodigoEquipo(j) == e->codigo){
            e->jugadores[e->jugadoresCargados] = j;
            e->jugadoresCargados = e->jugadoresCargados+1;
        }

    }


return e;
}



void mostrarEquipo(Equipo e){

        printf("El equipo es %s, tiene %d hinchas, su codigo es: %d, tiene un total de %d jugadores cargados \n", e->nombre, e->cantHinchas, e->codigo, e->jugadoresCargados);

        if(e->jugadoresCargados>0){

            printf("Los cuales son: \n");


            for (int i = 0; i<e->jugadoresCargados; i++){

                mostrarJugador(e->jugadores[i]);
            }


        }


        printf("\n\n-----------------------\n\n");


}



char *getNombre(Equipo e){ return e->nombre;};
int getCantHinchas(Equipo e){return e->cantHinchas;};
int getCodigo(Equipo e){return e->codigo;};
int getJugadoresCargados(Equipo e){return e->jugadoresCargados;};
Jugador * getJugadores(Equipo e){return  e->jugadores;};


void setNombre(Equipo e, char nombre[20]){strcpy(e->nombre, nombre);};
void setCantHinchas(Equipo e, int cantHinchas){e->cantHinchas = cantHinchas;};
void setCodigo(Equipo e, int codigo){e->codigo= codigo;};
void setJugadoresCargados(Equipo e, int jugadoresCargados){e->jugadoresCargados = jugadoresCargados;}
