#include "Cuenta.h"
#define TAM 5
Cuenta::Cuenta()
{
    numeroCuenta=0;
    saldo=0;
    contAbonos=0;
}
Cuenta::Cuenta(int nm, Cliente *cl){
    numeroCuenta=nm;
    clien=cl;
    saldo=0;
    contAbonos=0;
}
Cuenta::~Cuenta()
{
    //dtor
}
int Cuenta::getNumeroCuenta(){
    return numeroCuenta;
}
void Cuenta::setNumeroCuenta(int num){
    numeroCuenta=num;
}
Cliente* Cuenta::getCliente(){
    return clien;
}
void Cuenta::setCliente(Cliente *cli){
    clien=cli;
}
bool Cuenta::agregarAbono(Abono *abo) {
    bool retorno = false;
    if (contAbonos < TAM){
        lstAbono[contAbonos]=abo;
        contAbonos++;
        saldo += abo->getMontoAbono();
        retorno = true;
    }
    return retorno;
}
Abono** Cuenta::getLstAbonos() {
    return lstAbono;
}
float Cuenta::getSaldo(){
    return saldo;
}

int Cuenta::getContadorAbonos(){
    return contAbonos;
}
