#include <iostream>

using namespace std;

int main(){
    int x;
    cout << "Calculo de promedio" << endl;
    cout << "Escriba el numero de notas a ingresar para calcular su promedio:" << endl;
    cin >> x;
    if (x < 1){
        cout << "El numero escrito no es valido." << endl;
    }
    else{
        float calificacion[x];
        for (int i = 1; i <= x; i++){
            cout << "Escriba la nota No. " << i << ":" << endl;
            cin >> calificacion[i];
        }
        calificacion[0] = 0;
        for (int j = 1; j <= x; j++){
            calificacion[0] += calificacion[j];
        }
        calificacion[0] /= x;
        cout << "Usted tiene el promedio de " << calificacion[0] << " puntos." << endl;
    }
    return 0;
}