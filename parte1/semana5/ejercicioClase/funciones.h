#ifndef FUNCONES_H
#define FUNCONES_H
#include <fstream>
using namespace std;

void leerArchivos();
void inserta_medico(ofstream &med, char * codMed, char * medico);
void saca_especialidad(char * medico, char * esp);
void inserta_paciente(ofstream &pacBin,int dni,char * nombre);
void inserta_consulta(ofstream & cons,int dni,char  * codMed,int dd,int mm,int aa, int cantMed);
int verifica(int dni,char *cad);
void inserta_medicamento(ofstream &medBin,int codMedicamento,char * medicamento,double precio);
void inserta_consulta_med(ofstream &cons , int codMedicamento);
void imprimeArchivo();
void imprimirMedicos(ofstream &arch,ifstream &med);
#endif // !FUNCONES_H

