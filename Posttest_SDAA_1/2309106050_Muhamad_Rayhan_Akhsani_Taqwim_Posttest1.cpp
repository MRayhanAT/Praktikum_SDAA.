#include <iostream>
using namespace std;

void segitiga_Paskal() {
    for (int baris = 0; baris < 3; baris++) {
        int value = 1;
        for (int i = 0; i <= baris; i++) {
            cout << value << " "; 
            value = value * (baris - i) / (i + 1);        }
        cout << endl;    }
}

int main() {

    segitiga_Paskal();

    return 0;
}