/*

 */

#ifndef TIENDA_H
#define TIENDA_H

#include "Pedido.h"
#include "Cliente.h"


class Tienda {
public:
    Tienda();
    Tienda(const Tienda& orig);
    virtual ~Tienda();
    void carga();
    void muestra();
private:
    Pedido lpedidos[200];
    Cliente lclientes[200];
};

#endif /* TIENDA_H */

