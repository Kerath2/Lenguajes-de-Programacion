/* 
 * File:   PedidoEventual.h
 * Author: cueva
 *
 * Created on 26 de junio de 2022, 08:00 PM
 */
#include <fstream>
#include "Pedido.h"

using namespace std;


#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H

class PedidoEventual: public Pedido {
public:
    PedidoEventual();
    PedidoEventual(const PedidoEventual& orig);
    virtual ~PedidoEventual();
    void lee(int,ifstream &);
    void imprime(ofstream &,double,double);
    void actualiza();
private:
    double flete;
};

#endif /* PEDIDOEVENTUAL_H */

