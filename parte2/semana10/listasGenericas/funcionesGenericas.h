/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */

#ifndef FUNCIONESGENERICAS_H
#define FUNCIONESGENERICAS_H
#include <fstream>
using namespace std;
void crealista(void *&lista,void*(*lee)(ifstream&),int (*cmp)(void *, void*));
void construyeLista(void *&lista);
void insertarenLista(void *&lista,void *dato,int (*cmp)(void *, void*));
void imprimeLista(void *lista,void(*imprime)(ofstream&,void*));
#endif /* FUNCIONESGENERICAS_H */

