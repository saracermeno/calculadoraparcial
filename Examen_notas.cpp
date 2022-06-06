#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

void menu();
void ingresar_notas();
void verificar_notas(float &, int); // verifica que se ingresen notas validas
string cursos(int &);
bool certificado(float &, float &, float &); // dira si el alumno es promovido o no promovido
void resultados();                           // enseña la nota mas alta y mas baja
void guardar_informacion();                  // aqui guarda la informacion en archivos .txt
void leer_informacion();                     // aqui lee la informacion en archivos .txt

struct expediente
{
    float nota[4];
    float promedio;
    bool notas_ingresadas;
    bool promovido;
} alumno;

ofstream registro;
ifstream lectura;

int main(int argc, char const *argv[])
{
    system("Title Sistema de notas");
    do
    {
        cout << "\tDeteccion de archivo \"Historial.txt\"" << endl;
        cout << "1.- Obtener notas que fueron guardadas en el fichero." << endl;
        cout << "2.- Realizar un nuevo fichero con nuevas notas." << endl;
        cout << "Ingresar la opcion que usted desee ejecutar:" << endl;
        cin >> argc;
        if (argc == 1)
        {
            leer_informacion();
        }
        else if (argc == 2)
        {
        }
        else
        {
            cout << "El numero ingresado es invalido, intente de nuevo..." << endl;
            getch();
        }
    } while (argc < 1 || argc > 2);
    cout << "\nIngrese cualquier tecla para dirigirse al menu del sistema...";
    getch();
    menu();
    return 0;
}

void menu()
{
    int m;
    do
    {
        system("cls");
        cout << "\tMenu principal del sistema de notas" << endl;
        cout << "1.- Ingrese notas de cursos." << endl;
        cout << "2.- Revisar los resultados." << endl;
        cout << "0.- Cerrar programa." << endl;
        cout << "Ingrese la opcion que desea seguir:" << endl;
        cin >> m;
        if (m >= 1 && m <= 2)
        {
            system("cls");
        }
        switch (m)
        {
        case 0:
            registro.close();
            cout << "Agradezco que haya hecho uso de mi aplicacion , nos vemos en una proxima vez." << endl;
            getch();
            exit(1);
            break;
        case 1:
            ingresar_notas();
            break;
        case 2:
            resultados();
            break;
        default:
            cout << "El numero ingresado es incorrecto, intente de nuevo..." << endl;
            getch();
            break;
        }
    } while (m < 0 || m > 2);
    cout << "\nIngrese cualquier tecla para poderse dirigir al menu del sistema...";
    getch();
    menu();
}

void ingresar_notas()
{
    cout << "\tAgregar notas" << endl;
    if (alumno.notas_ingresadas == true)
    {
        cout << "Las notas ya fueron ingresadas con anterioridad." << endl;
    }
    else
    {
        cout << "Ingrese la nota de programacion: " << endl;
        cin >> alumno.nota[1];
        verificar_notas(alumno.nota[1], 1);
        cout << "Ingrese la nota de algoritmos: " << endl;
        cin >> alumno.nota[2];
        verificar_notas(alumno.nota[2], 2);
        cout << "Ingrese la nota de logica de sistemas: " << endl;
        cin >> alumno.nota[3];
        verificar_notas(alumno.nota[3], 3);
        alumno.notas_ingresadas = true;
        cout << "Los datos del estudiante se registraron con exito." << endl;
    }
}

void verificar_notas(float &nota, int x)
{
    if ((nota < 0) || (nota > 100))
    {
        do
        {
            cout << "\nIngresa una calificacion valida entre 0 y 100..." << endl;
            getch();
            cout << "Ingrese la nota de " << cursos(x) << ": " << endl;
            cin >> nota;
        } while ((nota < 0) || (nota > 100));
    }
}

string cursos(int &c)
{
    string curso;
    switch (c)
    {
    case 1:
        curso = "programacion";
        break;
    case 2:
        curso = "algoritmos";
        break;
    case 3:
        curso = "logica de sistemas";
        break;
    }
    return curso;
}

void resultados()
{
    cout << "\tResultados" << endl;
    int nota_max = 0, nota_min = 101, x, y;
    string promocion;
    if (alumno.notas_ingresadas == true)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (alumno.nota[j] > nota_max) // para calcular la nota mas alta
            {
                nota_max = alumno.nota[j];
                x = j;
            }
            if (alumno.nota[j] < nota_min) // para calcular la nota mas baja
            {
                nota_min = alumno.nota[j];
                y = j;
            }
        }
        cout << "\n-----------------------------" << endl;
        cout << "\tNota mas alta \nDel curso \"" << cursos(x) << "\"\ntiene la puntuacion: " << alumno.nota[x] << endl;
        cout << "\tNota mas baja \nDel curso \"" << cursos(y) << "\"\ntiene la puntuacion: " << alumno.nota[y] << endl;
        alumno.promedio = (alumno.nota[1] + alumno.nota[2] + alumno.nota[3]) / 3;
        cout << "\tPromedio \nSu puntuacion es: " << alumno.promedio << endl;
        alumno.promovido = certificado(alumno.nota[1], alumno.nota[2], alumno.nota[3]);
        if (alumno.promovido == true)
        {
            promocion = "PROMOVIDO";
        }
        else
        {
            promocion = "NO PROMOVIDO";
        }
        cout << "\nCondicion del estudiante: " << promocion << endl;
        cout << "-----------------------------" << endl;
        guardar_informacion(); // En esta parte se crea el archivo y se guardan los datos ingresados al programa
    }
    else
    {
        cout << "No hay notas registradas para ejecutar esta funcion." << endl;
    }
}

bool certificado(float &n1, float &n2, float &n3)
{
    bool resultado;
    if ((n1 < 61) || (n2 < 61) || (n3 < 61))
    {
        resultado = 0;
    }
    else
    {
        resultado = 1;
    }
    return resultado;
}

void guardar_informacion()
{
    registro.open("Historial.txt", ios::app);
    if (registro.fail())
    {
        cout << "No se pudo crear el archivo, probablemente su equipo esta protegido ante escritura de datos." << endl;
        return;
    }
    else
    {
        registro << alumno.nota[1] << " " << alumno.nota[2] << " " << alumno.nota[3] << "\n";
        registro.close();
        cout << "\nEn el archivo \"Historial.txt\" puede encontrar las notas almacenadas." << endl;
    }
}

void leer_informacion()
{
    int i = 1;
    float numero;
    string texto;
    lectura.open("Historial.txt", ios::in);
    cout << "\tLectura de datos" << endl;
    if (lectura.fail())
    {
        cout << "No se pudo abrir el archivo, probablemente fue eliminado el historial." << endl;
    }
    else
    {
        cout << "Estas son las notas almacenadas en el archivo de texto" << endl;
        while (lectura >> numero)
        {
            alumno.nota[i] = numero;
            cout << "Nota de " << cursos(i) << ": " << alumno.nota[i] << endl;
            i++;
        }
        alumno.notas_ingresadas = true;
        cout << "\nProceda a ver los resultados." << endl;
    }
    lectura.close();
}
