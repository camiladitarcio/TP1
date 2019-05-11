
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Empleado.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array Empleado Array of Empleado
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int Empleado_Inicializar(Empleado array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Inicializa 5 arrays con datos cargados para testear funcionalidad del programa
* \param array Empleado Array of Empleado
* \param size int Array length
* \return int Return 0
*
*/
//inicializar con valores cargados
void inicializarEmployeesConDatos(Empleado array[], int size)
{
    int id[5] = {1,2,3,4,5};
    char name[5][50] = {"Juan","Maria","Pedro","Susan","Luis"};
    char lastName[5][50] = {"Gonzales","Rodriguez","Xeller","Collins","Pedo"};
    int salary[5] = {1800,2500,2400,1000,2000};
    int sector[5] = {3,8,6,4,7};

    int i;
    for (i=0; i<5; i++)
    {
        array[i].idEmpleado = id[i];
        strcpy(array[i].nombre,name[i]);
        strcpy(array[i].apellido,lastName[i]);
        array[i].salario=salary[i];
        array[i].sector=sector[i];
        array[i].isEmpty = 0; // OCUPADO.
    }
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int Empleado_buscarEmpty(Empleado array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Empleado_buscarID(Empleado array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idEmpleado==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Empleado_buscarInt(Empleado array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].sector==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Empleado_buscarString(Empleado array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int Empleado_alta(Empleado array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Empleado_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idEmpleado=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre:","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nIngrese apellido:","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].apellido);
            utn_getSignedInt("\nIngrese sector:","\n-- ERROR --",1,2,1,9,1,&array[posicion].sector);
            utn_getSignedInt("\nIngrese salario:","\n-- ERROR --",1,6,1,99999,1,&array[posicion].salario);
            printf("\n ID: %d\n nombre: %s\n apellido: %s\n sector: %d\n salario: %d",
                   array[posicion].idEmpleado,array[posicion].nombre,array[posicion].apellido,array[posicion].sector,array[posicion].salario);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Empleado_baja(Empleado array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a dar de baja: ","\n-- ERROR --",1,sizeof(int),1,sizeArray,1,&id);
        if(Empleado_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Empleado_bajaValorRepetidoInt(Empleado array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idEmpleado==valorBuscado)
            {
                array[i].isEmpty=1;
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int Empleado_modificar(Empleado array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\n-- ERROR --",1,sizeof(int),1,sizeArray,1,&id);
        if(Empleado_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                 printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n sector: %d\n salario: %d",
                   posicion, array[posicion].idEmpleado,array[posicion].nombre,array[posicion].apellido,array[posicion].sector,array[posicion].salario);
                utn_getChar("\nModificar: A(Nombre) -- B(Apellido) -- C(Sector) -- D(Salario) -- S(salir)","\n-- ERROR --",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre: ","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'B': ;
                        utn_getTexto("\nIngrese nuevo apellido: ","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].apellido);
                        break;
                    case 'C':
                        utn_getUnsignedInt("\nIngrese nuevo sector: ","\n-- ERROR --",1,sizeof(int),1,1,1,&array[posicion].sector);
                        break;
                    case 'D':
                        utn_getUnsignedInt("\nIngrese nuevo salario: ","\n-- ERROR --",1,sizeof(int),0,1,1,&array[posicion].salario);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int Empleado_ordenarPorString(Empleado array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    int bufferInt;
    float bufferFloat;
    char bufferLongString[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombre);
            bufferId=array[i].idEmpleado;
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].sector;
            bufferFloat=array[i].salario;
            strcpy(bufferLongString,array[i].apellido);

            j = i - 1;
            while ((j >= 0) && (strcmp(bufferLongString,array[j].apellido)<0))
                {
                array[j + 1].idEmpleado=array[j].idEmpleado;
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].nombre,array[j].nombre);
                strcpy(array[j + 1].apellido,array[j].apellido);
                array[j + 1].sector=array[j].sector;
                array[j + 1].salario=array[j].salario;
                j--;
            }
                array[j + 1].idEmpleado=bufferId;
                array[j + 1].isEmpty=bufferIsEmpty;
                strcpy(array[j + 1].nombre,bufferString);
                strcpy(array[j + 1].apellido,bufferLongString);
                array[j + 1].sector=bufferInt;
                array[j + 1].salario=bufferFloat;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Empleado Array de Empleado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Empleado_listar(Empleado array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
        printf("\nID: %d \t nombre: %s \t apellido: %s \t sector: %d \t salario: %d",
                array[i].idEmpleado,array[i].nombre,array[i].apellido,array[i].sector,array[i].salario);
        }
        retorno=0;
    }
    return retorno;
}

int Empleado_Salarios(Empleado array[],int size)
{
    float promedio;
    int bufferSalario;
    int contador = 0;
    int acum;
    int overSalario = 0;
    int i;


    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==0)
        {
        bufferSalario = array[i].salario;
        acum = acum + bufferSalario;
        contador++;
    }
    }
    promedio = acum / contador;

    for(i=0;i<contador;i++)
    {
        bufferSalario = array[i].salario;
        if(bufferSalario>promedio)
        {
            overSalario++;
        }
    }
    if(overSalario > 0)
    {
        printf("\nCantidad de empleados que superan el promedio salario: %d",overSalario);
    }
    else
        {
           printf("\nNo se han encontrado empleados que superen el promedio salario");
        }

    printf("\n\n TOTAL SALARIOS: %d \t PROMEDIO: %2.f",acum,promedio);
    return 0;
}


