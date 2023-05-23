#include <iostream>
#include <cstdlib>

using namespace std;

//nota deseada
void notadesa(int nota){
  cout << "La nota que yo merezco es : " << nota << endl;
}

void notacalificada(int nota){
  cout << "Pero sacaste : " << nota << endl;
}




int main(){
  //Crearemos punteritos void a estas funciones
  //Tiene que tener el mismo formato de las funciones a las que vamos a llamar
  void (*mensaje)(int); 
  mensaje = notadesa;  

  int nota = 20;
  mensaje(nota);
  mensaje = notacalificada;
  mensaje(nota);
  return 0;
}
