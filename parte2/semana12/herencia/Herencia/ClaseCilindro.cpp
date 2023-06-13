/*

 */

#include "ClaseCilindro.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ClaseCilindro::SetAltura(double altura) {
    this->altura = altura;
}

double ClaseCilindro::GetAltura() const {
    return altura;
}

double ClaseCilindro::volumen(){
    return ClaseCirculo::area() * altura;
}

double ClaseCilindro::area(){
    return 2 * ClaseCirculo::area() + circunferencia()*altura;  
}

void ClaseCilindro::mostrarResultados(){
    cout.precision(2);
    cout << fixed;
    cout << "Radio:          " << setw(10) << GetRadio() << endl;
    cout << "Altura:         " << setw(10) << altura << endl;
    cout << "Volumen:        " << setw(10) << volumen() << endl;
    cout << "Area de la sup: " << setw(10) << area() << endl;
    cout << "Area de la Base:" << setw(10) << ClaseCirculo::area() << endl;
    cout << "Circunferencia: " << setw(10) << circunferencia() << endl;
            
}

