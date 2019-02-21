#include <stdio.h>
#include <stdlib.h>
#include "nadador.h"

int main()
{
    Nadador nadadores[3];
    int i;
    for(i=0; i<3; i++){
        nadadores[i] = crearNadador();
    }
    printf("NADADORES: \n");

    for(i=0; i<3; i++){
        mostrarNadador(nadadores[i]);
    }

    mostrarNadadoresOrdenados(nadadores[0]);



    return 0;
}
