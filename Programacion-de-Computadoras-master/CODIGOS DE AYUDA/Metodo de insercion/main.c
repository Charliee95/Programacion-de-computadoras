#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5] = {4,8,2,6,1};
    int i,pos,aux;

    for(i=0;i<5;i++){
        pos=i;
        aux=a[i];
        while(pos>0 && aux<a[pos-1]){
            a[pos] = a[pos-1];
            pos--;
        }
        a[pos]=aux;
    }

    for(i=0; i<5;i++) {
        printf(" %d,",a[i]);
    }


    return 0;
}
