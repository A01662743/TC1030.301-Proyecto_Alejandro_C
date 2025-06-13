#include <iostream>
#include "Electric.hpp"
using namespace std;

// Constructores
Electric::Electric(): Vehiculo(){
    energy = 0;
    max_energy = 0;
    energy_per_km = 0;
    motor = Motor();
}
Electric::Electric(string _marca, string _modelo, float _energy, float _max_energy, float _energy_per_km, string _corriente, string _design): Vehiculo(_marca, _modelo){
    energy = _energy;
    max_energy = _max_energy;
    energy_per_km = _energy_per_km;
    motor = Motor(_corriente, _design, 0);
}
//getters
float Electric::get_energy(){
    return energy;
}
float Electric::get_max_energy(){
    return max_energy;
}
float Electric::get_energy_per_km(){
    return energy_per_km;
}
Motor Electric::get_motor(){
    return motor;
}
//setters
void Electric::set_energy(float _energy){
    energy = _energy;
}
void Electric::set_max_energy(float _max_energy){
    max_energy = _max_energy;
}
void Electric::set_energy_per_km(float _energy_per_km){
    energy_per_km = _energy_per_km;
}
void Electric::set_motor(string _corriente, string _design){
    motor.set_combustible(_corriente);
    motor.set_design(_design);
    motor.set_cilindros(0);
}
//metodos sobreescritos por polimorfismo
void Electric::print(){
    vehiculo_print();
    cout << "   porcentaje de carga: " << energy << "%" << endl;
    cout << "   motor: " << motor.get_combustible() << " " << motor.get_design() << endl;
    cout << endl;
}

void Electric::restock(float percent){
    if (percent+energy > 100 || percent <= 0) {
        cout << "no es posible cargar al " << percent << "%" << endl;
    }
    else{
        energy = percent + energy;
        cout << energy << "% de pila";
    }
}

void Electric::stock_loss(float _km){
    if (_km == 0 || _km*energy_per_km > (energy/100)*max_energy){
        cout << "no se puede realizar el viaje con la energia actual" << endl;
    }
    else {
        ride(_km);
        energy = energy - ((_km*energy_per_km)/max_energy)*100;
        cout << endl << energy << "% de pila";
    }
}
