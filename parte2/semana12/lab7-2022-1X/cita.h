/*

 Gerardo Miguel Tacay Terrazos
 * codigo : 20193503
 */

#ifndef CITA_H
#define CITA_H
#include <fstream>
#include "medico.h"
using namespace std;
class cita {
public:
    cita();
    cita(const cita& orig);
    virtual ~cita();
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator<=(medico *arrmed);
    void LlenaTarifa(medico *arrMedicos);
private:
    int dni;
    int codigo;
    int fecha;
    double tarifa;
};

ifstream & operator >>(ifstream &arch, cita &cit);
#endif /* CITA_H */

