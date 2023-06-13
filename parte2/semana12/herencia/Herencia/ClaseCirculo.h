/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClaseCirculo.h
 * Author: gkerath
 *
 * Created on June 12, 2023, 7:51 PM
 */

#ifndef CLASECIRCULO_H
#define CLASECIRCULO_H

class ClaseCirculo {
public:
    void SetRadio(double radio);
    double GetRadio() const;
    double area(void);
    double circunferencia(void);
    void mostrarResultados(void);
private:
    double radio;
};

#endif /* CLASECIRCULO_H */

