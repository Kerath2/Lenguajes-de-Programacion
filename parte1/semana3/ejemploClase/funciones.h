#ifndef FUNCIONES
#include <fstream>
using namespace std;
void imprimeLinea(char car , int tamano, ofstream &reporte);
void imprimeCabecera(ofstream &reporte);
void separaNombres(char * cadena, char * nombreDoctor, char * especialidad, char * especialidadMayuscula);
void imprimeCabeceraPacientes(ofstream &reporte);
int compruebaVencido(int dd,int mm,int aa,int ddM,int mmM,int aaM);
#endif // !FUNCIONES

