#ifndef CUENTA_H
#define CUENTA_H
#include "Cliente.h"
#include "Abono.h"
#include <string>
#include <iostream>
#define TAM 5
using namespace std;

class Cuenta
{
    public:
        Cuenta();
        Cuenta(int,Cliente*);
        virtual ~Cuenta();
        int getNumeroCuenta();
        void setNumeroCuenta(int);
        Cliente *getCliente();
        void setCliente(Cliente *cl);
        bool agregarAbono(Abono*);
        Abono **getLstAbonos();
        float getSaldo();
        int getContadorAbonos();

    protected:

    private:
        int numeroCuenta;
        Cliente *clien;
        Abono *lstAbono[TAM];
        float saldo;
        int contAbonos;

};

#endif // CUENTA_H
