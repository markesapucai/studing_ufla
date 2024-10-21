#include <iostream>

using namespace std;


int main() {
    int x = 0, y = 8;

    while(x < 4 or y > 5) {
        x++;
        y++;
        y = y - x;
    }

    cout << x + y << endl;

    return 0;
}