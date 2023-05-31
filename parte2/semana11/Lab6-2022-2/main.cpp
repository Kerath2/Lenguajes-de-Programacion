//
//  main.cpp
//  Lab6-2022-2
//
//  Created by gkerath on 30/05/23.
#include <iostream>
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

using namespace std;

int main(int argc, const char * argv[]) {
    void *arreglo, *pilaini, *pilafin;
    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimenumero,"repnumeros.txt");
    return 0;
    
}
