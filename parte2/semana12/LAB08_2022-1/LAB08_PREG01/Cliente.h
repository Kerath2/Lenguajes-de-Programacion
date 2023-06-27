/*

 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
using namespace std;
class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetNombre(char* cad);
    void GetNombre(char * cad) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void leeCliente(ifstream &);
private:
    int dni;
    char categoria;
    char *nombre; 
};

#endif /* CLIENTE_H */

