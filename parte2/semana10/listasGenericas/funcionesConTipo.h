/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */

#ifndef FUNCIONESCONTIPO_H
#define FUNCIONESCONTIPO_H
#include <fstream>
using namespace std;
void *leeentero(ifstream &arch);
void *leecadena(ifstream &arch);
void leerCadena(ifstream &arch, char *&cad);
int cmpentero(void *a , void*b);
int cmpcadena(void *a , void*b);
void imprimeEntero(ofstream &arch,void *nd);
void imprimeCadena(ofstream &arch,void *nd);
#endif /* FUNCIONESCONTIPO_H */

