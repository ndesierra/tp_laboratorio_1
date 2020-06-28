#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char apellido[128];
    char posicion[128];
    float valor;
}Jugador;

Jugador* jugador_new();
Jugador* jugador_newParametros(char* id,char* apellido,char* posicion, char* valor);
void jugador_delete();

int jugador_setId(Jugador* this,int* id);
int jugador_getId(Jugador* this,int* id);

int jugador_setApellido(Jugador* this,char* apellido);
int jugador_getApellido(Jugador* this,char* apellido);

int jugador_setPosicion(Jugador* this,char* posicion);
int jugador_getPosicion(Jugador* this,char* posicion);

int jugador_setValor(Jugador* this,float* valor);
int jugador_getValor(Jugador* this,float* valor);

int mostrarJugador();
int mostrarJugadores(int* id, char* apellido, char* posicion, float* valor);

#endif // employee_H_INCLUDED
