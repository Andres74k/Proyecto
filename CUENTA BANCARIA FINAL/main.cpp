#include <iostream>
#include <string>

using namespace std;

#include "Cuenta.hpp"
#include "Estandard.hpp"
#include "Platino.hpp"
#include "Cajero.hpp"
#include "Banco.hpp"
//Casos de prueba al final.


//Estas funciones de menu son para que el usuario pueda escoger una opcion.
void menu_cuenta (){
    cout<<"1. Log in"<<endl;
    cout<<"2. Sign up"<<endl;
};

void menu_signup (){
    cout<<"1. Cuenta Estandard"<<endl;
    cout<<"2. Cuenta Premium"<<endl;
};


void menu_cliente (){
    cout<<"1. Depositar"<<endl;
    cout<<"2. Sacar Dinero"<<endl;
    cout<<"3. Ver saldo"<<endl;
    cout<<"4. Ver mi informacion"<<endl;
    cout<<"5 Log out"<<endl;
};


int main() {
    
    Banco banco;
    Cajero cajero; //Creamos los objetos que estaremos utilizando
    Cuenta cuenta;
    
    bool cont1 = true; //Esta variable esta hecha para que el programa continue y que los
                       //objetos no se esten redefiniendo.
    do{
    menu_cuenta();
    int opcion;
    int id;
    double dinero;
    
    
    cin >> opcion;
        
    if (opcion == 1){
        cout<<"\n"<<endl;
        
        cout<<"Introduce tu ID de cuenta"<<endl;
        cin >> id;                              //El id es el numero de posicion en la que esta
                                                //la cuenta que queremos acceder.
        cout<<"\n"<<endl;
        cuenta = banco.cambiar_cuenta(id);      //Cuando el usuario escoge "log in" creamos
                                                //un objeto tipo cuenta que es un copia de la
                                                //cuenta en la clase banco.
        
        if (cuenta.get_name() == ""){
            cout<<"Esa cuenta no existe"<<endl; //Aqui analizamos si la cuenta si existe viendo
            cout<<"\n"<<endl;                   //si tiene dueño.
        }
        else{
            bool cont2 = true;                  //Ya que se valoro que la cuenta si existe...
            do {                                //Le damos al usuario mas opciones
            cout<<"\n"<<endl;                   //Y usamos otro ciclo while para mantener la
            menu_cliente();                     //cuenta
            
            cin >> opcion;
            
            if (opcion == 1){       // Opcion 1 es depositar que usa la funcion del cajero para
                cout<<"\n"<<endl;   //cambiar el saldo de la cuenta
                cout<<"Cuanto dinero vas a depositar"<<endl;
                cin >> dinero;
                cajero.depositar(cuenta, dinero);
                banco.update_cuenta(cuenta, id); //Ya que tenemos nuestro saldo nuevo,
                                                 //le mandamos al banco los cambios de la cuenta
                cout<<"\n"<<endl;
                cout<<"Tu saldo es: "<<cuenta.get_saldo()<<endl;
                cout<<"\n"<<endl;
            }
            else if (opcion == 2){  //Opcion 2 es sacar dinero que funciona de una manera
                cout<<"\n"<<endl;   //similar a la opcion 1
                cout<<"Cuanto dinero vas a sacar"<<endl;
                cout<<"\n"<<endl;
                cout<<"Recuerda que en cuentas Estandard cobramos 10% de lo que retires"<<endl;
                cout<<"\n"<<endl;
                cin >> dinero;
                cajero.sacar_dinero(cuenta, dinero);
                banco.update_cuenta(cuenta, id);
                cout<<"Tu saldo es: "<<cuenta.get_saldo()<<endl;
                cout<<"\n"<<endl;
            }
            else if (opcion == 3){ //Opcion 3 es solo para ver el saldo de la cuenta
                cout<<"\n"<<endl;
                cout<<"Tu saldo es: "<<cuenta.get_saldo()<<endl;
                cout<<"\n"<<endl;
            }
            else if (opcion == 4){ //Opcion 4 es para ver todos los datos de la cuenta
                cout<<"ID: "<<cuenta.get_ID()<<endl;
                cout<<"Nombre: "<<cuenta.get_name()<<endl;
                cout<<"Localidad: "<<cuenta.get_loca()<<endl;
                cout<<"Saldo: "<<cuenta.get_saldo()<<endl;
                if (cuenta.check_des()== false)
                    cout<<"Cuenta: Estandard"<<endl;
                else
                    cout<<"Cuenta: Platino"<<endl;
            }
            else if (opcion == 5){ //Opcion 5 es Log out que nos saca del ciclo while
                cont2 = false;
                cout<<"\n"<<endl;
            }
            else
                cout<<"Opcion no existe"<<endl;
            }while (cont2==true);
        }
    }
        
    else if (opcion == 2){ //La opcion 2 es Sign up
        cout<<"\n"<<endl;
        int type;
        string n;
        string l;
        
        //Esta opcion te pide todos tus datos para mandarselos a la clase banco y que pueda
        //Crear una cuenta con esos datos que le diste.
        
        cout<<"Que tipo de cuenta quiere?"<<endl;
        cout<<"1. Estandard"<<endl;
        cout<<"2. Platino"<<endl;
        cin >> type;
        cout<<"\n"<<endl;
        
        cout<<"Introduce tu nombre: "<<endl;
        cin >> n;
        cout<<"\n"<<endl;
        
        cout<<"En donde vives?"<<endl;
        cin >> l;
        cout<<"\n"<<endl;
        
        if (type == 1){
            banco.agrega_cuenta_s(n, l);
            cout<<"Tu ID de acceso es: "<<banco.get_ID_cont()<<endl;
            cout<<"\n"<<endl;
        }
        else if(type == 2){
            banco.agrega_cuenta_p(n, l);
            cout<<"Tu ID de acceso es: "<<banco.get_ID_cont()<<endl;
            cout<<"\n"<<endl;
        }
        else{
            cout<<"El tipo de cuenta que escogiste no existe"<<endl;
            cout<<"\n"<<endl;
        }
    }
    else{
        cout<<"\n"<<endl;
        cout<<"Esa opcion no existe"<<endl;
        cout<<"\n"<<endl;
    }
    } while (cont1 == true);
    return 0;
}


//CASO DE PRUEBA
//
//cin 1
//cin 1
//Esa cuenta no existe
//
//cin 2
//cin 1
//cin "Andres"
//cin "Celaya"
//cout "Tu ID de acceso es: 1"
//
//cin 1
//cin 1
//cin 4
//cout ID: 1
//     Nombre: Andres
//     Localidad: Celaya
//     Saldo: 0
//     Cuenta: Estandard
//
//cin 5
//cin 2
//cin 2
//cin "Roberto"
//cin "Queretaro"
//cout "Tu ID de acceso es: 2"
//
//cin 1
//cin 2
//cin 1
//cin 1000
//cin 4
//cout ID: 2
//     Nombre: nombre
//     Localidad: lugar
//     Saldo: 1000
//     Cuenta: Platino



