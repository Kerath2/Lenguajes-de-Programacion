/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: cueva
 *
 * Created on 6 de junio de 2022, 05:41 PM
 */
#include <fstream>


using namespace std;

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(char* );
    void GetNombre(char *) const;
    void SetTotal(double );
    double GetTotal() const;
    virtual void lee(int,ifstream &);
    virtual void imprime(ofstream &,double,double);
    virtual void actualiza()=0;
    
private:
    int codigo;
    char *nombre;
    int cantidad;
    double total;
    int dni;
    int fecha;
};


#endif /* PEDIDO_H */

