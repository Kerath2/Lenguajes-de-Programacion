#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;


void transferirInformacion(){
  int cod, anhoIngreso, codFac, codFac_curso,cod_backup;
  char codCurso[10] , car ;
  double numCreditos;
  int nota, dd , mm , aa;
  ifstream arch("./Alumnos-Cursos.txt",ios::in);
  if(!arch){
    cout << "Error en la apertura del archivo Alumnos-Cursos.txt" << endl;
    exit(1);
  }
  
  ofstream notasFinales("NotasFinales.bin",ios::out|ios::binary);
  if(!notasFinales){
    cout << "Error en la apertura del archivo notasFinales.bin " << endl;
    exit(1);
  }

  while(1){
    arch >> cod;
    if(arch.eof()) break;
    if (arch.fail()){
      arch.clear();
      arch >> codCurso >> codFac_curso >> numCreditos >> nota >> dd >> car >> mm >> car >> aa;
      if (aa > anhoIngreso){
        //llenmar notas en NotasFinales.bin
        llenar_notas_finales(notasFinales,cod_backup, anhoIngreso, codFac, codCurso , codFac_curso, numCreditos , nota, aa ,mm);
      }

    }else{
      arch >> car >> anhoIngreso >>  car >> codFac;
      cod_backup = cod;
    }
  }

}


void llenar_notas_finales(ofstream &notasFinales,int cod, int anhoIngreso, int codFac, char * codCurso , 
                          int  codFac_curso, double numCreditos , int nota, int aa ,int mm){
  int semestre;
  if (1 <= mm && mm <=2){
    semestre = 0;
  }else if (3 <= mm && mm <=7){
    semestre = 1;
  }else{
    semestre = 2;
  }
  notasFinales.write(reinterpret_cast<const char*>(&cod), sizeof(int));
  notasFinales.write(reinterpret_cast<const char*>(&anhoIngreso), sizeof(int));
  notasFinales.write(reinterpret_cast<const char*>(&codFac), sizeof(int));
  notasFinales.write(reinterpret_cast<const char*>(codCurso), sizeof(char)*10);
  notasFinales.write(reinterpret_cast<const char*>(&codFac_curso), sizeof(int));
  notasFinales.write(reinterpret_cast<const char*>(&numCreditos), sizeof(double));
  notasFinales.write(reinterpret_cast<const char*>(&nota), sizeof(int));
  notasFinales.write(reinterpret_cast<const char*>(&aa), sizeof(int));
  notasFinales.write(reinterpret_cast<const char*>(&semestre), sizeof(int));
}

void compruebaNotasFinalesBin(){
  int cod , anhoIngreso,codFac , codFac_curso, nota, aa , semestre ;
  char codCurso[10];
  double numCreditos;
  ifstream notasFinales("NotasFinales.bin",ios::in|ios::binary);
  if(!notasFinales){
    cout << "Error en la apertura del archivo notasFinales.bin " << endl;
    exit(1);
  }
  ofstream reporte("reporteNotasFin.txt", ios::out);
  if(!reporte){
    cout << "Error en la apertura del archivo reporteNotasFin.txt" << endl;
    exit(1);
  }
  while(1){
    notasFinales.read(reinterpret_cast<char*>(&cod), sizeof(int));
    if(notasFinales.eof()) break;
    notasFinales.read(reinterpret_cast<char*>(&anhoIngreso), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(&codFac), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(codCurso), sizeof(char)*10);
    notasFinales.read(reinterpret_cast<char*>(&codFac_curso), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(&numCreditos), sizeof(double));
    notasFinales.read(reinterpret_cast<char*>(&nota), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(&aa), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(&semestre), sizeof(int));


    reporte << setw(5) << cod << setw(10) << anhoIngreso << setw(10) << codFac << setw(15) << codCurso
      << setw(5) << codFac_curso << setw(5) << numCreditos << setw(5) << nota << setw(5) << aa << setw(5) <<
      semestre << endl;
  }
}

void transferir_segundo_archivo(){
  int cod, anho, codFac;
  char nombre[100] , especialidad[100], car;
  int totalCursos =0,ponderadoAprob=0, ponderadoDes = 0;
  double totalCreAprob = 0, totalCreDes = 0, promGeneralCurso = 0;
  double promCursosAprob=0;
  double relCredAproDes=0 ;
  ifstream arch("./alumnos.txt",ios::in);
  if(!arch){
    cout << "Error en la apertura del archivo alumnos.txt" << endl;
    exit(1);
  }
  ofstream alumBin("alumnos.bin",ios::out|ios::binary);
  if(!alumBin){
    cout << "Error en la apertura del archivo alumnos.bin" << endl;
    exit(1);
  }

  while(1){
    arch >> cod;
    if(arch.eof()) break;
    arch >> car >> anho >> car >>  codFac >> nombre >> especialidad;
    alumBin.write(reinterpret_cast<const char *>(&cod), sizeof(int));
    alumBin.write(reinterpret_cast<const char *>(&anho), sizeof(int));
    alumBin.write(reinterpret_cast<const char *>(&codFac), sizeof(int));
    alumBin.write(reinterpret_cast<const char *>(nombre), sizeof(char) * 100);
    alumBin.write(reinterpret_cast<const char *>(especialidad), sizeof(char) * 100);
    alumBin.write(reinterpret_cast<const char *>(&totalCursos),sizeof(int));
    alumBin.write(reinterpret_cast<const char *>(&totalCreAprob),sizeof(double));
    alumBin.write(reinterpret_cast<const char *>(&totalCreDes),sizeof(double));
    alumBin.write(reinterpret_cast<const char *>(&totalCreDes),sizeof(double));
    alumBin.write(reinterpret_cast<const char *>(&ponderadoAprob),sizeof(double));
    alumBin.write(reinterpret_cast<const char *>(&ponderadoDes),sizeof(double));
    alumBin.write(reinterpret_cast<const char *>(&promGeneralCurso),sizeof(double));
    alumBin.write(reinterpret_cast<const char *>(&promCursosAprob),sizeof(double));
    alumBin.write(reinterpret_cast<const char *>(&relCredAproDes),sizeof(double));
  }
}

void compruebaSegundoArchivo(){
  int cod , anho;
  char nombre[100], especialidad[100];
  int totalCursos, codFac;
  double totalCreAprob = 0, totalCreDes = 0, promGeneralCurso = 0;
  double promCursosAprob, ponderadoAprob =0 , ponderadoDes=0;
  double relCredAproDes=0 ;
  ifstream alumBin("alumnos.bin",ios::in|ios::binary);
  if(!alumBin){
    cout << "Error en la apertura del archivo alumnos.bin" << endl;
    exit(1);
  }
  fstream rep("reporteSeg.txt",ios::out);
  if(!rep){
    cout << "Error en la apertura del archivo reporteSeg.txt" << endl;
    exit(1);
  }

  while(1){

    alumBin.read(reinterpret_cast<char *>(&cod), sizeof(int));
    if (alumBin.eof()) break;
    alumBin.read(reinterpret_cast<char *>(&anho), sizeof(int));
    alumBin.read(reinterpret_cast<char *>(&codFac), sizeof(int));
    alumBin.read(reinterpret_cast<char *>(nombre), sizeof(char) * 100);
    alumBin.read(reinterpret_cast<char *>(especialidad), sizeof(char) * 100);
    alumBin.read(reinterpret_cast<char *>(&totalCursos),sizeof(int));
    alumBin.read(reinterpret_cast<char *>(&totalCreAprob),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&totalCreDes),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&totalCreDes),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&ponderadoAprob),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&ponderadoDes),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&promGeneralCurso),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&promCursosAprob),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&relCredAproDes),sizeof(double));

    rep << setw(5) << cod << setw(5) << anho << setw(5) << codFac << setw(30) << nombre
      << setw(30) << especialidad << setw(5) << totalCursos << setw(5) << totalCreAprob
      <<setw(5) << totalCreDes << setw(5) << ponderadoAprob << setw(5) << ponderadoDes 
    << setw(5) << promGeneralCurso << setw(5) << promCursosAprob << setw(5) << relCredAproDes << endl;
  }
}

void completaInfo(){
  int cod , anhoIngreso,codFac , codFac_curso, nota, aa , semestre ;
  char codCurso[10];
  double numCreditos;
  ifstream notasFinales("NotasFinales.bin",ios::in|ios::binary);
  if(!notasFinales){
    cout << "Error en la apertura del archivo notasFinales.bin " << endl;
    exit(1);
  }
  while(1){
    notasFinales.read(reinterpret_cast<char*>(&cod), sizeof(int));
    if(notasFinales.eof()) break;
    notasFinales.read(reinterpret_cast<char*>(&anhoIngreso), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(&codFac), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(codCurso), sizeof(char)*10);
    notasFinales.read(reinterpret_cast<char*>(&codFac_curso), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(&numCreditos), sizeof(double));
    notasFinales.read(reinterpret_cast<char*>(&nota), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(&aa), sizeof(int));
    notasFinales.read(reinterpret_cast<char*>(&semestre), sizeof(int));

    actualizaAlumno(cod, numCreditos,nota);
  }
}


void actualizaAlumno(int codC,double  numCreditos,int nota){
  int cod , anho;
  char nombre[100], especialidad[100];
  int totalCursos, codFac;
  double totalCreAprob = 0, totalCreDes = 0, promGeneralCurso = 0;
  double promCursosAprob, ponderadoAprob =0 , ponderadoDes=0;
  double relCredAproDes=0 ;
  fstream alumBin("alumnos.bin",ios::in|ios::out|ios::binary);
  if(!alumBin){
    cout << "Error en la apertura del archivo alumnos.bin" << endl;
    exit(1);
  }

  while(1){

    alumBin.read(reinterpret_cast<char *>(&cod), sizeof(int));
    if (alumBin.eof()) break;
    alumBin.read(reinterpret_cast<char *>(&anho), sizeof(int));
    alumBin.read(reinterpret_cast<char *>(&codFac), sizeof(int));
    alumBin.read(reinterpret_cast<char *>(nombre), sizeof(char) * 100);
    alumBin.read(reinterpret_cast<char *>(especialidad), sizeof(char) * 100);
    alumBin.read(reinterpret_cast<char *>(&totalCursos),sizeof(int));
    alumBin.read(reinterpret_cast<char *>(&totalCreAprob),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&totalCreDes),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&totalCreDes),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&ponderadoAprob),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&ponderadoDes),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&promGeneralCurso),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&promCursosAprob),sizeof(double));
    alumBin.read(reinterpret_cast<char *>(&relCredAproDes),sizeof(double));


    cout << setw(5) << cod << setw(5) << anho << setw(5) << codFac << setw(40) << nombre
    << setw(10) <<fixed  <<setprecision(2)<< promGeneralCurso << setw(10) << promCursosAprob << setw(10) << relCredAproDes << endl;

    if(codC == cod){
      //Actualizamos contadores
      promGeneralCurso = (promGeneralCurso + nota) / 2;
      if (nota>=11){
        ponderadoAprob = (totalCreAprob * ponderadoAprob + numCreditos * nota) / (totalCreAprob + numCreditos);
        promCursosAprob = (promCursosAprob + nota ) / 2;
        totalCreAprob += numCreditos; 
      }else{
        ponderadoDes= (totalCreDes* ponderadoDes + numCreditos * nota) / (totalCreDes+ numCreditos);
        totalCreDes += numCreditos;
      }
      totalCursos += 1;
      relCredAproDes = totalCreAprob / totalCreDes;
      //Retrocedemos espacios necesarios
      int mov=  (sizeof(int) * 1 + sizeof(double) * 8);
      mov*= -1;
      
      alumBin.seekg(mov,ios::cur);
      // Escribimos nuevamente
      alumBin.write(reinterpret_cast<const char *>(&totalCursos),sizeof(int));
      alumBin.write(reinterpret_cast<const char *>(&totalCreAprob),sizeof(double));
      alumBin.write(reinterpret_cast<const char *>(&totalCreDes),sizeof(double));
      alumBin.write(reinterpret_cast<const char *>(&totalCreDes),sizeof(double));
      alumBin.write(reinterpret_cast<const char *>(&ponderadoAprob),sizeof(double));
      alumBin.write(reinterpret_cast<const char *>(&ponderadoDes),sizeof(double));
      alumBin.write(reinterpret_cast<const char *>(&promGeneralCurso),sizeof(double));
      alumBin.write(reinterpret_cast<const char *>(&promCursosAprob),sizeof(double));
      alumBin.write(reinterpret_cast<const char *>(&relCredAproDes),sizeof(double));
      alumBin.flush();
    }
  }
}
 
