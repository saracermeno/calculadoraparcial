#include <iostream>

using namespace std;

int main(){
    int deporte;
    cout << "Menu de deportes" << endl;
    cout << "1. Futbol." << endl;
    cout << "2. Basquetbol." << endl;
    cout << "3. Tenis" << endl;
    cout << "Ingrese el deporte que mas le interesa: " << endl;
    cin >> deporte;
    if (deporte >= 1 && deporte <= 3){
        cout << "Implementos necesarios" << endl;
        cout << "Si desea practicar " << endl;
    }
    switch (deporte){
    case 1:
        cout << "Futbol necesita un par de zapatos para grama y guantes si sera portero." << endl;
        break;
    case 2:
        cout << "Basquetbol necesita de zapatillas comodas y ropa holgada" << endl;
        break;
    case 3:
        cout << "Tenis necesita una raqueta resistente y muchas pelotas pequeñas que reboten" << endl;
        break;
    default:
        cout << "El numero ingresado no es valido" << endl;
        break;
    }
    system("pause");
    return 0;
}