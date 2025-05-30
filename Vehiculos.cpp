#include <iostream>
#include "Vehiculos2.hpp"

using namespace std;

int main() {
    // Create a vehicle object
    Vehiculo* electrico = new Electric("Tesla", "Model S", 100, 759014, 1518.028, "AC", "Synchronous");
    Vehiculo* gas = new Gas("Toyota", "pickup", 40, 70, 0.04, "diesel", "v", 8);
    Vehiculo* eco = new Eco("Mercurio", "EcoSport");

    // Print vehicle details
    electrico->print();
    cout << endl << "------------------------" << endl;
    gas->print();
    cout << endl << "------------------------" << endl;
    eco->print();
    
    // Clean up
    delete electrico;
    delete gas;
    delete eco;
    
    return 0;
}
