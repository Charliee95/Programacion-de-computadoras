#include <stdio.h>
#include <stdlib.h>

int main()
{
    int jugador,semestre,matriz[3][2],goles,totalJugador[4] = {0,0,0,0};

    for(jugador=1; jugador <=3; jugador++) {
        for(semestre=1; semestre <=2; semestre++) {
            printf("Ingrese cantidad de goles del semestre %d jugador %d: ",semestre,jugador);
            scanf("%d",&goles);
            totalJugador[jugador] = totalJugador[jugador] + goles;
        }
        printf("\nEl total de goles del jugador %d es: %d",jugador,totalJugador[jugador]);
        printf("\n");
    }
    return 0;
}
