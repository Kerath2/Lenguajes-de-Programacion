#ifndef FUNCIONES_GENERICAS
#define FUNCIONES_GENERICAS
#include <fstream>
using namespace std;


void crealista(void *&lista,void*(*lee)(ifstream&),int (*cmp)(void *, void *));
void insertarlista(void *&lista,void *dato,int (*cmp)(void*, void*));
void construyeLista(void *&lista);

#endif // !FUNCIONES_GENERICAS

