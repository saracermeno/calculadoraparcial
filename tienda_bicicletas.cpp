// Proyecto realizado por Saraí Cermeño 7490-20-13063 y Cristian Chajón 7490-20-7825

#include <iostream>
#include <conio.h>

using namespace std;

void menu_tienda();
void menu_bodega();
void bicicletas();

struct bicicleta
{
    bool vendida;
    int codigo;
    int estado;
    float precio;
    string color;
} bici[5];

int main()
{
    bici[0].codigo = 1;
    bici[0].color = "Negro";
    bici[0].vendida = 0;
    bici[0].estado = 1;
    bici[0].precio = 700.00;

    bici[1].codigo = 2;
    bici[1].color = "Rojo";
    bici[1].vendida = 1;
    bici[1].estado = 2;
    bici[1].precio = 500.00;

    bici[2].codigo = 3;
    bici[2].color = "Azul";
    bici[2].vendida = 0;
    bici[2].estado = 1;
    bici[2].precio = 1000.00;

    bici[3].codigo = 4;
    bici[3].color = "Verde";
    bici[3].vendida = 0;
    bici[3].estado = 2;
    bici[3].precio = 850.00;

    bici[4].codigo = 5;
    bici[4].color = "Amarillo";
    bici[4].vendida = 0;
    bici[4].estado = 1;
    bici[4].precio = 1500.00;

    menu_tienda();
    return 0;
}

void menu_tienda()
{
    int m;
    do
    {
        system("cls");
        cout << "\tMenu principal de \"El mundo de las bicis\"" << endl;
        cout << "1.- Desplegar lista de bicicletas disponibles." << endl;
        cout << "2.- Vender bicicleta." << endl;
        cout << "0.- Cerrar tienda." << endl;
        cout << "Ingrese la opcion que desea seguir:" << endl;
        cin >> m;
        if (m >= 1 && m <= 2)
        {
            system("cls");
        }
        switch (m)
        {
        case 0:
            cout << "Gracias por usar este programa, nos vemos en la proxima sesion." << endl;
            getch();
            exit(1);
            break;
        case 1:
            menu_bodega();
            break;
        case 2:
            bicicletas();
            break;
        default:
            cout << "El numero ingresado es invalido, intente de nuevo..." << endl;
            getch();
            break;
        }
    } while (m < 0 || m > 2);
    cout << "\nIngrese cualquier tecla para volver al menu de la tienda...";
    getch();
    menu_tienda();
}

void menu_bodega()
{
    cout << "\tBodega" << endl;
    cout << "A continuacion se despliega una lista del inventario existente." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "\n---------- Bicicleta No. " << i + 1 << " ----------" << endl;
        cout << "Vendida: ";
        if (bici[i].vendida == true)
        {
            cout << "Si" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        cout << "No. de registro: " << bici[i].codigo << endl;
        cout << "Color: " << bici[i].color << endl;
        cout << "Estado: ";
        if (bici[i].estado == 1)
        {
            cout << "Nueva" << endl;
        }
        else if (bici[i].estado == 2)
        {
            cout << "Usada" << endl;
        }
        cout << "Precio: Q" << bici[i].precio << " IVA incluido." << endl;
        cout << "-------------------------------------" << endl;
    }
}

void bicicletas()
{
    string estado;
    int x, menu[4], bici_disponible = 5;
    cout << "\tVenta de bicicleta" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (bici[i].vendida == false)
        {
            if (bici[i].estado == 1)
            {
                estado = "nueva";
            }
            else
            {
                estado = "usada";
            }
            cout << i + 1 << ". Bicicleta " << estado << " color " << bici[i].color << " a Q" << bici[i].precio << endl;
            menu[i] = i;
        }
        else if (bici[i].vendida == true)
        {
            bici_disponible--;
        }
    }
    if (bici_disponible == 0)
    {
        cout << "Lo sentimos. Se agotaron las bicicletas en venta." << endl;
    }
    else
    {
        do
        {
            cout << "Ingrese el numero de la bicicleta que desea comprar:" << endl;
            cin >> x;
            if (x - 1 == menu[0] || x - 1 == menu[1] || x - 1 == menu[2] || x - 1 == menu[3] || x - 1 == menu[4])
            {
                cout << "Se creara una orden de compra. Gracias por escoger \"El mundo de las bicis\" :)" << endl;
                bici[x - 1].vendida = true;
            }
            else
            {
                cout << "El numero ingresado no es valido, intente de nuevo." << endl;
            }
        } while (x - 1 != menu[0] && x - 1 != menu[1] && x - 1 != menu[2] && x - 1 != menu[3] && x - 1 != menu[4]);
    }
}