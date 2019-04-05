#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int funcionSumar(int numA, int numB, int* pResultado)
{
    int resultado;
    resultado = numA + numB;
    *pResultado = resultado;
    return 0;
}
int funcionRestar(int numA, int numB, int* pResultado)
{
    int resultado;
    resultado = numA - numB;
    *pResultado = resultado;
    return 0;
}
int funcionDividir(int numA, int numB, float* pResultado, char* mensaje)
{
    int resultado;
    if(numB == 0){
        printf("%s",mensaje);
        return -1;
    } else {
    resultado = numA/numB;
    *pResultado = resultado;
    return 0;}
}
int funcionMultiplicar(int numA, int numB, int* pResultado)
{
    int resultado;
    resultado = numA * numB;
    *pResultado = resultado;
    return 0;
}
int utn_getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                fflush(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getInt(int *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atoi(buffer);
    return 0;
}
