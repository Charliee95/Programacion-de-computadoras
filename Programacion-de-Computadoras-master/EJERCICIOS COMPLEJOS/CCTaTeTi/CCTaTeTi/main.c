#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* alo soy el claudio corsico trayendo un codigo de tateti sin AI que apenas funciona xdd
Pense en una implementacion de Ai para ver cuan lejos llego pero pense na
Hay ocasiones en las que pude usar el operador <or> (||) u <else if> pero como aun no se aprendio aquello en clase (creo?), evité usarlos.

Para los que quieran saber por que primero <y> y luego <x>:
Mi grilla esta compuesta, para mi, de la siguiente manera:
grilla[3] me da una tabla de tres cuadrados:
[]

[]

[]

Cuando hago grilla[3][3], mi grilla se vuelve una tabla de 3 cuadrados los cuales contienen tres cuadrados (o asi lo saque de Lua):
[][][]

[][][]

[][][]

Por ende, grilla[y][x].
*/

// Declaro algunas variables fuera de main() por que puedo
char j1Simbolo = 'X'; // Valor para el simbolo del jugador 1 (Normalmente 'X')
char j2Simbolo = 'O'; // Valor para el simbolo del jugador 2 (Normalmente 'O')

// Declaro algunas funciones por conveniencia
int esFicha(char n) { // Funcion esFicha: Devuelve si el caracter es una "ficha" (X o O) o no.
    if (n == j1Simbolo) return 1; // Es X? Es una ficha, devuelve 1.
    if (n == j2Simbolo) return 2; // Es O? Es una ficha, devuelve 2.
    return 0; // Si hasta ahora no devolvio algun valor (por que no era ninguno de esos dos), devuelve 0.
}
int mismaFicha(char a, char b, char c) { //Funcion mismaFicha: Toma tres caracteres.
    // Si los tres caracteres son fichas, y las fichas son iguales, devuelve 1. Si no, devuelve 0.
    if (esFicha(a) > 0) {if (esFicha(a) > 0) {if (esFicha(a) > 0) { // Si todas las variables ingresadas son fichas
        if (a==b) {if (b==c) {if (a==c) { // Si todas las variables son iguales
            return esFicha(a); // Devuelve el valor de la ficha (Ver declaracion de esFicha)
        }}}
    }}}
    return 0; // Si aun no devolvio algo es por que nada fue verdadero, enonces devuelve 0.
}

int main()
{
    int valido = 0; // Para el chequeo de que la fila y columna introducida en un momento es valido.
    int continuar = 1; // Continuar: Si el codigo va a continuar.
    char turno = j1Simbolo; // Turno: Cual es la ficha que juega en este turno.
    char grilla[3][3]; // Grilla del TaTeTi en blanco
    int fichas = 0; // Fichas en el tablero
    char ganador = '.'; // Ficha ganadora, si la hay
    int finDelJuego = 0; // Fin del juego?
    int ix = 0,iy = 0; // X e Y introducidos para futuras operaciones.
    int x = 0,y = 0; // X e Y para operaciones <for>.

    // Vamos a inicializar la grilla
    for (y=0; y<=2; y++) { // Para todas las filas
        for (x=0; x<=2; x++) { // Para todas las columnas
            grilla[y][x] = '.'; // Ponemos un punto
        }
    }

    while (continuar == 1) {
        printf("\n--------------------\n\n"); // Ponemos una linea para dividir los turnos

        for (y=0; y<=2; y++) { // Para todas las filas
            for (x=0; x<=2; x++) { // Para todas las columnas
                printf("%c", grilla[y][x] ); // Imprimir el caracter en cada casillero
            }
            printf("\n");
        }
        printf("\n");

        if (finDelJuego == 1) { // Si este es el fin del juego,
            continuar = 0; // Fin del juego! No continuar el bucle.
            printf("Fin del juego!\n");
            // Reviar condicion del juego.
            if (ganador != '.') { // Si tenemos un ganador...
                printf("El ganador es %c", ganador);
            }
            if (ganador == '.') { // Si NO tenemos un ganador...
                if (fichas >= 9) {
                    printf("Hubo un empate!");
                }
            }
        }

        if (finDelJuego == 0) {
            valido = 0;
            while (valido == 0) {
                printf("Turno de %c\n", turno);
                printf("Fila: ");scanf("%d",&iy);
                printf(" Col: ");scanf("%d",&ix);
                // Hay que revisar que ni fila ni columna esten fuera de los limites
                iy--;ix--; // Ya que los vectores de la grilla comprenden entre 0 y 2, vale la pena disminuir lo que se ingrese por 1
                valido = 1; // Marcamos que valido es 1 antes que nada, ahora revisamos:
                if (iy < 0) {printf("Fila no puede ser menor a 1! ");valido = 0;}
                if (iy > 2) {printf("Fila no puede ser mayor a 3! ");valido = 0;}
                if (ix < 0) {printf("Columna no puede ser menor a 1! ");valido = 0;}
                if (ix > 2) {printf("Columna no puede ser mayor a 3! ");valido = 0;}
                // Si hubo algun error, valido se vuelve 0 y comenzamos todo de nuevo.
                printf("\n");
            }

            if (valido == 1) { // redundante
                if (esFicha(grilla[iy][ix]) == 0) { // Si el casillero esta libre...
                    grilla[iy][ix] = turno;

                    int ganado = 0;

                    // Ahora revisamos que el jugador de este turno haya ganado
                    for(x=0; x<=2; x++) { // Para cada columna
                        if (mismaFicha(grilla[0][x], grilla[1][x], grilla[2][x])) ganado = 1;
                    }
                    for(y=0; y<=2; y++) { // Para cada fila
                        if (mismaFicha(grilla[y][0], grilla[y][1], grilla[y][2])) ganado = 1;
                    }
                    if (mismaFicha(grilla[0][0], grilla[1][1], grilla[2][2])) ganado = 1; // Diagonal <^ a V>
                    if (mismaFicha(grilla[2][0], grilla[1][1], grilla[0][2])) ganado = 1; // Diagonal ^> a <V

                    if (ganado == 1) {
                        ganador = turno;
                        finDelJuego = 1;
                    }
                    fichas++; // Se ha puesto una ficha. Incrementar el contador de fichas por 1
                    if (fichas >= 9) finDelJuego = 1; // Si hay 9 (o mas, por si acaso) fichas, terminar el juego

                    if (turno == j1Simbolo) {turno = j2Simbolo;} else {turno = j1Simbolo;} // Intercambiar simbolos del turno
                } else { // Si el casillero no estaba libre despues de todo...
                    printf("Casillero ocupado, eleji otro.\n");
                }

            } // Fin del if valido.
        } // Fin del if finDelJuego



    } // Fin del while continuar.







}

























// espacio en blanco por que me molesta que el codigo no este en el medio de la pantalla
