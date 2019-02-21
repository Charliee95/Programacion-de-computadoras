#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nadador.h"

struct nadadorEstructura {
    char nombre[20];
    char apellido[20];
    int numAtleta;
    int peso;
    int ranking;
    char mejorTiempo[20];
};

Nadador crearNadador(){
    struct nadadorEstructura * nadadorCreado = malloc(sizeof(struct nadadorEstructura));

    printf("Ingrese el nombre del nadador: ");
    gets(nadadorCreado->nombre);
    printf("Ingrese su apellido: ");
    gets(nadadorCreado->apellido);
    printf("Ingrese numero de atleta: ");
    scanf("%d",&nadadorCreado->numAtleta);
    printf("Ingrese su peso: ");
    scanf("%d",&nadadorCreado->peso);
    printf("Ingrese su ranking: ");
    scanf("%d",&nadadorCreado->ranking);
    fflush(stdin);
    printf("Ingrese el mejor tiempo: ");
    gets(nadadorCreado->mejorTiempo);

    return nadadorCreado;

}

void mostrarNadador(Nadador n){
    printf("Su nombre y apellido es: %s %s ",n->nombre,n->apellido);
    printf("Numero de atleta: %d",n->numAtleta);
    printf("Peso: %d",n->peso);
    printf("Ranking: %d",n->ranking);
    printf("Mejor tiempo: %s",n->mejorTiempo);
}

void mostrarNadadoresOrdenados(Nadador n) {
    struct nadadorEstructura * aux = malloc(sizeof(struct nadadorEstructura));
    int i,j;
    int num = TAMANIO;

    for(i=1; i<num; i++){
        for(j=0; j<num-i; j++){
            if(n[j]->ranking > n[j+1]->ranking){
                aux->ranking = n[j]->ranking;
                n[j]->ranking = n[j+1]->ranking;
                n[j+1]->ranking = aux->ranking;

                strcpy(aux->nombre, n[j]->nombre);
                strcpy(n[j]->nombre, n[j+1]->nombre);
                strcpy(n[j+1]->nombre, aux->nombre);

                strcpy(aux->apellido, n[j]->apellido);
                strcpy(n[j]->apellido, n[j+1]->apellido);
                strcpy(n[j+1]->apellido, aux->apellido);

                strcpy(aux->mejorTiempo, n[j]->mejorTiempo);
                strcpy(n[j]->mejorTiempo, n[j+1]->mejorTiempo);
                strcpy(n[j+1]->mejorTiempo, aux->mejorTiempo);

                aux->peso = n[j]->peso;
                n[j]->peso = n[j+1]->peso;
                n[j+1]->peso = aux->peso;

                aux->numAtleta = n[j]->numAtleta;
                n[j]->numAtleta = n[j+1]->numAtleta;
                n[j+1]->numAtleta = aux->numAtleta;
            }
        }
    }

    for(i=0; i<num; i++){
        printf("Su nombre y apellido es: %s %s ",n->nombre,n->apellido);
        printf("Numero de atleta: %d",n->numAtleta);
        printf("Peso: %d",n->peso);
        printf("Ranking: %d",n->ranking);
        printf("Mejor tiempo: %s",n->mejorTiempo);
    }

}
