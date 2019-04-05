#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int funcionMultiplicar(int numA, int numB, int* pResultado);

int funcionDividir(int numA, int numB, float* pResultado, char* mensaje);

int funcionRestar(int numA, int numB, int* pResultado);

int funcionSumar(int numA, int numB, int* pResultado);

int utn_getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos);
/*Recibe la variable de tipo int *pResultado donde se guardara el numero.un const char* para el mensaje otro para el mensaje de error,
  tambien recibe int minimo y maximo para los limites de los valores aceptados. recibe la cantidad de reintentos de error, y devuelve
  0 si funciono -1 si no. */

int getInt(int *pResultado);
/*toma el ingreso por consola de un char* y lo transforma en int , lo guarda en la varible pRersultado. devuelve 0 si funciono y -1
  si no funciono*/

#endif // FUNCIONES_H_INCLUDED
