/*
 * Proyecto Vehiculos main
 * Alejandro Contreras Magallanes
 * A01662770
 *
 * Este es un proyecto que modela
 * una cochera que puede almacenar
 * vehículos de diferentes tipos:
 * eléctricos, a base de gasolina y ecológicos.
 * Permite agregar vehículos, añadir kilómetros recorridos
 * entre otros
 */

#include <iostream>
#include <typeinfo>
#include "Vehiculo.cpp"
#include "Cochera.cpp"
#include "Electric.cpp"
#include "Gas.cpp"
#include "Eco.cpp"
#include "Motor.cpp"

using namespace std;

int main() {
    int opcion;
    cout << "¿Cuantos vehiculos puede guardar tu cochera? ";
    cin >> opcion;
    cout << endl;
    while (opcion <= 0) {
        cout << "Ingrese una capacidad válida: " << endl;
        cin >> opcion;
        cout << endl;
    }
    Cochera* cochera = new Cochera(opcion);
    while (true){
        cout << endl << endl << "1 - vehiculo nuevo\n2 - añadir kilómetros a vehículo\n3 - recargar vehículo\n4 - eliminar vehíulo\n5 - Mostrar vehículos\n6 - Generar coches Demo\ncualquier otro número para finalizar el programa" << endl;
        cin >> opcion;

        //agregar vehiculo
        if (opcion == 1){
            //verificar que la cochera no esté llena
            if (cochera -> get_nvehiculos() >= cochera -> get_capacidad()){
                cout << endl << "La cochera está llena, no se pueden agregar más vehículos" << endl;
                continue;
            }
            //variables
            string marca_;
            string modelo_;
            float recurso;
            float energy;
            float max;
            float per_km;
            string combustible_;
            string design_;
            int cilindros_;
            //tipo de vehiculo
            cout << endl << "¿Qué tipo de vehículo quieres agregar?" << endl;
            cout << endl << "1 = Eléctrico\n2 = A base de gasolina\n3 = Ecológico" << endl;
            cin >> opcion;

            //agregar vehiculo tipo eléctrico
            if (opcion == 1){
                //marca
                cout << endl << "¿Cuál es la marca del vehículo eléctrico? ";
                cin >> marca_;
                //modelo
                cout << "¿Cual es el modelo? ";
                cin >> modelo_;
                // carga %
                cout <<"¿Cual es su porcentaje de carga actual? (omitir el simbolo '%') ";
                cin >> recurso;
                while (recurso > 100 || recurso < 0){
                    cout << "ingrese un valor valido: ";
                    cin >> recurso;
                }
                // caapcidad Wtts
                cout << "¿Cual es su capacidad máxima en Watts? ";
                cin >> max;
                while (max <= 0){
                    cout << "ingrese un valor válido: ";
                    cin >> max;
                }
                // energía por km
                cout << "¿Cuanta energia gasta por kilómetro en watts? ";
                cin >> per_km;
                while (per_km > max || per_km <= 0){
                    cout << "ingrese un valor válido: ";
                    cin >> per_km;
                }
                // tipo de corriente y diseño del motor
                cout << "¿Qué tipo de corriente usa? (seleccione 1 para AC o 2 para DC): ";
                int comb_val;
                cin >> comb_val;
                while (comb_val != 1 && comb_val != 2){
                    cout << "seleccione una opción válida: ";
                    cin >> comb_val;
                }
                int design_val;
                //AC
                if (comb_val == 1){
                    combustible_ = "AC";
                    cout << endl << "seleccione 1 si el motor es sincrónico o 2 si es asincrónico: ";
                    cin >> design_val;
                    while (design_val != 1 && design_val != 2){
                        cout << "seleccione una opción válida: ";
                        cin >> design_val;
                    }
                    if (design_val == 1){
                        design_ = "sincrónico";
                    }
                    else{
                        design_ = "asincrónico";
                    }
                }
                //DC
                else{
                    combustible_ = "DC";
                    cout << endl << "seleccione 1 si el motor tiene escobillas o 2 si no: ";
                    cin >> design_val;
                    while (design_val != 1 && design_val != 2){
                        cout << "seleccione una opción válida: ";
                        cin >> design_val;
                    }
                    if (design_val == 1){
                        design_ = "con escobillas";
                    }
                    else{
                        design_ = "con escobillas";
                    }
                }

                //crear objeto eléctrico y añadir a cochera
                Electric* electric_1 = new Electric(marca_, modelo_, recurso, max, per_km, combustible_, design_);
                cochera -> addVehiculo(electric_1);
                electric_1 -> print();
            }

            //agregar vehiculo a abse de gasolina
            else if (opcion == 2){
                //marca
                cout << endl << "¿Cuál es la marca del vehículo a base de gasolina? ";
                cin >> marca_;
                //modelo
                cout << "¿Cual es el modelo? ";
                cin >> modelo_;
                // capacidad en L
                cout << "¿Cual es su capacidad máxima de gasolina en litros? ";
                cin >> max;
                while (max <= 0){
                    cout << "ingrese un valor válido: ";
                    cin >> max;
                }
                // tanque actual
                cout << "¿Cuantos litros de gasolina tiene actualmente? ";
                cin >> recurso;
                while (recurso > max || recurso < 0){
                    cout << "ingrese un valor válido: ";
                    cin >> recurso;
                }
                // gas por km
                cout << "¿Cuantos litros de gasolina gasta por kilómetro? ";
                cin >> per_km;
                while (per_km <= 0 || per_km > max){
                    cout << "ingrese un valor válido: ";
                    cin >> per_km;
                }
                // tipo de combustible
                cout << "¿Qué tipo de combustible usa? (seleccione 1 para gasolina o 2 para diésel): ";
                int comb_val;
                cin >> comb_val;
                while (comb_val != 1 && comb_val != 2){
                    cout << "seleccione una opción válida: ";
                    cin >> comb_val;
                }
                if (comb_val == 1){
                    combustible_ = "gasolina";
                }
                else{
                    combustible_ = "diésel";
                }
                // diseño del motor
                cout << endl << "¿Qué diseño de motor tiene?" << endl;
                cout << "1 - motor en linea"<< endl;
                cout << "2 - motor en V" << endl;
                cout << "3 - motor en W" << endl;
                cout << "4 - motor boxer" << endl;
                cout << "5 - motor radial" << endl;
                cout << "6 - motor rotativo" << endl;
                int design_val;
                cin >> design_val;
                while (design_val < 1 || design_val > 6){
                    cout << "seleccione una opción válida: ";
                    cin >> design_val;
                }
                if (design_val == 1){
                    design_ = "L";
                }
                else if (design_val == 2){
                    design_ = "V";
                }
                else if (design_val == 3){
                    design_ = "W";
                }
                else if (design_val == 4){
                    design_ = "H";
                }
                else if (design_val == 5){
                    design_ = "R";
                }
                else if (design_val == 6){
                    design_ = "motor rotativo";
                }
                // cilindros
                if (design_val == 6) {
                    cout << "Cuántos rotores tiene el motor? ";
                }
                else {
                    cout << endl << "¿Cuantos cilindros tiene el motor? ";
                }
                cin >> cilindros_;
                while (cilindros_ <= 0){
                    cout << "ingrese un valor válido: ";
                    cin >> cilindros_;
                }

                //crear objeto Gas y añadir a cochera
                Gas* gas_1 = new Gas(marca_, modelo_, recurso, max, per_km, combustible_, design_, cilindros_);
                cochera -> addVehiculo(gas_1);
                gas_1 -> print();
            }

            //agregar vehiculo tipo ecológico
            else if (opcion == 3){
                //marca
                cout << endl << "¿Cuál es la marca del vehiculo ecológico? ";
                cin >> marca_;
                //modelo
                cout << "¿Cual es el modelo? ";
                cin >> modelo_;

                //crear objeto Eco y añadir a cochera
                Eco* eco_1 = new Eco(marca_, modelo_);
                cochera -> addVehiculo(eco_1);
                eco_1 -> print();
            }
            else{
                cout << "opcion invalida" << endl;
            }
        }

        //añadir km a vehículo o recargar vehiculo
        else if (opcion == 2 || opcion == 3){
            //verificar que hayan vehículos
            if (cochera -> get_nvehiculos() == 0){
                cout << endl << "no hay vehiculos todavia" << endl;
            }
            //elegír vehiculo
            else {
                string _marca;
                string _modelo;
                cochera -> print();
                cout << "Marca del vehiculo: ";
                cin >> _marca;
                cout << "Modelo del vehiculo: ";
                cin >> _modelo;
                //buscar vehiculo
                int index = cochera -> buscar_por_nombre(_marca, _modelo);
                //verificar que exista
                if (index == -1){
                    cout << endl << "Vehiculo no encontrado";
                }
                else{
                    Vehiculo* vehiculo = cochera -> get_vehiculos()[index];
                    //opción para agregar km
                    if (opcion == 2){
                        float _km;
                        cout << endl << "¿Cuántos kilómetros recorriste? ";
                        cin >> _km;
                        vehiculo -> stock_loss(_km);
                    }
                    //opcion para recargar
                    else{
                        float _r;
                        cout << endl << "¿A que porcentaje recargaste el vehículo o cuántos litros de gasolina añadiste?";
                        cin >> _r;
                        vehiculo -> restock(_r);
                    }
                }
            }
        }

        //eliminar coche
        else if (opcion == 4){
            //verificar que hayan vehículos
            if (cochera -> get_nvehiculos() == 0){
                cout << "no hay vehiculos todavia" << endl;
            }
            //elegír vehiculo y eliminar
            else {
                string _marca;
                string _modelo;
                cochera -> print();
                cout << endl << "Marca del vehiculo que quieres eliminar: ";
                cin >> _marca;
                cout << "Modelo del vehiculo: ";
                cin >> _modelo;
                cochera -> eliminar(_marca, _modelo);
            }
        }

        //mostar vehiculos
        else if (opcion == 5){
            //verificarq ue hayan vehiculos
            if (cochera -> get_nvehiculos() == 0){
                cout << endl << "Aún no hay ningún vehículo" << endl;
            }
            //mostrar vehiculos
            else{
                cochera -> print();
            }
        }
        //agregar vehículos demo
        else if (opcion == 6){
            if (cochera -> get_nvehiculos() > 0){
                cout << endl << "No se pueden agregar vehículos de demostración, la cochera ya tiene vehículo(s)." << endl;
                continue;
            }
            else if (cochera -> get_capacidad() < 3){
                cout << endl << "No se pueden agregar vehículos de demostración, la cochera no tiene suficiente capacidad." << endl;
                continue;
            }
            else {
                //eléctrico
                Electric* electric_1 = new Electric("Tesla", "Model S", 80, 100, 0.2, "AC", "sincrónico");
                cochera -> addVehiculo(electric_1);
                //gasolina
                Gas* gas_1 = new Gas("Ford", "Mustang", 50, 60, 0.15, "gasolina", "V", 8);
                cochera -> addVehiculo(gas_1);
                //ecológico
                Eco* eco_1 = new Eco("Toyota", "Prius");
                cochera -> addVehiculo(eco_1);
                cout << endl << "Vehículos de demostración agregados." << endl;
                cochera -> print();
            }
        }
        //finalizar programa
        else {
            cout << endl << "------------ finalizando programa -----------" << endl;
            break;
        }
    }
    delete cochera; // Liberar memoria
    return 1;
}
