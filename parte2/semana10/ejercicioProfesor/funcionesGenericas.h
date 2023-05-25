/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */

#ifndef FUNCIONESGENERICAS_H
#define FUNCIONESGENERICAS_H
#include <fstream>
using namespace std;
void crealista(void *&lista,void*(*lee)(ifstream&),int (*cmp)(void *, void*));

#endif /* FUNCIONESGENERICAS_H */

