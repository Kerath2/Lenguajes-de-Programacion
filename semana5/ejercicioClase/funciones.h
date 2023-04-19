#ifndef FUNCONES_H
#define FUNCONES_H
#include <fstream>
using namespace std;

void leerArchivos();
void inserta_medico(ofstream &med, char * codMed, char * medico);
void saca_especialidad(char * medico, char * esp);
void inserta_paciente(ofstream &pacBin,int dni,char * nombre);
int verifica(int dni);
void inserta_consulta(ofstream & cons,int dni,char codMed,int dd,int mm,int aa, int cantMed);
#endif // !FUNCONES_H

