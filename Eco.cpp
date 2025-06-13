#include <iostream>
#include "Eco.hpp"
using namespace std;

// Constructores
Eco::Eco(): Vehiculo(){
}
Eco::Eco(string _marca, string _modelo): Vehiculo(_marca, _modelo){
}
//metodos sobreescritos por polimorfismo
void Eco::print(){
    vehiculo_print(); 
    cout << endl;
}
void Eco::restock(float ignore) {
    cout << endl << "no se puede recargar para este tipo de vehículo" << endl;
}
void Eco::stock_loss(float _km) {
    ride(_km);
    cout << endl << "kilometros agregados";
}
