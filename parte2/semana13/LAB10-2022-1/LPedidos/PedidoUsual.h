/* 
 * File:   PedidoUsual.h
 * Author: cueva
 *
 * Created on 26 de junio de 2022, 08:00 PM
 */
#include <fstream>
#include "Pedido.h"

using namespace std;

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H

class PedidoUsual: public Pedido {
public:
    PedidoUsual();
    PedidoUsual(const PedidoUsual& orig);
    virtual ~PedidoUsual();
    void lee(int,ifstream &);
    void imprime(ofstream &,double,double);    
    void actualiza();
private:
    double descuento;
    double flete;
};

#endif /* PEDIDOUSUAL_H */

