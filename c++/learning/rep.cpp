#include <iostream>
#include <math.h>

using namespace std;

int calcula(int a) {
    int multi = 1;
    for(int x = a; x > 1; x--) {
        multi *= x;
    }
    return multi;
}

int main() {
    int a;
    cout << "Digite um número inteiro positivo" << endl;
    cin >> a;
    int resul = calcula(a);
    int resulBibli = tgamma(a + 1);
    cout << "O fatorial de " << a << " e " << resul << " PELO CALCULO" << endl;
    cout << "O fatorial de " << a << " e " << resulBibli << " PELA BIBLIOTECA" << endl;
    return 0;
}