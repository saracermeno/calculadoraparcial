#include <iostream>

using namespace std;

int main(){
    int division, x, y = 1;
    cout << "Escriba un numero para mostrar una tabla de divisiones:" << endl;
    cin >> x;
    while (y <= 12)    {
        division = x / y;
        cout << x << "/" << y << " = " << division << " residuo: " << x % y << endl;
        y = y + 1;
    }
    system("pause");
    return 0;
}