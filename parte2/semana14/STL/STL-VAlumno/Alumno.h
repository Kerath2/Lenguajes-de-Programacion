/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: cueva
 *
 * Created on 10 de junio de 2023, 08:23 PM
 */

#include <fstream>

using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(char* );
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void SetCreditos(double creditos);
    double GetCreditos() const;
    bool operator < (const Alumno&);
    bool operator > (const Alumno&);
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
};

#endif /* ALUMNO_H */

