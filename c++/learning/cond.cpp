#include <iostream>

using namespace std;

float recebeNota() {
    float nota01, nota02;
    cout << "me diga sua nota 1" << endl;
    cin >> nota01;
    cout << "me diga sua nota 2" << endl;
    cin >> nota02;
    float media = (nota01 + nota02)/2;
    return media;
}

float pegaFrequencia() {
    float dias;
    cout << "De 36 dias, quantos voce foi para a escola?" << endl;
    cin >> dias;
    float freq = (dias * 100)/36;
    return freq;
}

int main() {
    float media = recebeNota();
    float freq = pegaFrequencia();

    if(media < 7 || freq < 70){
        if(media < 7 && freq >=70) {
            cout << "Aluno reprovado pela media " << media << " mas aprovado pela frequencia " << freq;
        } else if(media > 7 && freq < 70) {
            cout << "Aluno aprovado pela media " << media << " mas reprovado pela frequencia " << freq;
        } else if(media < 7 && freq < 70) {
            cout << "Aluno reprovado pela media " << media << " e reprovado pela frequencia " << freq;
        }
    } else if (media >= 7 && freq >= 70) {
        cout << "Aluno Aprovado, com media de " << media << " e frequencia de " << freq;
    }

    return 0;
}