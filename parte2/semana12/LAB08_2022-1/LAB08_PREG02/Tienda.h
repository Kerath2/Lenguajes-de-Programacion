/*

 */

#ifndef TIENDA_H
#define TIENDA_H

#include "Cliente.h"
#include "Pedido.h"

class Tienda {
public:
  Tienda();
  Tienda(const Tienda &orig);
  virtual ~Tienda();
  void carga();
  void muestra();
  char devuelveCat(int dni);
  void actualiza(int stockmin);

private:
  Pedido lpedidos[200];
  Cliente lclientes[200];
};

#endif /* TIENDA_H */
