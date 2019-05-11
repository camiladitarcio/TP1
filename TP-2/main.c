#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"

#define QTY_TIPO 10

int main()
{
    int opcion;
    int contadorIdEmpleado=0;
    Empleado arrayEmpleado[QTY_TIPO];
    //int contadorIdEmpleado=5;
    //inicializarEmployeesConDatos(arrayEmpleado,QTY_TIPO); //INICIALIZA EMPLEADOS CON DATOS YA CARGADOS

    Empleado_Inicializar(arrayEmpleado,QTY_TIPO);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",
                      "\n-- ERROR --",1,sizeof(int),1,7,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                Empleado_alta(arrayEmpleado,QTY_TIPO,&contadorIdEmpleado);
                break;

            case 2: //Modificar
                Empleado_modificar(arrayEmpleado,QTY_TIPO);
                break;

            case 3: //Baja
                Empleado_baja(arrayEmpleado,QTY_TIPO);
                break;

            case 4://Listar
                Empleado_listar(arrayEmpleado,QTY_TIPO);
                Empleado_Salarios(arrayEmpleado,QTY_TIPO);
                break;

            case 5://Ordenar
                Empleado_ordenarPorString(arrayEmpleado,QTY_TIPO);
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
