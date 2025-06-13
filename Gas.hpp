#ifndef GAS
#define GAS

#include <iostream>
#include "Vehiculo.hpp"
#include "Motor.hpp"
using namespace std;

//clase Gas, hereda de Vehiculo
class Gas: public Vehiculo{
    //atributos
    private:
        float gas; // en litros
        int gas_max; // en litros
        float gas_per_km;
        Motor motor;
    //métodos
    public:
        // Constructores
        Gas();
        Gas(string _marca, string _modelo, float _gas, int _gas_max, float _gas_per_km, string _combustible, string _design, int _cilindros);
        //getters
        float get_gas();
        int get_gas_max();
        float get_gas_per_km();
        Motor get_motor();
        //setters
        void set_gas(float _gas);
        void set_gas_max(int _gas_max);
        void set_gas_per_km(float _gas_per_km);
        void set_motor(string _combustible, string _design, int _cilindros);
        //metodos sobreescritos por polimorfismo
        void print();
        /*
            print imprime la marca, modelo, kilómetros recorridos, cantidad de combustible, tipo de combustible y diseño del motor.
        */
        void restock(float liters);
        /*
            restock agrega combustible al vehículo si es posible.
            @param liters es la cantidad de combustible a agregar al vehículo.
        */
        void stock_loss(float _km);
        /*
            stock_loss reduce la cantidad de combustible del vehículo según los kilómetros recorridos.
            @param _km es la cantidad de kilómetros recorridos a agregar al vehículo.
        */
};

#endif //GAS
