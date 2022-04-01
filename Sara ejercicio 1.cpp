#include <iostream>

using namespace std;

int main(){
    float pro, desc, pago = 4000.00, total;
    cout << "Pago de colegiatura" << endl;
    cout << "Escriba su promedio: ";
    cin >> pro;

    if (pro >= 96 && pro <= 100){
        desc = 30;
    }
    else if (pro >= 91 && pro <= 95){
        desc = 25;
    }
    else if (pro >= 86 && pro <= 90){
        desc = 20;
    }
    else if (pro >= 81 && pro <= 85){
        desc = 15;
    }
    else if (pro >= 76 && pro <= 80){
        desc = 10;
    }
    else if (pro >= 70 && pro <= 75){
        desc = 5;
    }
    else{
        desc = 0;
    }

    if (desc > 0){
        cout << "Felicidades, por su promedio obtiene un descuento del " << desc << "% en la colegiatura." << endl;
    }
    total = pago - ((pago * desc) / 100);
    cout << "El monto a pagar es de: Q" << total << endl;
    system("pause");
    return 0;
}