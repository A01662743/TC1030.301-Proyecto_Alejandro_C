#ifndef COCHERA
#define COCHERA

#include <iostream>
#include "Vehiculo.hpp"
using namespace std;

//clase Cochera, agrega Vehiculos
class Cochera {
    //atributos
    private:
        Vehiculo** vehiculos;
        int nvehiculos = 0;
        int capacidad;
    //métodos
    public:
        //constructores
        Cochera();
        Cochera(int _capacidad);
        //getters
        int get_capacidad();
        int get_nvehiculos();
        Vehiculo** get_vehiculos();
        //métodos especiales
        void addVehiculo(Vehiculo* v);
        /*
            addVehiculo agrega un vehículo a la cochera si hay espacio disponible.
            Si la cochera está llena, muestra un mensaje indicando que no se puede agregar más vehículos.
            @param v es un puntero al objeto Vehiculo que se desea agregar a la cochera.
        */
        int buscar_por_nombre(string _marca, string _modelo);
        /*
            buscar_por_nombre busca un vehículo por su marca y modelo.
            Si lo encuentra, devuelve el índice del vehículo en el arreglo; de lo contrario, devuelve -1.
            @param _marca es la marca del vehículo a buscar.
            @param _modelo es el modelo del vehículo a buscar.
            @return el índice del vehículo si se encuentra, o -1 si no se encuentra.
        */
        void eliminar(string _marca, string _modelo);
        /*
            eliminar elimina un vehículo de la cochera por su marca y modelo.
            Si lo encuentra, lo elimina y desplaza los vehículos restantes hacia la izquierda.
            Si no lo encuentra, muestra un mensaje indicando que el elemento no fue encontrado.
            @param _marca es la marca del vehículo a eliminar.
            @param _modelo es el modelo del vehículo a eliminar.
        */
        void print();
        /*
            print imprime la información de todos los vehículos en la cochera.
            Muestra la capacidad de la cochera, el número de vehículos y los detalles de cada vehículo.
        */

};

#endif //COCHERA
