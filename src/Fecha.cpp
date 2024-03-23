#include "Fecha.h"

Fecha::Fecha(int _dia,int _mes, int _anio)
{
    this->dia=_dia;
    this->mes=_mes;
    this->anio=_anio;
}
Fecha::~Fecha()
{
    //dtor
}

void Fecha::mostrarFecha(){
     cout << dia << "/" << mes << "/" << anio;

}
