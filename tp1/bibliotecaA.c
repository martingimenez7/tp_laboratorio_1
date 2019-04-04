#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaA.h"

int suma(int a, int b)
{
  int total;

  total= a + b;
  printf(" El resultado de A+B es: %d\n",total);

  return total;
}

int resta(int a, int b)
{
    int total;

    total = a - b;
    printf(" El resultado de A-B es: %d\n",total);

    return total;
}

float division(int a, int b)
{
    int total;

    if(b==0){
        printf(" No es posible dividir por cero\n");

    }else{
         total = a / b;
         printf(" La division es: %d\n", total);
    }

    return total;
}

int multiplicacion(int a,int b)
{
    int total;

    total = a * b;
     printf(" El resultado de A*B: %d\n", total);

    return total;
}

int factorial(int a)
{
    int total;

    if(a<0){
        printf(" No es posible sacar fatorial de un numero negativo\n");
    }else if(a == 0 || a == 1){
        total = 1;
        printf(" \n El factorial de A es: %d\n", total);
    }else{
           total = a * factorial(a - 1);
           printf(" El factorial de A es: %d\n", total);
         }

    return total;
}
