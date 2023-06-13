/*

 */

#ifndef CLASECILINDRO_H
#define CLASECILINDRO_H
#include "ClaseCirculo.h"

class ClaseCilindro : public ClaseCirculo {
public:
    void SetAltura(double altura);
    double GetAltura() const;
    double volumen(void);
    double area(void); //Area de la superficie
    void mostrarResultados(void);
private:
    double altura;
};

#endif /* CLASECILINDRO_H */

