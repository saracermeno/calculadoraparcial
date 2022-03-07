#include <iostream>
#include "mate.h"

using namespace std; 

int main (){
	float num1,num2,num3;
	char op;
	cout<<"Calculadora"<<endl;
	cout<<"Escribe el primer numero: ";
	cin>>num1;
	cout<<"Escribe el segundo numero: ";
	cin>>num2;
	cout<<"Escribe el simbolo de operacion, puede ser suma, resta, multiplicacion, division y factorizacion: ";
	cin>>op;
		
	if(op=='+'){
		num3=s(num1,num2);
		cout<<"El resultado de la suma es: "<<num3<<endl;
	}else if(op=='-'){
		num3=r(num1,num2);
		cout<<"El resultado de la resta es: "<<num3<<endl;
	}else if(op=='*'){
		num3=m(num1,num2);
		cout<<"El resultado de la multiplicacion es: "<<num3<<endl;
	}else if(op=='/'){
		num3=d(num1,num2);
		cout<<"El resultado de la division es: "<<num3<<endl;
	}else if(op=='!'){
		num3=f(num1);
		cout<<"El resultado de la factorial es: "<<num3<<endl;
	}else{
		cout<<"Escriba un simbolo de operacion valido";
	}
	system ("pause");
	return 0;
}

