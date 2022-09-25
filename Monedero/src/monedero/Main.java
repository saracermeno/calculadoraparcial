package monedero;

import java.util.Scanner;

public class Main {
    static double DineroCuenta = 5000.00;

    public static void main(String[] args) {
        int x = 5;
        Scanner in = new Scanner(System.in);
        do {
            System.out.println("\tMonedero");
            System.out.println("1. Depositar dinero");
            System.out.println("2. retirar dinero");
            System.out.println("3. Consultar estado");
            System.out.println("4. Salir");
            System.out.println("Ingrese el numero de la opcion a seguir: ");
            x = in.nextInt();
            switch (x) {
                case 1:
                    deposito();
                    break;
                case 2:
                    retiro();
                    break;
                case 3:
                    consulta();
                    break;
                case 4:
                    System.out.println("Esta saliendo");
                    break;
                default:
                    System.out.println("El numero ingresado no es valido, intente otra vez");
                    break;
            }
            if (x == 1 || x == 2 || x == 3) {
                System.out.println("Volvera al menu principal...\n");
            }
        } while (x != 4);
    }

    public static void retiro() {//Restarle a la cuenta
        double Ret;
        Scanner en = new Scanner(System.in);
        System.out.println("\tRetiro");
        System.out.println("Ingrese la cantidad de dinero a retirar: ");
        Ret = en.nextDouble();
        DineroCuenta = DineroCuenta - Ret;
        System.out.println("El dinero ha sido retirado de su cuenta.");
    }

    public static void deposito() { //Sumarle a la cuenta
        double Dep;
        Scanner on = new Scanner(System.in);
        System.out.println("\tDeposito");
        System.out.println("Ingrese la cantidad de dinero a depositar: ");
        Dep = on.nextDouble();
        DineroCuenta = DineroCuenta + Dep;
        System.out.println("El dinero ha sido depositado exitosamente.");
    }

    public static void consulta() {
        System.out.println("\tConsulta de cuenta");
        System.out.println("El dinero disponible en su cuenta es: "+DineroCuenta);
    }
    
    public static void limpiarConsola() {  //Esto es lo equivalente a System("cls") en C++ y es para limpiar la consola
    System.out.print("\033[H\033[2J");  
    System.out.flush();  
}  
}
