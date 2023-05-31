//
//  BibliotecaPilaGenerica.h
//  Lab6-2022-2
//
//  Created by gkerath on 30/05/23.
//

#ifndef BibliotecaPilaGenerica_h
#define BibliotecaPilaGenerica_h
#include <fstream>
using namespace std;

void cargaarreglo(void *&arreglo,int (*cmp)(const void *, const void*),
                  void *(*lee)(ifstream &),const char * nombreArch);
void cargapila(void *&pila,void *arreglo);
void construyePila(void *&pila);
int pilaVacia(void *pila);
void push(void *pila, void*dato);
void* pop(void*pila);
void muevepila(void *pilaini,void * pilafin);
void hanoi(int n,void  * origen,void *auxiliar,void *destino);
void imprimepila(void *pilafin,void (*imprime)(ofstream &,const void*),const char *nombreArch);
#endif /* BibliotecaPilaGenerica_h */
