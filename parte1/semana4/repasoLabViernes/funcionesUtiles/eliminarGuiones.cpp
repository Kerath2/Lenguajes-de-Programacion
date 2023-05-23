#include <iostream>
#include <iomanip>

using namespace std;

void eliminarGuiones(char *cadena);

int main(){
  char nombre[100] = "GERARDO_MIGUEL_TACAY_TERRAZOS";
  eliminarGuiones(nombre);
  cout << nombre;

  return 0;
}

void eliminarGuiones(char *cadena){
  for (int i = 0 ; cadena[i]!='\0' ; i++){
    if(cadena[i] == '_')
      cadena[i] = ' ';
  }
}
