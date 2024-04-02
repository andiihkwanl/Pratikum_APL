#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Sepatu {
    string merk;
    string namasepatu;
    int ukuran;
    double harga;
    struct Detail {
        string warna;
        string material;
        string tambahan_terkait_sepatu[2]; 
    } detail;
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void tambahSepatu(vector<Sepatu> &daftarSepatu) {
    Sepatu sepatu;
    cout << "Merk: ";
    clearInputBuffer();
    getline(cin, sepatu.merk);
    if (sepatu.merk.empty()) {
        cout << "Merk tidak boleh kosong." << endl;
        return;
    }
    cout << "Nama Sepatu: ";
    getline(cin, sepatu.namasepatu);
    if (sepatu.namasepatu.empty()) {
        cout << "Nama sepatu tidak boleh kosong." << endl;
        return;
    }
    cout << "Ukuran: ";
    cin >> sepatu.ukuran;
    if (cin.fail() || sepatu.ukuran <= 0) {
        cout << "Ukuran tidak boleh kosong atau negatif dan huruf." << endl;
        clearInputBuffer();
        return;
    }
    cout << "Harga: ";
    cin >> sepatu.harga;
    if (cin.fail() || sepatu.harga <= 0) {
        cout << "Harga tidak boleh kosong atau negatif dan huruf." << endl;
        clearInputBuffer();
        return;
    }

   
    cout << "Warna: ";
    clearInputBuffer();
    getline(cin, sepatu.detail.warna);
    cout << "Material: ";
    getline(cin, sepatu.detail.material);

    
    cout << "apa yang ingin ditambahkan pada sepatu?: ";
    for (int i = 0; i < 2; ++i) {
        cout << "penambahan ke-:" << i + 1 << ": ";
        getline(cin, sepatu.detail.tambahan_terkait_sepatu[i]);
    }

    daftarSepatu.push_back(sepatu);
    cout << "Data sepatu berhasil ditambahkan." << endl;
}

void tampilkanSemuaSepatu(const vector<Sepatu> *daftarSepatu) {
    if (daftarSepatu->empty()) {
        cout << "Daftar sepatu kosong." << endl;
    } else {
        cout << "Daftar Sepatu:" << endl;
        for (size_t i = 0; i < daftarSepatu->size(); ++i) {
            cout << "Indeks: " << i << ", Merk: " << daftarSepatu->at(i).merk << ", Nama Sepatu: " << daftarSepatu->at(i).namasepatu << ", Ukuran: " << daftarSepatu->at(i).ukuran << ", Harga: " << daftarSepatu->at(i).harga << ", Warna: " << daftarSepatu->at(i).detail.warna << ", Material: " << daftarSepatu->at(i).detail.material << ", Fitur: ";
            for (int j = 0; j < 2; ++j) {
                cout << daftarSepatu->at(i).detail.tambahan_terkait_sepatu[j] << " ";
            }
            cout << endl;
        }
    }
}


void ubahSepatu(vector<Sepatu> &daftarSepatu) {
    if (daftarSepatu.empty()) {
        cout << "Daftar sepatu kosong." << endl;
        return;
    }
    size_t indeks;
    cout << "Masukkan indeks sepatu yang ingin diubah: ";
    cin >> indeks;
    if (cin.fail() || indeks < 0 || indeks >= daftarSepatu.size()) {
        cout << "Indeks tidak valid." << endl;
        clearInputBuffer();
        return;
    }
    Sepatu &sepatu = daftarSepatu[indeks];
    cout << "Merk: ";
    clearInputBuffer();
    getline(cin, sepatu.merk);
    if (sepatu.merk.empty()) {
        cout << "Merk tidak boleh kosong." << endl;
        return;
    }
    cout << "Nama Sepatu: ";
    getline(cin, sepatu.namasepatu);
    if (sepatu.namasepatu.empty()) {
        cout << "Nama sepatu tidak boleh kosong." << endl;
        return;
    }
    cout << "Ukuran: ";
    cin >> sepatu.ukuran;
    if (cin.fail() || sepatu.ukuran <= 0) {
        cout << "Ukuran tidak boleh kosong atau negatif." << endl;
        clearInputBuffer();
        return;
    }
    cout << "Harga: ";
    cin >> sepatu.harga;
    if (cin.fail() || sepatu.harga <= 0) {
        cout << "Harga tidak boleh kosong atau negatif." << endl;
        clearInputBuffer();
        return;
    }

   
    cout << "Warna: ";
    clearInputBuffer();
    getline(cin, sepatu.detail.warna);
    cout << "Material: ";
    getline(cin, sepatu.detail.material);

   
    cout << "Fitur: ";
    for (int i = 0; i < 2; ++i) {
        cout << "Fitur ke-" << i + 1 << ": ";
        getline(cin, sepatu.detail.tambahan_terkait_sepatu[i]);
    }

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
    if (cin.fail() || indeks < 0 || indeks >= daftarSepatu.size()) {
        cout << "Indeks tidak valid." << endl;
        clearInputBuffer();
        return;
    }
    daftarSepatu.erase(daftarSepatu.begin() + indeks);
    cout << "Data sepatu berhasil dihapus." << endl;
}

bool login() {
    string nama, nim;
    int salah = 0;

    while (salah < 3) {
        cout << "Masukkan Nama: ";
        
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

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

int main() {
   vector<Sepatu> daftarSepatu;

    if (!login()) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }

    int pilih;
    do {
        cout << "\nMenu:\n1. Tambah Data Sepatu\n2. Tampilkan Semua Data Sepatu\n3. Ubah Data Sepatu\n4. Hapus Data Sepatu\n5. Keluar\nPilih Menu : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                tambahSepatu(daftarSepatu);
                break;
            case 2:
                tampilkanSemuaSepatu(&daftarSepatu);
                break;
            case 3:
                ubahSepatu(daftarSepatu);
                break;
            case 4:
                hapusSepatu(daftarSepatu);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilih menu 1-5\n";
                clearInputBuffer();
        }
    } while (pilih != 5);

    return 0;
}