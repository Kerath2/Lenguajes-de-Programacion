/*

 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H

#include "Lista.h"

class Promociones {
public:
  Promociones();
  Promociones(const Promociones &orig);
  virtual ~Promociones();
  void leepedidos();

private:
  Lista lpedidos;
};

#endif /* PROMOCIONES_H */
