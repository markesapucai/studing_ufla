#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

float calculateAreaOfCircle(float raio) {
    float raio2 = pow(raio, 2);
    float area = PI * raio2; 
    return area;
}

int main() {
    float raio;
    cout << "Digte o valor do raio" << endl;
    cin >> raio;

    cout << "A area dpo ciculo e: " << calculateAreaOfCircle(raio);
    return 0;
}