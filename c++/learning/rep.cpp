#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int tamVet;
    cin >> tamVet;
    vector<int> vetor(tamVet); 
    vector<int> newVet;
    
    for(int i = 0; i < tamVet; i++) {
        cin >> vetor[i];
    }

    for(int i = 0; i < tamVet; i++) {
        if(newVet.empty() || vetor[i] < newVet[0]) {
            newVet.insert(newVet.begin(), vetor[i]); 
        }
    }
    for(int i = 0; i < tamVet; i++) {
        cout << newVet[i] << endl;
    }


    return 0;
}