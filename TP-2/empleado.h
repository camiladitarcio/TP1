

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define TEXT_SIZE 51

typedef struct
{
    int idEmpleado;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int sector;
    int salario;

}Empleado;


#endif // Empleado_H_INCLUDED
void inicializarEmployeesConDatos(Empleado array[], int size);
int Empleado_Salarios(Empleado array[],int size);
int Empleado_Inicializar(Empleado array[], int size);                                    //cambiar Empleado
int Empleado_buscarEmpty(Empleado array[], int size, int* posicion);                    //cambiar Empleado
int Empleado_buscarID(Empleado array[], int size, int valorBuscado, int* posicion);                    //cambiar Empleado
int Empleado_buscarInt(Empleado array[], int size, int valorBuscado, int* posicion);                    //cambiar Empleado
int Empleado_buscarString(Empleado array[], int size, char* valorBuscado, int* indice);                    //cambiar Empleado
int Empleado_alta(Empleado array[], int size, int* contadorID);                          //cambiar Empleado
int Empleado_baja(Empleado array[], int sizeArray);                                      //cambiar Empleado
int Empleado_bajaValorRepetidoInt(Empleado array[], int sizeArray, int valorBuscado);
int Empleado_modificar(Empleado array[], int sizeArray);                                //cambiar Empleado
int Empleado_ordenarPorString(Empleado array[],int size);                              //cambiar Empleado
int Empleado_listar(Empleado array[], int size);                      //cambiar Empleado

