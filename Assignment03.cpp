#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Model 
class Mahasiswa {
private:
    string nama;
    long long int nim;

public:
    //construktor 
    Mahasiswa(string nama, long long int nim) {
        this->nama = nama;
        this->nim = nim;
    }

    string getNama() const {
        return nama;
    }

    long long int getNim() const {
        return nim;
    }
};

bool compareByNIM(Mahasiswa& a, Mahasiswa& b) {
    return a.getNim() < b.getNim();
}

//Controller 
class ManajemenMahasiswa {
private:
    vector<Mahasiswa> daftar;

public:
    void tambahMahasiswa(string& nama, long long int nim) {
        Mahasiswa mhs(nama, nim);
        daftar.push_back(mhs);
    }

    void urutkanBerdasarkanNIM() {
        sort(daftar.begin(), daftar.end(), compareByNIM);
    }


//view 
    void tampilkanDaftar() {
        cout << "\n=== Data Mahasiswa (Terurut Berdasarkan NIM) ===" << endl;
        for (size_t i = 0; i < daftar.size(); ++i) {
            cout << "Mahasiswa ke-" << (i + 1)
                << "\nNama = " << daftar[i].getNama()
                << "\nNIM = " << daftar[i].getNim() << endl;
        }
    }
};


//fungsi Main
int main() {
    int jumlah;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;
    cin.ignore();

    ManajemenMahasiswa manajemen;

    string nama;
    long long int nim;

    for (int i = 0; i < jumlah; ++i) {
        cout << "Masukkan nama mahasiswa ke-" << (i + 1) << ": ";
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa ke-" << (i + 1) << ": ";
        cin >> nim;
        cin.ignore();

        manajemen.tambahMahasiswa(nama, nim);
    }

    manajemen.urutkanBerdasarkanNIM();
    manajemen.tampilkanDaftar();

    return 0;
}
