#include <iostream>
#include <stdlib.h>
#include <string>
#include "Abono.h"
#include "Fecha.h"
#include "Cliente.h"
#include "Cuenta.h"
#define MAX 5
using namespace std;
int menu() {
    int op;
    cout<< "*******MENU DE OPCIONES******" <<endl;
    cout<< "1. Agregar cliente a la lista_" <<endl;
    cout<< "2. Agregar cuenta a la lista_" <<endl;
    cout<< "3. Hacer abonos_" <<endl;
    cout<< "4. Mostrar lista de clientes_" <<endl;
    cout<< "5. Mostrar lista de cuentas_" <<endl;
    cout<< "6. Mostrar detalles de la cuenta_" <<endl;
    cout<< "7. SALIR_" <<endl;
    cout<< "Ingrese una opcion: ... ";
    cin >> op;

    return op;
}
Cliente *agregarCliente(){
    Cliente *clien;
    int id;
    string n,a;
    cout<<"Ingrese el id del cliente: "<<endl;
    cin>>id;
    cout<<"Ingrese el nombre del cliente: "<<endl;
    cin>>n;
    cout<<"Ingrese el apellido del cliente: "<<endl;
    cin>>a;
    clien = new Cliente(id, n, a);
    return clien;
}

Cliente *buscarCliente(Cliente *lstCli[],int contCli,int idCli){
    bool encontrar=false;
    int cont=0;
    Cliente *cli=NULL;
    while(cont<contCli&&!encontrar){
        if(lstCli[cont]->getIdCliente()==idCli){
           encontrar=true;
           cli=lstCli[cont];
        }else{
        cont++;
        }
    }
    return cli;
}
Cuenta *registrarCuenta(Cliente *clien){
    int numC;
    Cuenta *cuen;
    cout<<"Ingrese el numero de la cuenta :"<<endl;
    cin>>numC;
    cuen= new Cuenta(numC,clien);
    return cuen;
}
Cuenta *buscarCuenta(Cuenta *lstcuen[],int contc,int nCu){
   bool encontra=false;
   int contador=0;
   int cont=0;
   Cuenta *cuen=NULL;
   while(contador<contc && !encontra){
    if (lstcuen[contador]->getNumeroCuenta()==nCu){
        encontra=true;
        cuen=lstcuen[contador];
    }else{
        contador++;
    }
   }
   return cuen;
}
void hacerAbono(Cuenta *cuen){
    int d,m,a;
    Fecha *fechab;
    float ma;
    Abono *abon;
    cout<<"Ingrese la fecha del abono (dia\mes\anio): "<<endl;
    cin>>d;
    cin>>m;
    cin>>a;
    cout<<"Ingrese el monto del abono: "<<endl;
    cin>>ma;
    fechab = new Fecha(d,m,a);
    abon = new Abono(fechab, ma);
    cuen->agregarAbono(abon);
}
void mostrarDetalles(Cuenta lstc[],int contc,int idCue){
    bool encontrar = false;
    for (int i = 0; i < contc; i++) {
        if (lstc[i].getNumeroCuenta() ==idCue) {
            cout << "Numero de cuenta: " << lstc[i].getNumeroCuenta() << endl;
            cout << "Cliente: " << lstc[i].getCliente()->getNombre() << " " << lstc[i].getCliente()->getApellido() << endl;
            cout << "Saldo actual: " << lstc[i].getSaldo() << endl;
            cout << "Abonos realizados" << endl;
            Abono **abono = lstc[i].getLstAbonos();
            for (int p = 0; p < lstc[i].getContadorAbonos(); p++) {
                cout<<"Monto: "<<abono[p]->getMontoAbono()<<endl;
            }
            encontrar = true;
        }
    }
    if (!encontrar) {
        cout << "La cuenta no fue encontrada" << endl;
    }
}
int main()
{
    Cliente *lstCli[MAX];
    Cuenta  *lsCuentas[MAX];
    int opc, contCli = 0, contCuentas = 0, idCli=0, idCta=0;
    Cliente *cli= NULL;
    Cuenta *cta = NULL;
    do {
        system("cls");
        opc = menu();
        switch (opc) {
        case 1:
            if (contCli < MAX) {
                lstCli[contCli] = agregarCliente();
                contCli++;
                cout<<"El cliente se agrego correctamente"<<endl;
            } else {
                cout<<"La lista de clientes está llena"<<endl;
            }
            break;

        case 2:
            if (contCuentas < MAX) {
                cout<<"Ingrese el id del cliente: "<<endl;
                cin>>idCli;
                cli= buscarCliente(lstCli, contCli, idCli);
                if(cli){
                    lsCuentas[contCuentas] = registrarCuenta(cli);
                    contCuentas++;
                    cout<<"la cuenta se agrego con exito"<<endl;
                }
                else{
                    cout<<"el cliente no se encontro"<<endl;
                }
            }
            break;

        case 3:
            cout<<"Ingrese el numero de la cuenta"<<endl;
            cin>>idCta;
            cta = buscarCuenta(lsCuentas, contCuentas, idCta);
                if(cta){
                    hacerAbono(cta);
                    cout<<"El abono se agrego con exito"<<endl;
                }
                else{
                    cout<<"La cuenta no se encontro"<<endl;
                }
            break;
        case 4:
            if(contCli == 0)
                cout<<"la lista esta vacia"<<endl;
            else{
                cout<<"id \t Nombre\t apellido"<<endl;
                for(int i=0;i<contCli;i++){
                    cout<< lstCli[i]->getIdCliente()<<"\t";
                    cout<< lstCli[i]->getNombre()<<"\t";
                    cout<< lstCli[i]->getApellido()<<"\n";
                }
            }
            break;
        case 5:
                if(contCuentas == 0){
                    cout<<"La lista es vacia"<<endl;
                }else{
                    cout<<"No\t Cliente \t Saldo"<<endl;
                    for(int i=0; i<contCuentas; i++){
                        cout<< lsCuentas[i]->getNumeroCuenta()<<"\t";
                        cout<< lsCuentas[i]->getCliente()->getNombre()<<" "<< lsCuentas[i]->getCliente()->getApellido() <<"\t";
                        cout<< lsCuentas[i]->getSaldo()<<"\n";
                    }
                }
            break;
        case 6:
            cout<<"Ingrese el numero de la cuenta: "<<endl;
            cin>>idCta;
            cta = buscarCuenta(lsCuentas, contCuentas, idCta);
            if(cta){
                mostrarDetalles(*lsCuentas,contCuentas,idCta);
            }else{
                cout<<"la cuenta no se encontro"<<endl;
            }
            break;
        case 7:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opción Ingresada Invalida, Intente de nuevo" << endl;
            break;
        }
        system("pause");
    } while (opc != 7);
    return 0;
    }
