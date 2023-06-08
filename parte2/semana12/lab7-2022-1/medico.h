/*
 Gerardo Miguel Tacay Terrazos
 * codigo : 20193503
 */

#ifndef MEDICO_H
#define MEDICO_H
#include <fstream>
using namespace std;
class medico {
public:
    medico();
    medico(const medico& orig);
    virtual ~medico();
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetNombre(char* cad);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    char * nombre;
    double tarifa;

};

ifstream & operator >>(ifstream &arch, medico med);

#endif /* MEDICO_H */

