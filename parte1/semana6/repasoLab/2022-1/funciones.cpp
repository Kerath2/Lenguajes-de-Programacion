#include <iostream>
#include <iomanip>
#include <fstream>
#include <fstream>
#include "operadores.h"
#include "funciones.h"

using namespace std;



void inicializa(Estructura_ClienteRegistrado * clientes,int tam ){
  for (int i = 0 ; i < tam ; i++){
    clientes[i].dni = 0;
  }
}
