#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

static int cont=1000;

/** \brief Genera el ID empleado de manera correlativa
 *
 * \param void
* \return int cont - numero de ID
 *
 */
int employee_generarId(void)
{
    cont++;
    return cont;
}

/** \brief Reserva un espacio de memoria para un nuevo empleado
 *
 * \param void
 * \return Devuelvo el espacio en memoria
 *
 */
Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

/** \brief Genera un nuevo empleado a traves de parametros solamente del tipo CHAR*
 *
 * \param char* ID empleado
 * \param char* NOMBRE empleado
 * \param char* HORAS empleado
 * \param char* SUELDO empleado
 * \return puntero a espacio de memoria donde esta ubicado el nuevo empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* p = employee_new();
    if(p!=NULL)
    {
        //printf("%s\n",idStr);
        if(employee_setIdString(p,idStr)==-1 ||
        employee_setNombre(p, nombreStr)==-1 ||
        employee_setHorasTrabajadasString(p,horasTrabajadasStr)==-1 ||
        employee_setSueldoString(p,sueldo)==-1)
        {
            employee_delete(p);
        }
    }
    return p;
}

/** \brief Genera un nuevo empleado a traves de parametros del tipo CHAR* y del tipo INT
 *
 * \param int ID empleado
 * \param char* NOMBRE empleado
 * \param int HORAS empleado
 * \param int SUELDO empleado
 * \return puntero a espacio de memoria donde esta ubicado el nuevo empleado
 *
 */
Employee* employee_newParametrosInt(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldo)
{
    Employee* p = employee_new();
    if(p!=NULL)
    {
       // printf("%s\n",idStr);
        if(employee_setId(p,idStr)==-1 ||
        employee_setNombre(p, nombreStr)==-1 ||
        employee_setHorasTrabajadas(p,horasTrabajadasStr)==-1 ||
        employee_setSueldo(p,sueldo)==-1)
        {
            employee_delete(p);
        }

    }
    return p;
}

/** \brief Libera el espacio de memoria donde esta ubicado un empleado - lo elimina
 *
 * \param Empleado a borrar
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Guarda ID de empleado del tipo INT
 *
 * \param puntero a empleado
 * \param int ID empleado
 * \return int (0) si logra guardar correctamente ID de empleado - (-1) ERROR
 */
int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


/** \brief Guarda ID de empleado del tipo CHAR*
 *
 * \param puntero a empleado
 * \param int ID empleado
 * \return int (0) si logra guardar correctamente ID de empleado - (-1) ERROR
 */
int employee_setIdString(Employee* this,char* id)
{
    int auxId;
    int retorno = -1;
    if(this != NULL && isValidNumber(id))
    {
        auxId = atoi(id);
       // printf("%d\n",auxId);
        this->id = auxId;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene ID de empleado
 *
 * \param puntero a empleado
 * \param int donde se guardará ID de empleado
 * \return int (0) si logra devolver correctamente ID de empleado - (-1) ERROR
 */
int employee_getId(Employee* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


/** \brief Guarda SUELDO de empleado de tipo INT
 *
 * \param puntero a empleado
 * \param int SUELDO empleado
 * \return int (0) si logra guardar correctamente SUELDO de empleado - (-1) ERROR
 */
int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda SUELDO de empleado de tipo CHAR*
 *
 * \param puntero a empleado
 * \param int SUELDO empleado
 * \return int (0) si logra guardar correctamente SUELDO de empleado - (-1) ERROR
 */
int employee_setSueldoString(Employee* this,char* sueldo)
{
    int auxSueldo;
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        auxSueldo=atoi(sueldo);
        this->sueldo = auxSueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene SUELDO de empleado
 *
 * \param puntero a empleado
 * \param int SUELDO empleado
 * \return int (0) si logra obtener correctamente SUELDO de empleado - (-1) ERROR
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda NOMBRE de empleado
 *
 * \param puntero a empleado
 * \param char* NOMBRE empleado
 * \return int (0) si logra guardar correctamente SUELDO de empleado - (-1) ERROR
 */
int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene NOMBRE de empleado
 *
 * \param puntero a empleado
 * \param char* NOMBRE empleado
 * \return int (0) si logra obtener correctamente SUELDO de empleado - (-1) ERROR
 */
int employee_getNombre(Employee* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda HORAS TRABAJADAS de empleado de tipo INT
 *
 * \param puntero a empleado
 * \param int HORAS TRABAJADAS empleado
 * \return int (0) si logra guardar correctamente HORAS TRABAJADAS de empleado - (-1) ERROR
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


/** \brief Guarda HORAS TRABAJADAS de empleado de tipo CHAR*
 *
 * \param puntero a empleado
 * \param char* HORAS TRABAJADAS empleado
 * \return int (0) si logra guardar correctamente HORAS TRABAJADAS de empleado - (-1) ERROR
 */
int employee_setHorasTrabajadasString(Employee* this,char* horasTrabajadas)
{
    int auxHorasTrabajadas;
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        auxHorasTrabajadas=atoi(horasTrabajadas);
        this->horasTrabajadas = auxHorasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


/** \brief Obtiene HORAS TRABAJADAS de empleado de tipo INT
 *
 * \param puntero a empleado
 * \param int guarda HORAS TRABAJADAS empleado
 * \return int (0) si logra obtener correctamente HORAS TRABAJADAS de empleado - (-1) ERROR
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


/** \brief Ordena empleado según su NOMBRE
 *
 * \param Nombre A
 * \param Nombre B
 * \return int (0) si no logra ordenar empleados - (1) Si logra ordenar de manera ascendente - (-1) si logra ordenar de manera descendente
 */
int employee_criterioNombre(void* thisA,void* thisB)
{
    char nombreA[128];
    char nombreB[128];
    int ret = 0;

    employee_getNombre((Employee*)thisA,nombreA);
    employee_getNombre((Employee*)thisB,nombreB);

        if(strcmp(nombreA,nombreB)>0)
        {
            ret = 1;
        }
        else if(strcmp(nombreA,nombreB)<0)
        {
            ret = -1;
        }
    return ret;
}
