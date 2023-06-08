/*

 Gerardo Miguel Tacay Terrazos
 * codigo : 20193503
 */

#ifndef CITA_H
#define CITA_H

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
private:
    int dni;
    int codigo;
    int fecha;
    double tarifa;
};

#endif /* CITA_H */

