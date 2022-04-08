#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void calculadora();
void registrar_datos(int &, char &, int &, int &);
void lectura_datos();

int main()
{
    char x = 0;
    while (x != '3')
    {
        do
        {
            cout << " " << endl;
            cout << "Opciones" << endl;
            cout << "1. Utilizar la calculadora." << endl;
            cout << "2. Leer historial de operaciones." << endl;
            cout << "3. Salir del programa." << endl;
            cout << "Escriba la opcion a seguir:" << endl;
            cin >> x;
            if (((x != '1') && (x != '2')) && (x != '3'))
            {
                cerr << "El numero digitado es invalido, intente de nuevo." << endl;
            }
        } while (((x != '1') && (x != '2')) && (x != '3'));
        if (x == '1')
        {
            calculadora();
        }
        else if (x == '2')
        {
            lectura_datos();
        }
        else if (x == '3')
        {
            cout << "Usted saldra del programa." << endl;
        }
    }
    return 0;
}

void calculadora()
{
    int n[4] = {0, 0, 0, 0};
    char c = 0;
    do
    {
        system("cls");
        cout << "Calculadora" << endl;
        cout << "Escriba el primer numero: " << endl;
        cin >> n[0];
        cout << "Escriba el segundo numero: " << endl;
        cin >> n[1];
        if ((n[0] < 0) || (n[1] < 0))
        {
            cerr << "Por favor ingrese numeros positivos." << endl;
        }
    } while ((n[0] < 0) || (n[1] < 0));
    cout << "Operaciones disponibles" << endl;
    cout << "Suma (+)" << endl;
    cout << "Resta (-)" << endl;
    cout << "Multiplicacion (*)" << endl;
    cout << "Division (/)" << endl;
    cout << "Escriba el simbolo de la operacion a realizar:" << endl;
    cin >> c;
    switch (c)
    {
    case '+':
        n[2] = abs(n[0] + n[1]);
        break;
    case '-':
        if (n[0] < n[1])
        {
            do
            {
                cout << "El segundo numero es mayor que el primero. Solo mostrara el valor absoluto del resultado" << endl;
                cout << "1. Continuar." << endl;
                cout << "2. No continuar." << endl;
                cout << "Escriba la opcion a seguir: " << endl;
                cin >> n[3];
                if (n[3] == 2)
                {
                    cerr << "Sera enviado al menu de opciones." << endl;
                    system("pause");
                    return;
                }
            } while ((n[3] != 1) && (n[3] != 2));
        }
        n[2] = abs(n[0] - n[1]);
        break;
    case '*':
        n[2] = abs(n[0] * n[1]);
        break;
    case '/':
        if (n[1] == 0)
        {
            cout << "La operacion no es admitida, sera enviado al menu de opciones." << endl;
            system("pause");
        }
        else if (n[0] % n[1] != 0)
        {
            do
            {
                cout << "La division no sera exacta. Solo se mostrara el valor absoluto del cociente," << endl;
                cout << "No se mostrara el residuo. Desea continuar la operacion?" << endl;
                cout << "1. Continuar." << endl;
                cout << "2. No continuar." << endl;
                cout << "Escriba la opcion a seguir: " << endl;
                cin >> n[3];
                if (n[3] == 2)
                {
                    cerr << "Sera enviado al menu de opciones." << endl;
                    system("pause");
                    return;
                }
            } while ((n[3] != 1) && (n[3] != 2));
            n[2] = abs(n[0] / n[1]);
        }
        break;
    default:
        cout << "El simbolo digitado es invalido, sera enviado al menu de opciones." << endl;
        system("pause");
        break;
    }
    if ((((c == '+') || (c == '-')) || (c == '*')) || (c == '/'))
    {
        cout << "La operacion realizada es: " << abs(n[0]) << c << abs(n[1]) << "=" << abs(n[2]) << endl;
        registrar_datos(n[0], c, n[1], n[2]);
        system("pause");
    }
}

void registrar_datos(int &num1, char &s, int &num2, int &num3)
{
    char h = 0;
    ofstream registro;
    do
    {
        cout << "Desea registrar en el historial la operacion realizada? (s/n):" << endl;
        cin >> h;
        if ((h == 's') || (h == 'S'))
        {
            registro.open("Historial.txt", ios::app);
            if (registro.fail())
            {
                cout << "No se pudo crear el archivo." << endl;
                return;
            }
            registro << abs(num1) << s << abs(num2) << "=" << abs(num3) << "\n";
            registro.close();
            cout << "En el archivo Historial.txt puede encontrar todas las operaciones hechas en la calculadora" << endl;
        }
        else if ((h == 'n') || (h == 'N'))
        {
            cout << "No se guardaran los datos." << endl;
        }
        else
        {
            cout << "El caracter digitado es invalido, intente de nuevo." << endl;
        }
    } while ((((h != 's') && (h != 'S')) && (h != 'n')) && (h != 'N'));
}

void lectura_datos()
{
    system("cls");
    string dato;
    ifstream lectura;
    lectura.open("Historial.txt", ios::in);
    cout << "Lectura de datos" << endl;
    if (lectura.fail())
    {
        cout << "No se pudo abrir el archivo, probablemente fue eliminado el historial." << endl;
    }
    else
    {
        while (!lectura.eof())
        {
            getline(lectura, dato);
            cout << dato << endl;
        }
        cout << "Estas son las operaciones registradas en el historial." << endl;
    }
    lectura.close();
    system("pause");
}