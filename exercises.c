#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for(int k = 1; k <= 10; k++)
   {
      int *ptrNumero = malloc(sizeof(int));
      if(ptrNumero == NULL) exit(EXIT_FAILURE);

      *ptrNumero = k;

      pushBack(L, ptrNumero);
   }

   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {

   int suma = 0;
   int* elemento = (int*)(first(L));

   while(elemento)
   {
      suma += (*elemento);
      elemento = (int*)(next(L));
   }

   
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   
   int* elemento = (int*)(first(L));
   
   while(elemento)
   {
      if(*elemento == elem) popCurrent(L);
      elemento = (int*)(next(L));
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack * pila_aux = create_stack();

   while(top(P1))
   {
      push(pila_aux, top(P1));
      pop(P1);
   }

   while(top(pila_aux))
   {
      push(P1, top(pila_aux));
      push(P2, top(pila_aux));

      pop(pila_aux);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   
   int tallaString = strlen(cadena);
   if(tallaString % 2 != 0) return 0;
   
   Stack* pila = create_stack();

   for(int k = 0; k < tallaString; k++) push(pila, (cadena + k));

   int mitad = (tallaString / 2);

   for(int k = 0; k < mitad; k++)
   {
      char *caracter = top(pila);

      if(*(cadena + k) == '(')
      {
         if(*caracter != ')') return 0;
      }
      else if(*(cadena + k) == '{')
      {
         if(*caracter != '}') return 0;
      }
      else if(*(cadena + k) == '[') if(*caracter != ']') return 0;
      
      pop(pila);
   }


   //usar una pila para voltear cadena y luego comparar si son iguales, a medida que se elimina la lista creada
   return 1;
}

