#include <stdio.h>
#include <stdlib.h>
int cantLetra(char p[100],char l) {
    int contador = 0,i=0;
    for (i=0; i < 100; i++) {
        if (p[i] == l) {
            contador = contador + 1;
        }
    }
    return contador;
}

int main()
{
    char letra;
    char palabra[100];
    int repetidas=0;

    printf("Ingrese una letra: ");
    scanf("%c",&letra);
    fflush(stdin);
    printf("\nIngrese una palabra: ");
    gets(palabra);
    repetidas = cantLetra(palabra,letra);
    printf("%d",repetidas);
    return 0;
}


