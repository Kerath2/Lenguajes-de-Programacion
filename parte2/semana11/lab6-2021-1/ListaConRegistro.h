//
//  ListaConRegistro.h
//  lab6-2021-1
//
//  Created by gkerath on 31/05/23.
//

#ifndef ListaConRegistro_h
#define ListaConRegistro_h
#include <fstream>
using namespace std;

void* leeregistro(ifstream &arch);
void leerCadena(ifstream &arch , char *&cad);
int cmpregistro(const void *a , const void *b);
#endif /* ListaConRegistro_h */
