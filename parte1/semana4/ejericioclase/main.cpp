#include <iostream>
#include <iomanip>
#include "operators.h"
#include "alumno.h"
#include "regAlum.h"

using namespace std;

int main(){
  tregistro rnotas={{3,4,2,5,5},5};
  tregistro rcurva={{0,2,5,5,3},5};
  regalu lalumnos[100];
  cout << rnotas << endl;
  // cout << rnotas++ << endl;  
  cout << rcurva << endl;
  cout << rnotas+rcurva << endl;
  rnotas*2;
  
  cargaAlumnos("alumnos.txt",lalumnos);

  return 0;
}

