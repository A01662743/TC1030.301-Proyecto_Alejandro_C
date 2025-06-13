#include <iostream>
#include "Motor.hpp"
using namespace std;

//constructores
Motor::Motor(){
    combustible = "undefined";
    design = "undefined";
    cilindros = 0;
}
Motor::Motor(string _combustible, string _design, int _cilindros){
    combustible = _combustible;
    design = _design;
    cilindros = _cilindros;
}
//getters
string Motor::get_combustible(){
    return combustible;
}
string Motor::get_design(){
    return design;
}
int Motor::get_cilindros(){
    return cilindros;
}
//setters
void Motor::set_combustible(string _combustible){
    combustible = _combustible;
}
void Motor::set_design(string _design){
    design = _design;
}
void Motor::set_cilindros(int _cilindros){
    cilindros = _cilindros;
}
