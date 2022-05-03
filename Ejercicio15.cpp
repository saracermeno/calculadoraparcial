#include <iostream>

using namespace std;

int main(){
    int multiplicacion, n;
    cout << "Escriba un numero para mostrar una tabla de multiplicaciones:" << endl;
    cin >> n;
    for (int i = 1; i <= 12; i++){
        multiplicacion = n * i;
        cout << n << "*" << i << " = " << multiplicacion << endl;
    }
    system("pause");
    return 0;
}