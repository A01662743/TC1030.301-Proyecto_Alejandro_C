#include <iostream>
#include "Vehiculo.hpp"
using namespace std;

//constructores
Vehiculo::Vehiculo(){
    marca = "undefined";
    modelo = "undefined";
    km_recorridos = 0;
}
Vehiculo::Vehiculo (string _marca, string _modelo){
    marca = _marca;
    modelo = _modelo;
    km_recorridos = 0;
}
//getters
string Vehiculo::get_marca(){
    return marca;
}
string Vehiculo::get_modelo(){
    return modelo;
}
float Vehiculo::get_km_recorridos(){
    return km_recorridos;
}
//setters
void Vehiculo::set_marca(string _marca){
    marca = _marca;
}
void Vehiculo::set_modelo(string _modelo){
    modelo = _modelo;
}
void Vehiculo::set_km_recorridos(float _km_recorridos){
    km_recorridos = _km_recorridos;
}
//métodos especiales
void Vehiculo::ride (float km){
    km_recorridos = km + km_recorridos;
}
void Vehiculo::vehiculo_print(){
    cout << "   marca: " << marca << endl;
    cout << "   modelo: " << modelo << endl;
    cout << "   kilómetros recorridos: " << km_recorridos << " km" << endl;
}
