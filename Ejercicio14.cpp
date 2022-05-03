#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int factorial;
    for (int i = 10; i <= 50; i++){
        if (i % 5 == 0){
            for (int j = 1; j <= i; j++){
                factorial *= j;
            }
            cout << "Numero " << i << " su factorial es " << factorial << " y su logaritmo natural es " << log(i) << endl;
        }
    }
    system("pause");
    return 0;
}