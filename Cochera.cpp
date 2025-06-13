#include <iostream>
#include "Cochera.hpp"
using namespace std;

//constructores
Cochera::Cochera() {
    capacidad = 0;
}
Cochera::Cochera(int _capacidad) {
    capacidad = _capacidad;
    vehiculos = new Vehiculo* [capacidad];
}
//getters
int Cochera::get_capacidad() {
    return capacidad;
}
int Cochera::get_nvehiculos() {
    return nvehiculos;
}
Vehiculo** Cochera::get_vehiculos() {
    return vehiculos;
}
//métodos especiales
void Cochera::addVehiculo(Vehiculo* v) {
    if(nvehiculos < capacidad) {
        vehiculos[nvehiculos] = v;
        nvehiculos++;
        cout << endl << "Vehículo agregado a la cochera." << endl << endl;
    }
    else{
        cout << endl <<"No se puede agregar más vehículos, cochera llena." << endl << endl;
    }
}

int Cochera::buscar_por_nombre(string _marca, string _modelo){
    for(int i = 0; i < nvehiculos; i++){
        if (vehiculos[i] -> get_marca() == _marca){
            if (vehiculos[i] -> get_modelo() == _modelo){
                return(i);
            }
        }
    }
    return -1;
}

void Cochera::eliminar(string _marca, string _modelo){
    int i = buscar_por_nombre(_marca, _modelo);
    string text;
    if (i == -1){
        text = "elemento no encontrado";
    }
    else{
        nvehiculos = nvehiculos - 1;
        for (int j = i; j < nvehiculos; j++) {
            if (j == capacidad - 1) {
                vehiculos[j] = nullptr;
            }
            else{
            vehiculos[j] = vehiculos[j + 1];
            }
        }
        text = "elemento eliminado";
    }
    cout << endl << text << endl << endl;
}

void Cochera::print() {
    cout << endl << "Cochera con capacidad para " << capacidad << " vehículos." << endl;
    cout << "Número de vehículos en la cochera: " << nvehiculos << endl << endl;
    for(int i = 0; i < nvehiculos; i++) {
        cout << "Vehículo " << (i + 1) << ":" << endl;
        vehiculos[i]->print();
        cout << endl << endl;
    }
}
