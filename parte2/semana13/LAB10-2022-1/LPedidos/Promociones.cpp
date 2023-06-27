/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this
 * template
 */

/*
 * File:   Promociones.cpp
 * Author: gkerath
 *
 * Created on June 21, 2023, 10:41 AM
 */

#include "Promociones.h"
#include <fstream>
#include <iostream>
using namespace std;

Promociones::Promociones() {}

Promociones::Promociones(const Promociones &orig) {}

Promociones::~Promociones() {}

void Promociones::leepedidos() {
  ifstream arch("pedidos5.csv", ios::in);
  if (!arch) {
    cout << "Erorr en la apertura del archivo " << endl;
    exit(1);
  }

  while (1) {
    lpedidos.inserta(arch);
    if (arch.eof())
      break;
  }
}
