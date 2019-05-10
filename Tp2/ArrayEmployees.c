#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ArrayEmployees.h"

void addEmployees(eEmployee lista[], int tam, eSector sectores[], int ts)
{
    int i, j;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        lista[i].id = numeroAleatorio(+1,+999,LIBRE);

        getStringLetras("\n Ingrese name: ", lista[i].name);

        getStringLetras(" Ingrese lastName: ", lista[i].lastName);

        printf(" Elija sector: ");
        for(j=0; j<ts; j++)
        {
            printf("\n %d.%s\n",sectores[j].idSector,sectores[j].sector);
        }
        scanf("%d", &lista[i].idSector);

        printf(" Ingrese salary: ");
        scanf("%f", &lista[i].salary);

        lista[i].isEmpty = OCUPADO;
    }
    else
    {
        printf("\n No hay espacio\n\n");
    }
}

void initEmployees(eEmployee lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = LIBRE;
    }
}

int buscarLibre(eEmployee lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int findEmployeeById(eEmployee lista[],int tam, eSector sectores[])
{
   int i;
   int loEncontro=0;
   int opcion;
   int id;

   for(i=0; i<tam; i++)
   {
      if(lista[i].isEmpty == OCUPADO)
       {
         printf("\n Ingrese ID: ");
         scanf("%d", &id);
       }
   }

   for(i=0; i<tam; i++)
   {
       if(id == lista[i].id)
       {
           opcion = menuDeOpciones("\n 1.name\n 2.lastName\n 3.salary\n 4.Sector\n 5.Volver al menu\n Ingrese opcion: ");
           switch(opcion)
           {
               case 1:
                   printf(" Ingrese nuevo name: ");
                   fflush(stdin);
                   gets(lista[i].name);

                   loEncontro = 1;
               break;
               case 2:
                   printf(" Ingrese nuevo lastName: ");
                   fflush(stdin);
                   gets(lista[i].lastName);

                   loEncontro = 1;
               break;
               case 3:
                   printf("\n Ingrese nuevo salary: ");
                   scanf("%f", &lista[i].salary);

                   loEncontro = 1;
               break;
               case 4:
                   printf(" Ingrese nuevo sector: ");
                   printf("\n%d.%s\n",sectores[i].idSector,sectores[i].sector);
                   scanf("%d", &lista[i].idSector);

                   loEncontro = 1;
               break;
               case 5:
                   system("cls");
                   loEncontro = 1;
               break;
               default:
                      printf("\n Opcion incorrecta \n");
                      system("cls");
               break;
           }
           system("cls");
           break;//modificar
       }
   }

   if(loEncontro==0)
   {
       system("cls");
       printf("\n El dato no existe\n");
   }

   return loEncontro;
}

int removeEmployee(eEmployee lista[], int tam)
{
    int i;
    int loEncontro=0;
    int id;

    for(i=0; i<tam; i++)
   {
      if(lista[i].isEmpty == OCUPADO)
       {
         printf("\n Ingrese ID: ");
         scanf("%d", &id);
       }else{
          break;
       }
   }

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].id)
        {
            system("cls");
            printf("\n Borrado completo\n");
            lista[i].isEmpty = LIBRE;
            loEncontro = 1;
            break;
        }
    }

    if(loEncontro==0)
   {
       printf("\n El dato no existe\n");
   }

   return loEncontro;
}

void hardcodearDatosEmpleados(eEmployee lista[], int tam)
{
    int i;
    int id[]={ 177 , 107 , 105 , 49 , 35 , 68 };
    char names[][50]={"Maria","Carlos","Jose","Camila","Marcelo","Martina"};
    char lastName[][50]={"Lopez","Diaz","Martinez","Gutierrez","Perez","Silva"};
    float salary[]={100,300,200,100,400,200};
    int sector[]={1,3,3,1,2,2};

    for(i=0; i<tam; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].name, names[i]);
        strcpy(lista[i].lastName, lastName[i]);
        lista[i].salary = salary[i];
        lista[i].isEmpty = OCUPADO;
        lista[i].idSector = sector[i];
    }
}

void mostrarEmpleado(eEmployee unEmpleado, eSector sectores[], int ts)
{
    char descripcionSector[20];
    int i;

    for(i=0; i<ts; i++)
    {
        if(unEmpleado.idSector == sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].sector);
            break;
        }
    }

    printf("\n%d - %s - %s - %f - %s\n\n", unEmpleado.id,unEmpleado.lastName, unEmpleado.name, unEmpleado.salary,descripcionSector);
}

void printEmployees(eEmployee lista[], int tam, eSector sectores[], int ts)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty!=LIBRE)
        {
            mostrarEmpleado(lista[i], sectores, ts);
        }
    }
}

char numeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

void sortEmployees(eEmployee lista[],int tam)
{
   int i,j;
   eEmployee auxiliar;

    for(i=0; i < tam - 1; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            continue;
        }
        for(j=i+1; j < tam; j++)
        {
            if(lista[j].isEmpty == LIBRE)
            {
                continue;
            }
            if(strcmp(lista[i].lastName,lista[j].lastName) > 0)
            {
                auxiliar = lista[j];
                lista[j] = lista[i];
                lista[i] = auxiliar;
            }
        }
    }
}

void mostrarEmpleadosPorSector(eSector sectores[], int ts, eEmployee empleados[], int te)
{
   int i,j;

  for(i=0; i<ts; i++)
  {
     if(empleados[i].isEmpty==LIBRE)
     {
         printf("\n No se ingresaron empleados");
         break;
     }else{
         continue;
     }
     for(i=0; i<ts; i++)
     {
       printf("%s: \n", sectores[i].sector);
       for(j=0; j<te; j++)
       {
           if(sectores[i].idSector==empleados[j].idSector)
           {
               sortEmployees(empleados,te);
               mostrarEmpleado(empleados[j],sectores,ts);
           }
       }
     }
  }
}

void mostrarPromedioSueldo(eEmployee empleado[], int tam)
{
   int i;
   float auxiliarPromedio;
   float auxiliarSueldo=0;
   int contadorEmpleados=0;

   for(i=0; i<tam; i++)
   {
      if(empleado[i].isEmpty == LIBRE)
        {
            break;
        }

         auxiliarSueldo = auxiliarSueldo + empleado[i].salary;
   }

   auxiliarPromedio = auxiliarSueldo / tam;

   for(i=0;i<tam;i++)
   {
       if(empleado[i].isEmpty == LIBRE)
        {
            break;
        }else if(empleado[i].salary > auxiliarPromedio)
       {
         contadorEmpleados++;
       }
   }
  printf(" El total de los sueldos es : %f, el promedio es: %f y la cantidad de empleados que lo superan son: %d\n",auxiliarSueldo,auxiliarPromedio,contadorEmpleados);
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

