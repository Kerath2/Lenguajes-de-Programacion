/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medico.h
 * Author: gkerath
 *
 * Created on May 31, 2023, 11:51 AM
 */

#ifndef MEDICO_H
#define MEDICO_H

class medico {
public:
    medico();
    medico(const medico& orig);
    virtual ~medico();
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetNombre(char* nombre);
    char* GetNombre() const; //No se debe usar asi
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    char *nombre;
    double tarifa;
};

#endif /* MEDICO_H */

