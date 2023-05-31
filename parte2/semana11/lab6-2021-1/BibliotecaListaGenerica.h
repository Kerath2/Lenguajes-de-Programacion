//
//  BibliotecaListaGenerica.h
//  lab6-2021-1
//
//  Created by gkerath on 31/05/23.
//

#ifndef BibliotecaListaGenerica_h
#define BibliotecaListaGenerica_h

#include <fstream>
using namespace std;
void creaLista(void *&lista1,void * (*lee)(ifstream &),int (*cmp)(const void *, const void *),
               const char * nombreArch);
void construyeLista(void *&lista);
int listavacia(void*lista);
void insertaLista(void *lista,void * dato,int (*cmp)(const void *, const void *));
void imprimeLista(void *lista1, void (*imprime)(ofstream &,const void *),
                  const char * nombreArch);
void unelista(void *lista1,void *lista2);
#endif /* BibliotecaListaGenerica_h */
