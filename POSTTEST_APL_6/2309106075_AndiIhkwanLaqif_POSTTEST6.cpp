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
        cout << "Harga tidak boleh kosong, angka terlalu banyak atau negatif dan huruf." << endl;
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


void bubbleSort(vector<Sepatu> &arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j].merk > arr[j + 1].merk) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(vector<Sepatu> &arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<Sepatu> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].ukuran >= R[j].ukuran) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<Sepatu> &arr, int left, int right) {
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

void insertionSortByWarna(vector<Sepatu> &arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        Sepatu key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].detail.warna > key.detail.warna) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void tampilkanSemuaSepatu(vector<Sepatu> *daftarSepatu) {
    if (daftarSepatu->empty()) {
        cout << "Daftar sepatu kosong." << endl;
    } else {
        // Sorting bubble sort secara ascending pada huruf
        bubbleSort(*daftarSepatu);

        cout << "Daftar Sepatu (Diurutkan berdasarkan merk secara ascending[bubble sort]):" << endl;
        for (size_t i = 0; i < daftarSepatu->size(); ++i) {
            cout << "Indeks: " << i << ", Merk: " << daftarSepatu->at(i).merk << ", Nama Sepatu: " << daftarSepatu->at(i).namasepatu << ", Ukuran: " << daftarSepatu->at(i).ukuran << ", Harga: " << daftarSepatu->at(i).harga << ", Warna: " << daftarSepatu->at(i).detail.warna << ", Material: " << daftarSepatu->at(i).detail.material << ", Fitur: ";
            for (int j = 0; j < 2; ++j) {
                cout << daftarSepatu->at(i).detail.tambahan_terkait_sepatu[j] << " ";
            }
            cout << endl;
        }

        //ini Sorting insertion sort secara ascending pada huruf (warna)
        insertionSortByWarna(*daftarSepatu);

        cout << "\nDaftar Sepatu (Diurutkan berdasarkan warna secara ascending[insertion sort]):" << endl;
        for (size_t i = 0; i < daftarSepatu->size(); ++i) {
            cout << "Indeks: " << i << ", Merk: " << daftarSepatu->at(i).merk << ", Nama Sepatu: " << daftarSepatu->at(i).namasepatu << ", Ukuran: " << daftarSepatu->at(i).ukuran << ", Harga: " << daftarSepatu->at(i).harga << ", Warna: " << daftarSepatu->at(i).detail.warna << ", Material: " << daftarSepatu->at(i).detail.material << ", Fitur: ";
            for (int j = 0; j < 2; ++j) {
                cout << daftarSepatu->at(i).detail.tambahan_terkait_sepatu[j] << " ";
            }
            cout << endl;
        }

        //ini Sorting merge sort secara descending pada angka (ukuran)
        mergeSort(*daftarSepatu, 0, daftarSepatu->size() - 1);

        cout << "\nDaftar Sepatu (Diurutkan berdasarkan ukuran secara descending[merge sort]):" << endl;
        for (int i = daftarSepatu->size() - 1; i >= 0; --i) {
            cout << "Indeks: " << i << ", Merk: " << daftarSepatu->at(i).merk << ", Nama Sepatu: " << daftarSepatu->at(i).namasepatu << ", Ukuran: " << daftarSepatu->at(i).ukuran << ", Harga: " << daftarSepatu->at(i).harga << ", Warna: " << daftarSepatu->at(i).detail.warna << ", Material: " << daftarSepatu->at(i).detail.material << ", Fitur: ";
            for (int j = 0; j < 2; ++j) {
                cout << daftarSepatu->at(i).detail.tambahan_terkait_sepatu[j] << " ";
            }
            cout << endl;
        }
    }
}

int sequentialSearchAsc(const vector<Sepatu> &arr, const string &target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i].merk == target) {
            return i;
        }
    }
    return -1;
}

int binarySearchDesc(const vector<Sepatu> &arr, const string &target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].merk == target) {
            return mid;
        } else if (arr[mid].merk > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
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
        cout << "\nMenu:\n1. Tambah Data Sepatu\n2. Tampilkan Semua Data Sepatu\n3. Ubah Data Sepatu\n4. Hapus Data Sepatu\n5. Sequential Search Ascending\n6. Binary Search Descending\n7. Keluar\nPilih Menu : ";
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
            case 5: {
                string target;
                cout << "Masukkan merk sepatu yang ingin dicari: ";
                clearInputBuffer();
                getline(cin, target);
                int hasil = sequentialSearchAsc(daftarSepatu, target);
                if (hasil != -1) {
                    cout << "Data ditemukan pada indeks: " << hasil << endl;
                } else {
                    cout << "Data tidak ditemukan." << endl;
                }
                break;
            }
            case 6: {
                string target;
                cout << "Masukkan merk sepatu yang ingin dicari: ";
                clearInputBuffer();
                getline(cin, target);
                int hasil = binarySearchDesc(daftarSepatu, target);
                if (hasil != -1) {
                    cout << "Data ditemukan pada indeks: " << hasil << endl;
                } else {
                    cout << "Data tidak ditemukan." << endl;
                }
                break;
            }
            case 7:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilih menu 1-7\n";
                clearInputBuffer();
        }
    } while (pilih != 7);

    return 0;
}