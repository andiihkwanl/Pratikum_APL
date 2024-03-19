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

void tambahSepatu(vector<Sepatu> &daftarSepatu);
void tampilkanSemuaSepatu(const vector<Sepatu> &daftarSepatu);
void ubahSepatu(vector<Sepatu> &daftarSepatu);
void hapusSepatu(vector<Sepatu> &daftarSepatu);
bool login();
int menu();
void jalankanMenu(vector<Sepatu> &daftarSepatu);

int main() {
    vector<Sepatu> daftarSepatu;

    if (!login()) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }

    jalankanMenu(daftarSepatu);

    return 0;
}

bool login() {
    string nama, nim;
    int salah = 0;

    while (salah < 3) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == "Andi" && nim == "75") {
            cout << "Login berhasil!" << endl;
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            salah++;
        }
    }

    return false;
}

int menu() {
    int pilihan;
    cout << "\nMenu:" << endl;
    cout << "1. Tambah Data Sepatu" << endl;
    cout << "2. Tampilkan Semua Data Sepatu" << endl;
    cout << "3. Ubah Data Sepatu" << endl;
    cout << "4. Hapus Data Sepatu" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    return pilihan;
}

void jalankanMenu(vector<Sepatu> &daftarSepatu) {
    char ulang;
    do {
        switch (menu()) {
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
                hapusSepatu(daftarSepatu);
                break;
            case 5:
                cout << "Program selesai." << endl;
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << "\nApakah Anda ingin menambahkan/mengubah/menghapus data lainnya? (Y/N): ";
        cin >> ulang;
    } while (ulang == 'Y' || ulang == 'y');
}

void tambahSepatu(vector<Sepatu> &daftarSepatu) {
    Sepatu sepatu;
    cout << "Merk: ";
    cin >> sepatu.merk;
    cout << "Nama Sepatu: ";
    cin >> sepatu.namasepatu;
    cout << "Ukuran: ";
    cin >> sepatu.ukuran;
    cout << "Harga: ";
    cin >> sepatu.harga;
    daftarSepatu.push_back(sepatu);
    cout << "Data sepatu berhasil ditambahkan." << endl;

    char tambahLagi;
    cout << "\nApakah Anda ingin menambahkan data sepatu lagi? (Y/N): ";
    cin >> tambahLagi;
    if (tambahLagi == 'Y' || tambahLagi == 'y') {
        tambahSepatu(daftarSepatu);  
    }
}



void tampilkanSemuaSepatu(const vector<Sepatu> &daftarSepatu) {
    if (daftarSepatu.empty()) {
        cout << "Daftar sepatu kosong." << endl;
    } else {
        cout << "Daftar Sepatu:" << endl;
        for (size_t i = 0; i < daftarSepatu.size(); ++i) {
            cout << "Indeks: " << i << ", Merk: " << daftarSepatu[i].merk << ", Nama Sepatu: " << daftarSepatu[i].namasepatu << ", Ukuran: " << daftarSepatu[i].ukuran << ", Harga: " << daftarSepatu[i].harga << endl;
        }
    }
}

void ubahSepatu(vector<Sepatu> &daftarSepatu) {
    if (daftarSepatu.empty()) {
        cout << "Daftar sepatu kosong." << endl;
        return;
    }
    size_t indeks;
    cin >> indeks;
    if (indeks < 0 || indeks >= daftarSepatu.size()) {
        cout << "Indeks tidak valid." << endl;
        return;
    }
    cout << "Merk: ";
    cin >> daftarSepatu[indeks].merk;
    cout << "Nama Sepatu: ";
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
    size_t indeks;
    cout << "Masukkan indeks sepatu yang ingin dihapus: ";
    cin >> indeks;
    if (indeks < 0 || indeks >= daftarSepatu.size()) {
        cout << "Indeks tidak valid." << endl;
        return;
    }
    daftarSepatu.erase(daftarSepatu.begin() + indeks);
    cout << "Data sepatu berhasil dihapus." << endl;
}