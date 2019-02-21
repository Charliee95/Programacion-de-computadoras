#include <stdio.h>
#include <stdlib.h>

int main(void){
    int arreglo[] = {1,23,17,4,-5,100,2,8};
    int *ptr;
    int i;

    ptr = &arreglo[0];

    for (i=0; i<8; i++){
        printf("%d\n", arreglo[i]);
        printf("%d\n",*(ptr+2));
    }
    return 0;
}
