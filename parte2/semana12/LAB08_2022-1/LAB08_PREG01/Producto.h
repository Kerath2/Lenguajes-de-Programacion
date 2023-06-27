/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: alulab14
 *
 * Created on 13 de junio de 2023, 10:31 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* cad);
    void GetNombre(char *cad) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    void cargaDatos(int cod);
private:
    int codprod;
    char *nombre;
    double precio;
    int stock;
};

#endif /* PRODUCTO_H */

