#include <iostream>

using namespace std;

int main(){
    int n, multiplo;
    cout << "Ingrese un numero entero:" << endl;
    cin >> n;
    multiplo = n % 4;
    if (multiplo == 0){
        cout << "El numero " << n << " es multiplo de 4." << endl;
    }
    else{
        cout << "El numero " << n << " no es multiplo de 4." << endl;
    }
    system("pause");
    return 0;
}