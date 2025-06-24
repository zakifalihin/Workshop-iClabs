#include <iostream>
using namespace std;

int main() {
    int bilangan[5];
    int total = 0;
    int max, min;

    cout << "Masukkan 5 bilangan Bro:";

    for (int i = 0; i < 5; i++) {
        cin >> bilangan[i];
        total += bilangan[i];

        if (i == 0) {
            max = min = bilangan[i];
        } else {
            if (bilangan[i] > max) max = bilangan[i];
            if (bilangan[i] < min) min = bilangan[i];
        }
    }
    
    float rataRata = total / 5;

    int jumlahAtasRata = 0;
    for (int i = 0; i < 5; i++) {
        if (bilangan[i] > rataRata) {
            jumlahAtasRata++;
        }
    }

    cout << "\nBilangan terbesar: " << max << endl;
    cout << "Bilangan terkecil: " << min << endl;
    cout << "Rata-rata: " << rataRata << ".0" << endl;
    cout << "Jumlah bilangan di atas rata-rata: " << jumlahAtasRata << endl;

    return 0;
}
