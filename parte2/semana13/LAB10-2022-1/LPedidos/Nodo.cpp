/*
 */

#include "Nodo.h"

Nodo::Nodo() {
  ped = nullptr;
  sig = nullptr;
  ant = nullptr;
}

Nodo::Nodo(const Nodo &orig) {}

Nodo::~Nodo() { delete ped; }

int Nodo::cmp(Nodo & nuevo){
    if (ped->GetDni() > nuevo.ped->GetDni())
        return 1;
    if( ped->GetDni() == nuevo.ped->GetDni()){
        if (ped->GetFecha() > nuevo.ped->GetFecha())
            return 1;
    }
    return 0;

}
