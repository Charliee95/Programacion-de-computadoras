#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contVocales=0;
    int i=0;
    char dni[8];
    char anio[4];
    char nombre[20];

    printf("Introduzca su nombre: ");
    scanf("%s",nombre);
    printf ("Introduce tu dni: ");
    scanf("%s",dni);
    printf("Introduce tu fecha de nacimiento: ");
    scanf("%s",anio);
//--------------------------------------------------------------------------
    printf("Su patente es: ");
    while (contVocales < 2) { // cuento las primeras 2 vocales del nombre
        if(nombre[i]=='A') {
            printf("A");
            contVocales++;
        }
        if(nombre[i]=='E') {
            printf("E");
            contVocales++;
        }
        if(nombre[i]=='I') {
            printf("I");
            contVocales++;
        }
        if(nombre[i]=='O') {
            printf("O");
            contVocales++;
        }
        if(nombre[i]=='U') {
            printf("U");
            contVocales++;
        }
        i++;
    }
//-------------------------------------------------------------
    printf(" %c",dni[5]); // ultimos 3 numeros del dni
    printf("%c",dni[6]);
    printf("%c",dni[7]);
//-------------------------------------------------------------
    switch(anio[2]) {
        case '0': printf(" A");break;
        case '1': printf(" B");break;
        case '2': printf(" C");break;
        case '3': printf(" D");break;
        case '4': printf(" E");break;
        case '5': printf(" F");break;
        case '6': printf(" G");break;
        case '7': printf(" H");break;
        case '8': printf(" I");break;
        case '9': printf(" J");break;

    }

    switch(anio[3]) {
        case '0': printf("A");break;
        case '1': printf("B");break;
        case '2': printf("C");break;
        case '3': printf("D");break;
        case '4': printf("E");break;
        case '5': printf("F");break;
        case '6': printf("G");break;
        case '7': printf("H");break;
        case '8': printf("I");break;
        case '9': printf("J");break;

    }

    return 0;
}
