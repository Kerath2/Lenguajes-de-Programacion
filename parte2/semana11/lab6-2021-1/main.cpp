//
//  main.cpp
//  lab6-2021-1
//
//  Created by gkerath on 31/05/23.
//

#include <cstdlib>
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistro.h"

using namespace std;


int main(){
    void *lista1, *lista2;

    creaLista(lista1,leenum,cmpnum,"RegistroDeFaltas1.csv");
    creaLista(lista2,leenum,cmpnum,"RegistroDeFaltas2.csv");
    unelista(lista1,lista2);
    imprimeLista(lista1,imprimenum,"Repnum.txt");

    return 0;
}
