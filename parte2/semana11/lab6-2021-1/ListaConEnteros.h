//
//  ListaConEnteros.h
//  lab6-2021-1
//
//  Created by gkerath on 31/05/23.
//

#ifndef ListaConEnteros_h
#define ListaConEnteros_h
#include <fstream>
using namespace std;

void* leenum(ifstream &arch);
int cmpnum(const void *a , const void *b);
void imprimenum(ofstream &arch,const void *dat );
#endif /* ListaConEnteros_h */
