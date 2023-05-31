#include <fstream>
using namespace std;


void cargaArreglo(void *&arreglo,int (*comp)(const void*, const void* ),void *(*lee)(ifstream &),
              const char * nombreArch);
void * leenumero(ifstream & arch);
void cargaPila(void *&pila, void * arreglo);
void generapila(void *&pila);
int pilavacia(void*pila);
void push(void *pila, void *dato);
void * pop(void*pila);
void hanoi(int n,void *pilaini,void *pilaux,void *pilafin);
void * pop(void*pila);
void muevePila(void *pilaini,void *& pilafin);
