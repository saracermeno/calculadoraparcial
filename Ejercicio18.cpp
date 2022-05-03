#include <iostream>
#include <math.h>

using namespace std;

int main(){
    for (int i = 60; i >= 20; i--){
        if (i % 4 == 0){
            cout << "Numero " << i << ", su logaritmo de base 10 es " << log10(i) << " y su logaritmo natural (base e) es " << log(i) << endl;
        }
    }
    system("pause");
    return 0;
}