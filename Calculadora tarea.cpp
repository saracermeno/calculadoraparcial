#include <iostream>

using namespace std; 
int main(){
	float dato1;
	float dato2;
	float sumar,restar,multiplicar,dividir;
	char signo;
	
	cout<<"CALCULADORA"<<endl;
	
	cout<<"Ingresar el primer dato:"<<endl;
	cin>>dato1;
	cout<<"Ingresar el segundo dato:"<<endl;
	cin>>dato2;
	cout<<"Ingresar el simbolo de la operacion:"<<endl;
	cin>>signo;
	
	if(signo=='+'){
		sumar=dato1+dato2;
		cout<<"El resultado de la suma es: "<<sumar<<endl;
	}else if(signo=='-'){
		restar=dato1-dato2;
		cout<<"El resultado de la resta es: "<<restar<<endl;
	}else if(signo=='*'){
		multiplicar=dato1*dato2;
		cout<<"El resultado de la multiplicacion es: "<<multiplicar<<endl;
	}else if(signo=='/'){
		dividir=dato1/dato2;
		cout<<"El resultado de la division es: "<<dividir<<endl;
	}	
	system("pause");
	return 8;
}
