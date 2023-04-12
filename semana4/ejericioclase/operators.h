#ifndef OPERATORS
#define OPERATORS
#include "alumno.h"
#include <iostream>
using namespace std;
double operator ++(tregistro &notas, int b);
ostream & operator<<(ostream &out,const tregistro &notas);
tregistro operator+(const tregistro &a,const tregistro&b);
void operator*(const tregistro &a, double factor);
#endif // !OPERATORS

