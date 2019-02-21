#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[] = {-1,3,4,6,-11,23,17,4,-5,100,2,8};

    int *ptr;
    int i;
    ptr=&arreglo[0]; //EL PUNTERO APUNTA A LA POSICION DE MEMORIA DE LA POSICION 0 DEL ARRAY

    for(i=0; i<12; i++) {
        printf("%d ",*(ptr)); //IMPRIME EL VALOR ALMACENADO EN ESA POSICION DE MEMORIA
        ptr = ptr+1;
        printf("%d ",(ptr+1)); // IMPRIME LA SIGUIENTE POSICION DE MEMORIA DE CADA NUMERO
    }

    return 0;
}
