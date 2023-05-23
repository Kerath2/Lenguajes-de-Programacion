#include <iostream>
#include <iomanip>
#include <cstring>

#include "metodoExacto.h"

using namespace std;

int main(){
  char **cli_nombre,*cli_categoria,**pro_Descripcion;
  int *cli_dni;
  cargaClientes(cli_dni,cli_nombre,cli_categoria);
  
  for (int i = 0 ; cli_dni[i] != -1;i++){
    cout <<setw(10) << cli_dni[i] << setw(40) << cli_nombre[i] <<  setw(5) << cli_categoria[i] << endl;
  }

  return 0;
}
