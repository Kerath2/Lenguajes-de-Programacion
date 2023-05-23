#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void transferirInformacion();
void llenar_notas_finales(ofstream &notasFinales ,  int cod, int anhoIngreso, int codFac, char * codCurso , 
                          int  codFac_curso, double numCreditos , int nota, int aa ,int mm);
void compruebaNotasFinalesBin();
void transferir_segundo_archivo();
void compruebaSegundoArchivo();
void completaInfo();
void actualizaAlumno(int cod,double  numCreditos,int nota);
#endif // !FUNCIONES_H

