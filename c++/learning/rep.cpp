#include <iostream>

using namespace std;

string brownCalculateToGreen(string momColor) {
    if(momColor == "Marrom") {
        return "8.33%";
    } else if(momColor == "Verde") {
        return "27.78%";
    } else if(momColor == "Azul") {
        return "16.67%";
    } else {
        return "ERRO";
    }
}
string brownCalculateToBlue(string momColor) {
    if(momColor == "Marrom") {
        return "2.78%";
    } else if(momColor == "Verde") {
        return "5.56%";
    } else if(momColor == "Azul") {
        return "16.67%";
    } else {
        return "ERRO";
    }
}
string blueBlueToBlue(string momColor) {
    if(momColor == "Azul") {
        return "99%";
    } else if(momColor == "Verde") {
        return "33.08%";
    } else {
        return "ERRO";
    }
}
string blueBlueToGreen(string momColor) {
    if(momColor == "Azul") {
        return "0.5%";
    } else if(momColor == "Verde") {
        return "66.42%";
    } else {
        return "ERRO";
    }
}

int main() {
    string dadColor, momColor, sonColor;
    cin >> dadColor >> momColor >> sonColor;

    if(dadColor == "Marrom" and sonColor == "Verde") {
        cout << brownCalculateToGreen(momColor);
    } else if(dadColor == "Marrom" and sonColor == "Azul") {
        cout << brownCalculateToBlue(momColor);
    } else if(dadColor == "Azul" and sonColor == "Azul") {
        cout << blueBlueToBlue(momColor);
    } else if(dadColor == "Azul" and sonColor == "Verde") {
        cout << blueBlueToGreen(momColor);
    } else if(dadColor == "Verde" and momColor == "Verde") {
        if(sonColor == "Verde") {
            cout << "88.64%";
        } else if(sonColor == "Azul") {
            cout << "10.86%";
        }
    } else {
        cout << "ERRO";
    }
}