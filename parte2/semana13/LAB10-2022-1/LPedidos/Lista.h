/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this
 * template
 */

/*
 * File:   Lista.h
 * Author: gkerath
 *
 * Created on June 21, 2023, 10:35 AM
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <fstream>
using namespace std;
class Lista {
public:
  Lista();
  Lista(const Lista &orig);
  virtual ~Lista();
  void inserta(ifstream &arch);

private:
  Nodo *lini;
  Nodo *lfin;
};

#endif /* LISTA_H */
