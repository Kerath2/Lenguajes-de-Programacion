/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */

#ifndef FUNCIONESCONTIPO_H
#define FUNCIONESCONTIPO_H
#include <fstream>
using namespace std;
void *leeentero(ifstream &arch);
void leerCadena(ifstream &arch, char *&cad);
int cmpentero(void *a , void*b);

#endif /* FUNCIONESCONTIPO_H */

