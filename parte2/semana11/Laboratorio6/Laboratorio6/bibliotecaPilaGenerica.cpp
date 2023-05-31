#include "bibliotecaPilaGenerica.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

void cargaArreglo(void *&arreglo,int (*comp)(const void*, const void* ),void *(*lee)(ifstream &),
              const char * nombreArch){
  ifstream arch(nombreArch,ios::in);
  if(!arch){
    cout << "Error en la apertura del archivo " << endl;
    exit(1);
  }

  void *buffer[200];
  void ** aux;
  int i = 0;
  while(1){
    buffer[i] = lee(arch);  
    if(buffer[i] == nullptr) break;
    i++;
  }
  
  aux = new void*[i+1];
  for (int j = 0 ; j <= i ; j++){
    aux[j] = buffer[i];
  } 

  qsort(aux,i,sizeof(void*),comp);

  arreglo = aux;
}


void cargaPila(void *&pila, void * arreglo){
  void **aux = (void**)arreglo;
  generapila(pila);
  int i = 0;
  while(aux[i]){
    push(pila,aux[i]);
    i++;
  }
}


void generapila(void *&pila){
  int *num;
  void **dupla = new void*[2];
  dupla[0] = nullptr;
  num = new int ;
  num = 0;
  dupla[1] = num;

  pila = dupla;
}

// No es necesario el ampersan en este caso
void push(void *pila, void *dato){
  void ** aux = (void**)pila;  
  void **nuevo = new void*[2];
  int * cont = (int*)(aux[1]);
  nuevo[0] = aux[0];
  nuevo[1] = dato;
  aux[0] = nuevo;
  (*cont)++;
}

int pilavacia(void*pila){
  void ** dupla = (void**)pila;
  if (dupla[0] == nullptr)
    return 1;
  return 0;
}

void * pop(void*pila){
  //tiene que devolver el dato
  void ** dupla = (void**)pila;
  void * dato = nullptr;
  if(!pilavacia(pila)){
    void **aux = (void**)(dupla[0]);
    dato = aux[1];

    dupla[0] = aux[0];
    int * cont = (int*)(dupla[1]);
    (*cont)--;
    delete aux;
  }

  return dato;
}


void muevePila(void *pilaini,void *& pilafin){
  void *pilaaux;  
  void ** dupla  = (void**)pilaini;
  generapila(pilafin);
  generapila(pilaaux);


  int *n = (int*)(dupla[1]);

  hanoi(*n,pilaini,pilaaux,pilafin);
}
  


void hanoi(int n,void *ini,void *aux,void *fin){
  void * dato;
  if (n == 1){
    dato = pop(ini);
    push(fin,dato);
    return;
  }
  hanoi(n-1,ini,fin,aux);
  dato = pop(ini);
  push(fin,dato);
  hanoi(n-1,aux,ini,fin);

}
