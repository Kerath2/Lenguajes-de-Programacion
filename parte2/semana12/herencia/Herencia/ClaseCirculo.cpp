/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClaseCirculo.cpp
 * Author: gkerath
 * 
 * Created on June 12, 2023, 7:51 PM
 */

#include "ClaseCirculo.h"
#define PI 3.1416
#include <iostream>
#include <iomanip>

using namespace std;

void ClaseCirculo::SetRadio(double radio) {
    this->radio = radio;
}

double ClaseCirculo::GetRadio() const {
    return radio;
}

double ClaseCirculo::area(){
    return PI * radio*radio;
}

double ClaseCirculo::circunferencia(){
    return 2 * PI * radio;
}

void ClaseCirculo::mostrarResultados(){
    cout.precision(2);
    cout << fixed;
    cout << setw(20) <<"Radio: " << setw(10) << radio << endl;
    cout << setw(20) << "Area: " << setw(10) << area() << endl;
    cout << setw(20) << "Circuferencia:  " << setw(10) << circunferencia() << endl;
}