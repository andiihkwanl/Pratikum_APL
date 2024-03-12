#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Sepatu {
    string merk;
    string namasepatu;
    int ukuran;
    double harga;
};


void tambahSepatu(vector<Sepatu> &daftarSepatu) {
    Sepatu sepatu;
    cout << "Merk: ";
    cin >> sepatu.merk;
    cout << "nama sepatu: ";
    cin >> sepatu.namasepatu;
    cout << "Ukuran: ";
    cin >> sepatu.ukuran;
    cout << "Harga: ";
    cin >> sepatu.harga;
    daftarSepatu.push_back(sepatu);
    cout << "Data sepatu berhasil ditambahkan." << endl;
}


void tampilkanSemuaSepatu(const vector<Sepatu> &daftarSepatu) {
    if (daftarSepatu.empty()) {
        cout << "Daftar sepatu kosong." << endl;
    } else {
        cout << "Daftar Sepatu:" << endl;
        for (size_t i = 0; i < daftarSepatu.size(); ++i) {
            cout << "Indeks: " << i << ", Merk: " << daftarSepatu[i].merk << ", nama sepatu: " << daftarSepatu[i].namasepatu << ", Ukuran: " << daftarSepatu[i].ukuran << ", Harga: " << daftarSepatu[i].harga << endl;
        }
    }
}


void ubahSepatu(vector<Sepatu> &daftarSepatu) {
    if (daftarSepatu.empty()) {
        cout << "Daftar sepatu kosong." << endl;
        return;
    }
    cout << "Pilih indeks sepatu yang ingin diubah: ";
    size_t indeks;
    cin >> indeks;
    if (indeks < 0 || indeks >= daftarSepatu.size()) {
        cout << "Indeks tidak valid." << endl;
        return;
    }
    cout << "Merk: ";
    cin >> daftarSepatu[indeks].merk;
    cout << "nama sepatu: ";
    cin >> daftarSepatu[indeks].namasepatu;
    cout << "Ukuran: ";
    cin >> daftarSepatu[indeks].ukuran;
    cout << "Harga: ";
    cin >> daftarSepatu[indeks].harga;
    cout << "Data sepatu berhasil diubah." << endl;
}


void hapusSepatu(vector<Sepatu> &daftarSepatu) {
    if (daftarSepatu.empty()) {
        cout << "Daftar sepatu kosong." << endl;
        return;
    }
    cout << "Pilih indeks sepatu yang ingin dihapus: ";
    size_t indeks;
    cin >> indeks;
    if (indeks < 0 || indeks >= daftarSepatu.size()) {
        cout << "Indeks tidak valid." << endl;
        return;
    }
    daftarSepatu.erase(daftarSepatu.begin() + indeks);
    cout << "Data sepatu berhasil dihapus." << endl;
}

int main() {
    vector<Sepatu> daftarSepatu;
    string nama, nim;
    int salah = 0;

    
    while (salah < 3) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

       
        if (nama == "Andi" && nim == "75") {
            cout << "Login berhasil!" << endl;
            break;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            salah++;
        }
    }

    
    if (salah >= 3) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }

    
    char ulang;
    do {
        
        int pilihan;
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data Sepatu" << endl;
        cout << "2. Tampilkan Semua Data Sepatu" << endl;
        cout << "3. Ubah Data Sepatu" << endl;
        cout << "4. Hapus Data Sepatu" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        
        switch (pilihan) {
            case 1:
                tambahSepatu(daftarSepatu);
                break;
            case 2:
                tampilkanSemuaSepatu(daftarSepatu);
                break;
            case 3:
                tampilkanSemuaSepatu(daftarSepatu);
                cout << "Masukkan indeks sepatu yang ingin diubah: ";
                ubahSepatu(daftarSepatu);
                break;
            case 4:
                tampilkanSemuaSepatu(daftarSepatu);
                cout << "Masukkan indeks sepatu yang ingin dihapus: ";
                hapusSepatu(daftarSepatu);
                break;
            case 5:
                cout << "Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        
        cout << "\nApakah Anda ingin menambahkan/mengubah/menghapus data lainnya? (Y/N): ";
        cin >> ulang;
    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}