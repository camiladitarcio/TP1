#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (0) si logra leer correctamente los datos de archivo - (-1) ERROR
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    Employee *pEmpleado;
    int ret = -1;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

            pEmpleado = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee,pEmpleado);
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (0) si logra leer correctamente los datos de archivo - (-1) ERROR
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee *pEmpleado;
    int bufferInt;
    int maxId=-1;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pEmpleado = employee_new();
            if(pEmpleado!=NULL && fread(pEmpleado,sizeof(Employee),1,pFile) && ll_add(pArrayListEmployee,pEmpleado)==0)
            {
                employee_getId(pEmpleado,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId = bufferInt;
                }
                ret = 0;
            }
            else
            {
                employee_delete(pEmpleado);
            }
        }
    }
    return ret;
}
