#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Ingrese un numero entero:" << endl;
    cin >> n;
    if (n % 2 == 0){
        if (n >= 0){
            cout << "El numero " << n << " es par y es un numero positivo." << endl;
        }
        else if (n < 0){
            cout << "El numero " << n << " es par y es un numero negativo." << endl;
        }
    }
    else if (n % 2 != 0){
        if (n >= 0){
            cout << "El numero " << n << " es impar y es un numero positivo." << endl;
        }
        else if (n < 0){
            cout << "El numero " << n << " es impar y es un numero negativo." << endl;
        }
    }
    system("pause");
    return 0;
}