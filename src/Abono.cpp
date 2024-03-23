#include "Abono.h"

Abono::Abono(Fecha *fa,float ma)
{
    this->fechaAbono=fa;
    this->montoAbono=ma;
}
Abono::~Abono()
{
}
Fecha Abono::getFechaAbono(){
    return *fechaAbono;
}
float Abono::getMontoAbono(){
    return montoAbono;
}
