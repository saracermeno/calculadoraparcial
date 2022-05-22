#include <iostream>
#include <conio.h>

using namespace std;

void menu_principal();
void promedio();
void comparar_notas(int);
void agregar_nota();
void eliminar_nota();

struct alumno
{
    char nombre[15];
    int nota[4];
    bool registro;
} alumno[5];

int main()
{
    menu_principal();
    return 0;
}

void menu_principal()
{
    int m;
    system("cls");
    cout << "\tMenu principal" << endl;
    cout << "1. Promedio." << endl;
    cout << "2. Nota mas alta." << endl;
    cout << "3. Nota mas baja." << endl;
    cout << "4. Agregar notas." << endl;
    cout << "5. Eliminar notas." << endl;
    cout << "0. Salir del programa." << endl;
    cout << "Digite la opcion a seguir:" << endl;
    cin >> m;
    while ((((((m != 1) && (m != 2)) && (m != 3)) && (m != 4)) && (m != 5)) && (m != 0))
    {
        cout << "\aEl numero digitado es invalido, intente de nuevo... " << endl;
        cout << "Digite la opcion a seguir:" << endl;
        cin >> m;
    }
    switch (m)
    {
    case 0:
        cout << "Gracias por usar este programa." << endl;
        exit(1);
        break;
    case 1:
        promedio();
        break;
    case 2:
        comparar_notas(1);
        break;
    case 3:
        comparar_notas(2);
        break;
    case 4:
        agregar_nota();
        break;
    case 5:
        eliminar_nota();
        break;
    }
    cout << "\nIngrese cualquier tecla para volver al menu principal... ";
    getch();
    menu_principal();
}

void promedio()
{
    int clave;
    float promedio;
    cout << "\tPromedio" << endl;
    cout << "Digite la clave del alumno para calcular su promedio (1-5): ";
    cin.ignore();
    cin >> clave;
    if ((clave < 1) || (clave > 5))
    {
        cout << "El numero ingresado es invalido." << endl;
    }
    else if (alumno[clave].registro == false)
    {
        cout << "No hay notas registradas en esta clave." << endl;
    }
    else
    {
        for (int i = 1; i <= 4; i++)
        {
            promedio += alumno[clave].nota[i];
        }
        promedio /= 4;
        cout << "El promedio de " << alumno[clave].nombre << " es: " << promedio << " puntos." << endl;
    }
}

void comparar_notas(int x)
{
    int max = 0, min = 101, clave[1], nota[1];
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (alumno[i].registro == true)
            {
                if (alumno[i].nota[j] > max)
                {
                    max = alumno[i].nota[j];
                    clave[0] = i;
                    nota[0] = j;
                }
                if (alumno[i].nota[j] < min)
                {
                    min = alumno[i].nota[j];
                    clave[1] = i;
                    nota[1] = j;
                }
            }
        }
    }
    if (x == 1)
    {
        cout << "\tNota maxima" << endl;
        cout << alumno[clave[0]].nombre << " tiene la nota mas alta." << endl;
        cout << "Su puntuacion es: " << alumno[clave[0]].nota[nota[0]] << endl;
        cout << "Su calificacion es del bimestre " << nota[0] << endl;
    }
    else if (x == 2)
    {
        cout << "\tNota minima" << endl;
        cout << alumno[clave[1]].nombre << " tiene la nota mas baja." << endl;
        cout << "Su puntuacion es: " << alumno[clave[1]].nota[nota[1]] << endl;
        cout << "Su calificacion es del bimestre " << nota[1] << endl;
    }
}

void agregar_nota()
{
    int clave = 0;
    cout << "\tAgregar notas" << endl;
    cout << "Digite la clave del alumno para agregar sus notas (1-5):" << endl;
    cin >> clave;
    if ((clave < 1) || (clave > 5))
    {
        cout << "\aEl numero ingresado es invalido." << endl;
    }
    else if (alumno[clave].registro == true)
    {
        cout << "Para reemplazar los datos de un alumno primero debe eliminar sus notas." << endl;
    }
    else
    {
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        cin.getline(alumno[clave].nombre, 15, '\n');
        for (int i = 1; i <= 4; i++)
        {
            do
            {
                cout << "\nIngrese la nota del bimestre " << i << ": ";
                cin >> alumno[clave].nota[i];
                if ((alumno[clave].nota[i] < 0) || (alumno[clave].nota[i] > 100))
                {
                    cout << "\nIngresa una calificacion valida entre 0 y 100." << endl;
                    getch();
                }
            } while ((alumno[clave].nota[i] < 0) || (alumno[clave].nota[i] > 100));
        }
        alumno[clave].registro = true;
        cout << "Los datos han sido registrados con exito." << endl;
    }
}

void eliminar_nota()
{
    cout << "\tEliminar notas" << endl;
    int clave;
    char x;
    cout << "Digite la clave del alumno para eliminar sus notas (1-5): ";
    cin >> clave;
    if ((clave < 1) || (clave > 5))
    {
        cout << "El numero ingresado es invalido." << endl;
    }
    else if (alumno[clave].registro == false)
    {
        cout << "No hay notas registradas en esta clave." << endl;
    }
    else
    {
        cout << "\nDatos por eliminar" << endl
             << endl;
        cout << "Nombre del alumno: " << alumno[clave].nombre << endl;
        for (int i = 1; i <= 4; i++)
        {
            cout << "Nota del bimestre " << i << ": " << alumno[clave].nota[i] << endl;
        }
        do
        {
            cout << "Desea eliminar estos datos? (s/n): ";
            cin >> x;
            if ((x == 's') || (x == 'S'))
            {
                for (int i = 1; i <= 15; i++)
                {
                    alumno[clave].nombre[i] = 0;
                    for (int j = 1; j <= 4; j++)
                    {
                        alumno[clave].nota[j] = 0;
                    }
                }
                alumno[clave].registro = false;
                cout << "Los datos han sido eliminados con exito." << endl;
            }
            else if ((x == 'n') || (x == 'N'))
            {
                cout << "No se eliminaron los datos." << endl;
            }
            else
            {
                cout << "El caracter digitado es invalido, intente de nuevo." << endl;
            }
        } while ((((x != 's') && (x != 'S')) && (x != 'n')) && (x != 'N'));
    }
}