#ifndef NADADOR_H_INCLUDED
#define NADADOR_H_INCLUDED
#define TAMANIO 3

struct nadadorEstructura;

typedef struct nadadorEstructura * Nadador;

Nadador crearNadador();

void mostrarNadador(Nadador n);

void mostrarNadadoresOrdenados(Nadador n);



#endif // NADADOR_H_INCLUDED
