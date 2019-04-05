#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 100
#define MIN 0

int main()
{
    int numA;
    int numB;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int opcionMenu;

    printf("--- Menú de opciones ---\n\n");
    printf("--- 1) Ingresar el primer numero.\n");
    printf("--- 2) Ingresar el segundo numero.\n");
    printf("--- 3) Calcular.\n");
    printf("--- 4) Mostrar resultados.\n");
    printf("--- 4) Salir.\n\n");

    do {
    utn_getNumero(&opcionMenu,"Ingrese una opcion del menu: \n","\n --- Error, reingrese una opcion del menu: \n",1,5,3);

    switch(opcionMenu){
    case 1:
        utn_getNumero(&numA, "Primer numero:\n", "\n --- Error, reingrese el primer numero:\n", MIN,MAX,3);
        break;
    case 2:
        utn_getNumero(&numB, "Segundo numero:\n", "\n --- Error, reingrese el primer numero:\n", MIN,MAX,3);
        break;
    case 3:
        funcionSumar(numA, numB, &suma);
        funcionRestar(numA, numB, &resta);
        if(funcionDividir(numA, numB, &division, "\n --- WARNING. No es posible dividir por cero.\n")==-1){

        }
        funcionMultiplicar(numA, numB, &multiplicacion);
        printf(" \nCalculo realizado. Ingrese (4) para visualizar los resultados.\n");
        break;
    case 4:
        printf("\nPrimer Numero: %d\n Segundo Numero: %d\n",numA, numB);
        printf("El resultado de la suma es: %d\n", suma);
        printf("El resultado de la resta es: %d\n", resta);
        printf("El resultado de la multiplicacion es: %d\n", multiplicacion);
        printf("El resultado de la division es: %f\n", division);
        break;
    }

    } while(opcionMenu != 5);
    printf("\n ----- Gracias por participar ---- \n");
}
