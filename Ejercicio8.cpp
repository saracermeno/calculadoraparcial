#include <iostream>

using namespace std;

int main(){
    string producto;
    int cantidad;
    float preciototal;
    char origen;
    cout << "Solicitud de compra de producto" << endl;
    cout << "Ingrese el nombre del producto:" << endl;
    cin >> producto;
    cout << "Ingrese la cantidad existente:" << endl;
    cin >> cantidad;
    cout << "Ingrese el precio total: Q";
    cin >> preciototal;
    cout << "Ingrese el origen del producto, digite \'n\' si es nacional o \'e\' si es extranjero:" << endl;
    cin >> origen;
    if ((cantidad <= 100) && (origen == 'n')){
        cout << "A continuacion se hara una nueva orden de compra" << endl;
    }
    else if ((cantidad > 100) && (origen == 'n')){
        cout << "No se hara una orden de compra" << endl;
    }
    else{
        cout << "El caracter ingresado no es valido." << endl;
    }
    system("pause");
    return 0;
}