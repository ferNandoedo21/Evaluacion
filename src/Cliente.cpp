#include "Cliente.h"

Cliente::Cliente(int id,string n,string a)
{
    IdCliente=id;
    nombre=n;
    apellido=a;
}

Cliente::~Cliente()
{
    //dtor
}
int Cliente::getIdCliente(){
    return IdCliente;
}
string Cliente::getNombre(){
    return nombre;
}
string Cliente::getApellido(){
    return apellido;
}
