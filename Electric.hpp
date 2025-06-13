#ifndef ELECTRIC
#define ELECTRIC

#include <iostream>
#include "Vehiculo.hpp"
#include "Motor.hpp"
using namespace std;

//clase Electric, hereda de Vehiculo
class Electric: public Vehiculo{
    //atributos
    private:
        float energy;
        float max_energy;
        float energy_per_km;
        Motor motor;
    //métodos
    public:
        // Constructores
        Electric();
        Electric(string _marca, string _modelo, float _energy, float _max_energy, float _energy_per_km, string _corriente, string _design);
        //getters
        float get_energy();
        float get_max_energy();
        float get_energy_per_km();
        Motor get_motor();
        //setters
        void set_energy(float _energy);
        void set_max_energy(float _max_energy);
        void set_energy_per_km(float _energy_per_km);
        void set_motor(string _corriente, string _design);
        //metodos sobreescritos por polimorfismo
        void print();       
        /*
            print imprime la marca, modelo, kilómetros recorridos, porcentaje de carga, tipo de corriente y diseño del motor.
        */
        void restock(float percent);      
        /*
            restock agrega energía al vehículo si es posible.
            @param percent es el porcentaje de energía a agregar al vehículo.
        */
        void stock_loss(float _km);
        /*
            stock_loss reduce la energía del vehículo según los kilómetros recorridos.
            @param _km es la cantidad de kilómetros recorridos a agregar al vehículo.
        */
};

#endif //ELECTRIC
