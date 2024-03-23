#ifndef ABONO_H
#define ABONO_H
#include "Fecha.h"
#include <iostream>
using namespace std;

class Abono
{
    public:
        Abono(Fecha*,float);
        virtual ~Abono();
        Fecha getFechaAbono();
        float getMontoAbono();
    protected:

    private:
        Fecha *fechaAbono;
        float montoAbono;
};

#endif // ABONO_H
