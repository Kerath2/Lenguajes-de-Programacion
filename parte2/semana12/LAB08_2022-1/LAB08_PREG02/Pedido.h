/*

 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"
#include <fstream>
using namespace std;

class Pedido : public Producto {
public:
  Pedido();
  Pedido(const Pedido &orig);
  virtual ~Pedido();
  void SetObs(char *cad);
  void GetObs(char *cad) const;
  void SetTotal(double total);
  double GetTotal() const;
  void SetFecha(int fecha);
  int GetFecha() const;
  void SetDni(int dni);
  int GetDni() const;
  void SetCantidad(int cantidad);
  int GetCantidad() const;
  void SetCodigo(int codigo);
  int GetCodigo() const;
  void leePedido(ifstream &);
  void actualizaValores(int stockmin, char cat);

private:
  int codigo;
  int cantidad;
  int dni;
  int fecha;
  double total;
  char *obs;
};

#endif /* PEDIDO_H */
