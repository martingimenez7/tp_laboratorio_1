#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaA.h"

int main()
{
  int a,b,opcion;

  do{

     printf("   CALCULADORA  \n 1.Calcular la suma \n 2.Calcular resta \n 3.Calcular division \n 4.Calcular multiplicacion \n 5.Calcular el factorial \n 6.Salir \n\n Introduzca una opcion: ");
     scanf("%d", & opcion);

     switch(opcion)
     {
       case 1:
            printf("\n Ingrese numero(A): ");
            scanf("%d",&a);
            printf(" Ingrese otro numero(B): ");
            scanf("%d",&b);
            suma(a,b);
       break;
       case 2:
            printf("\n Ingrese numero(A): ");
            scanf("%d",&a);
            printf(" Ingrese otro numero(B): ");
            scanf("%d",&b);
            resta(a,b);
       break;
       case 3:
            printf("\n Ingrese numero(A): ");
            scanf("%d",&a);
            printf(" Ingrese otro numero(B): ");
            scanf("%d",&b);
            division(a,b);
       break;
       case 4:
            printf("\n Ingrese numero(A): ");
            scanf("%d",&a);
            printf(" Ingrese otro numero(B): ");
            scanf("%d",&b);
            multiplicacion(a,b);
       break;
       case 5:
            printf("\n Ingrese numero(A): ");
            scanf("%d",&a);
            factorial(a);
       break;
       case 6:
            printf(" Saiendo...\n");
            return 7;
       break;

       default:
            printf(" Opcion no valida\n");
       break;
     }
   }while(opcion>=6);

    system("pause");
    system("cls");
}
