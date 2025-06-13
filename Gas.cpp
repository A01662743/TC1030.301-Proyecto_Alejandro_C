#include <iostream>
#include "Gas.hpp"
using namespace std;

// Constructores
Gas::Gas(): Vehiculo(){
    gas = 0;
    gas_max = 0;
    gas_per_km = 0;
    motor = Motor();
}
Gas::Gas(string _marca, string _modelo, float _gas, int _gas_max, float _gas_per_km, string _combustible, string _design, int _cilindros): Vehiculo(_marca, _modelo){
    gas = _gas;
    gas_max = _gas_max;
    gas_per_km = _gas_per_km;
    motor = Motor(_combustible, _design, _cilindros);
}
//getters
float Gas::get_gas(){
    return gas;
}
int Gas::get_gas_max(){
    return gas_max;
}
float Gas::get_gas_per_km(){
    return gas_per_km;
}
Motor Gas::get_motor(){
    return motor;
}
//setters
void Gas::set_gas(float _gas){
    gas = _gas;
}
void Gas::set_gas_max(int _gas_max){
    gas_max = _gas_max;
}
void Gas::set_gas_per_km(float _gas_per_km){
    gas_per_km = _gas_per_km;
}
void Gas::set_motor(string _combustible, string _design, int _cilindros){
    motor.set_combustible(_combustible);
    motor.set_design(_design);
    motor.set_cilindros(_cilindros);
}
//metodos sobreescritos
void Gas::print(){
    vehiculo_print();
    cout << "   tanque: " << gas << " L" << endl;
    cout << "   tipo de combustible: " << motor.get_combustible() << endl;
    cout << "   motor: " << motor.get_design() << "-" << motor.get_cilindros() << endl;
    cout << endl;
}

void Gas::restock(float liters) {
    if (liters <= 0 || liters + gas > gas_max) {
        cout << "no es posible añadirle al tanque " << liters << " L" << endl;
    }
    else{
        gas = gas + liters;
        cout << "tu tanque contiene ahora " << gas << " L";
    }
}

void Gas::stock_loss(float _km) {
    if (_km == 0 || _km*gas_per_km > gas){
        cout << "no se puede realizar el viaje con la gasolina actual" << endl;
    }
    else{
        ride(_km);
        gas = gas - (_km*gas_per_km);
        cout << endl << "tu tanque contiene ahora " << gas << "L";
    }
}
