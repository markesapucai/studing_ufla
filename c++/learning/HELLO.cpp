#include <iostream>

using namespace std;

#define char good = "a";
#define floot pi = 3,14; // definindo que esssa variaveis são globais e imutaveis

int sum(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int a, b;
    cout << "type one number:" << endl;
    cin >> a;
    cout << "type another" << endl;
    cin >> b;

    int resul = sum(a, b);

    cout << "your result is: " << resul;
    return 0;
}