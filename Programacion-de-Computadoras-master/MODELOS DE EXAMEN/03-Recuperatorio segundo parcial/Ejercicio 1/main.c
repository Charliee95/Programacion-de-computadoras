#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 5

struct Cliente {
    int DNI;
    char nombreYapellido[50];
}clientes[TAMANIO],aux;

int main() {
    int x, y;

    for(x=0; x<5; x++){
        printf("Ingrese el numero de dni: ");
        scanf("%d",&clientes[x].DNI);
        fflush(stdin);
        printf("Ingrese su nombre y apellido: ");
        gets(clientes[x].nombreYapellido);
        printf("\n");
    }

    OrdenarDNI(x,y);
    MostrarDNI(x);

    return 0;
}


void OrdenarDNI(x,y){
    int n= TAMANIO;

    for(x=1; x<n; x++) {
        for(y=0; y<n-x; y++) {
            if(clientes[y].DNI>clientes[y+1].DNI){
                aux.DNI= clientes[y].DNI;
                clientes[y].DNI= clientes[y+1].DNI;
                clientes[y+1].DNI= aux.DNI;

                strcpy(aux.nombreYapellido, clientes[y].nombreYapellido);
                strcpy(clientes[y].nombreYapellido, clientes[y+1].nombreYapellido);
                strcpy(clientes[y+1].nombreYapellido, aux.nombreYapellido);

            }
        }
    }
}

void MostrarDNI(x){

    for(x=0; x<TAMANIO; x++){
        printf(" %d",clientes[x].DNI);
        printf(" %s",clientes[x].nombreYapellido);
        printf("\n\n");
    }
}

