#include <iostream>

using namespace std;

void menu_principal();
void opciones(int &);
void calculo_edad();
void comparar_numeros();

int main(){
    menu_principal();
    return 0;
}

void menu_principal(){
    int p = 0;
    system("cls");
    cout << "Hola, que deseas hacer en este programa?" << endl;
    cout << "1. Calcular edad." << endl;
    cout << "2. Comparar dos numeros." << endl;
    cout << "3. Salir." << endl;
    cout << "Escriba la opcion a seguir: " << endl;
    cin >> p;
    while (((p != 1) && (p != 2)) && (p != 3)){
        cout << "El numero digitado es invalido, intente de nuevo... " << endl;
        system("pause");
        cout << "Escriba la opcion a seguir: " << endl;
        cin >> p;
    }
    opciones(p);
}

void opciones(int &m){
    switch (m){
    case 1:
        calculo_edad();
        break;
    case 2:
        comparar_numeros();
        break;
    case 3:
        cout << "Adios, gracias por usar este programa." << endl;
        system("pause");
        exit(1);
        break;
    }
    cout << "Escriba cualquier tecla para volver al menu principal... " << endl;
    system("pause");
    menu_principal();
}

void calculo_edad(){
    int an, aa;
    cout << "Calculo de edad" << endl;
    cout << "Escriba su anio de nacimiento: " << endl;
    cin >> an;
    cout << "Escriba el anio actual: " << endl;
    cin >> aa;
    cout << "Tiene la edad de " << aa - an << " anios." << endl;
}

void comparar_numeros(){
    int n1, n2;
    cout << "Comparacion de 2 numeros" << endl;
    cout << "Escriba el primer numero: " << endl;
    cin >> n1;
    cout << "Escriba el segundo numero: " << endl;
    cin >> n2;
    if (n1 > n2){
        cout << n1 << " es mayor que " << n2 << endl;
    }
    else if (n1 < n2){
        cout << n1 << " es menor que " << n2 << endl;
    }
    else{
        cout << "Son el mismo numero" << endl;
    }
}
