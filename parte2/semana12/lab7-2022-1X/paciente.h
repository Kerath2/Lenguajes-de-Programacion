/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include "cita.h"
#include  <fstream>
using namespace std;
class paciente {
public:
    paciente();
    paciente(const paciente& orig);
    virtual ~paciente();
    void SetTotalGastado(double totalGastado);
    double GetTotalGastado() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(char* cad);
    void GetNombre(char *cad) const;
    void SetDni(int dni);
    int GetDni() const;
    int ultimaCita() const;
    void operator+=(cita &cit);
    void operator ++(int a);
private:
    int dni;
    char *nombre;
    cita lcitas[100];
    int telefono;
    double totalGastado;
};

ifstream & operator >>(ifstream &arch, paciente &pac);

#endif /* PACIENTE_H */

