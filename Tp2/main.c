#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define T 1000

int menuDeOpciones(char []);

int main()
{
   int opcion;

    eEmployee lista[T];
    initEmployees(lista,T);
    ///hardcodearDatosEmpleados(lista,6);
    eSector sectores[3] = {{1,"Contabilidad"},{2,"Sistemas"},{3, "RRHH"}};

    do
    {
        opcion = menuDeOpciones("\n 1.Alta\n 2.Baja\n 3.Modificar\n 4.Informar\n 5.Salir\n Elija una opcion: ");
        switch(opcion)
        {
            case 1:
                system("cls");
                addEmployees(lista, T, sectores, 3);
            break;
            case 2:
                removeEmployee(lista,T);
            break;
            case 3:
                system("cls");
                findEmployeeById(lista,T,sectores);
            break;
            case 4:
                  system("cls");
                  mostrarEmpleadosPorSector(sectores,3,lista,T);
                  mostrarPromedioSueldo(lista,T);
            break;
            case 5:
                system("cls");
                printf("\n Saliendo...\n ");
            break;
            default:
                system("cls");
                printf("\n Opcion incorrecta\n");
            break;
        }
    }while(opcion!=5);
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
