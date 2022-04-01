#include <iostream>
#include <fstream>
#include "funcion factorial.h"

using namespace std;

int main(){
    float n;
    ofstream historial;
    historial.open("resultados.txt", ios::app);
    if (historial.fail()){
        cout << "No pudo crearse el archivo.";
    }
    else{
        cout << "Factorizacion de un numero" << endl;
        cout << "Escriba un numero: ";
        cin >> n;
        cout << "El resultado de la factorial es: " << factorial(n) << endl;
        historial << "La factorial de " << n << " es: " << factorial(n) << "\n";
    }
    cout << "Cerrando programa." << endl;
    historial.close();
    return 0;
}