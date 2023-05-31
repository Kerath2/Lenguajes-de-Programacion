//
//  PilaConEnteros.h
//  Lab6-2022-2
//
//  Created by gkerath on 30/05/23.
//

#ifndef PilaConEnteros_h
#define PilaConEnteros_h
#include <fstream>
using namespace std;

void *leenumero(ifstream& arch);
int cmpnumero(const void *a, const void*b);
void imprimenumero(ofstream &arch,const void*a);
#endif /* PilaConEnteros_h */
