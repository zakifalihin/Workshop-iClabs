#include <iostream>
using namespace std;

int n; 

class Bintang {

    void cetakKolom(int jumlah) {
        if (jumlah == 0) 
        return;
        cout << "*";
        cetakKolom(jumlah - 1);
    }

    void cetakBaris(int baris) {
        if (baris > n) 
        return;
        cetakKolom(baris);
        cout << endl;
        cetakBaris(baris + 1);
    }

    public:
    Bintang(int jumlahBaris) {
        n = jumlahBaris;
    }

    void tampilkanPola() {
        cetakBaris(1);
    }
};

int main() {
    int jumlah;
    cout << "Masukkan Ukuran: ";
    cin >> jumlah;

    if (jumlah <= 0) {
        cout << "Jumlah baris harus lebih dari 0!" << endl;
    } else {
        Bintang pola(jumlah);
        pola.tampilkanPola();
    }

    return 0;
}
