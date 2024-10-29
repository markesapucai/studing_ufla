#include <iostream>

using namespace std;

int main()
{
    // ponteiros
    /*int valor2 = 2;
    int valor;
    int* ponteiro;

    valor=50;
    ponteiro =& valor;

    cout << ponteiro << endl;
    cout << *ponteiro * valor2;*/

    // vetores
    /*char vet[5] = {'a','b','c','d','e'};
    char anotherVet[] = {'x','y'};

    cout << vet[0];
    cout << anotherVet[8];*/
    //alocação estatica
    /*int x = 15;
    char newArray[16];
    char alfabeto[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < x; i++)
    {
        newArray[i] = alfabeto[i];
        cout << newArray[i] << endl;
    }

    int n = sizeof(newArray);
    cout << n << endl;*/

    //alocação dinamica
    int tamanho;
    cout << "Digite o tamanho do seu vetor" << endl;
    cin >> tamanho;
    int *vetor = new int[tamanho];

    for(int i = 0; i < tamanho; i++){
        cout << "Digite o " << i + 1 << " valor " << endl;
        cin >> vetor[i];
    }

    for(int i = 0; i < tamanho ; i++) {
        cout << vetor[i] << " ";
    }

    return 0;
}