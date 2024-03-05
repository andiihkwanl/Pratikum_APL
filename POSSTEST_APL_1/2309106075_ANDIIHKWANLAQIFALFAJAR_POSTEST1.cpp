#include <iostream>

using namespace std;

int main() {
    char ulangi;
    int count = 0;
    int menu, awal, akhir;
    double speed;
    string nim; 
    string nama;
    

    while (count < 3) {
        
        cout << "Masukkan Nama:";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        cin.ignore();
       

        if (nama == "Andi" and nim == "75") {
            cout << "Login berhasil!" << endl;
            do {
        cout << "Menu Konversi Kecepatan:" << endl;
        cout << "1. Konversi Kilometer/jam" << endl;
        cout << "2. Konversi Centimeter/detik" << endl;
        cout << "3. Konversi Meter/detik" << endl;
        cout << "4. Konversi Mil/jam" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        cout << "Masukkan kecepatan: ";
        cin >> speed;

        cout << "Pilih satuan kecepatan (1/2/3/4): ";
        cin >> awal;

        cout << "Pilih satuan yang ingin dikonversi (1/2/3/4): ";
        cin >> akhir;

        double result;

        // Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)
        if (awal == 1) {
            if (akhir == 1) // Kilometer/jam ke Centimeter/detik
                result = speed * 27.7778;
            else if (akhir == 2) // Kilometer/jam ke Meter/detik
                result = speed * 0.277778;
            else if (akhir == 3) // Kilometer/jam ke Mil/jam
                result = speed * 0.621371;
        }
        // Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)
        else if (awal == 2) {
            if (akhir == 1) // Centimeter/detik ke Kilometer/jam
                result = speed * 0.036;
            else if (akhir == 2) // Centimeter/detik ke Meter/detik
                result = speed * 0.01;
            else if (akhir == 3) // Centimeter/detik ke Mil/jam
                result = speed * 0.0223694;
        }
        // Konversi Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)
        else if (awal == 3) {
            if (akhir == 1) // Meter/detik ke Kilometer/jam
                result = speed * 3.6;
            else if (akhir == 2) // Meter/detik ke Centimeter/detik
                result = speed * 100;
            else if (akhir == 3) // Meter/detik ke Mil/jam
                result = speed * 2.23694;
        }
        // Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)
        else if (awal == 4) {
            if (akhir == 1) // Mil/jam ke Kilometer/jam
                result = speed * 1.60934;
            else if (akhir == 2) // Mil/jam ke Centimeter/detik
                result = speed * 44.704;
            else if (akhir == 3) // Mil/jam ke Meter/detik
                result = speed * 0.44704;
        } else {
            result = -1;
        }

        if (result == -1) {
            cout << "Satuan tidak valid!" << endl;
        } else {
            cout << "Hasil konversi: " << result << endl;
        }

        cout << "Apakah Anda ingin mengulangi (y/n)?: ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');
            break;
        } else {
            cout << "NIM salah, coba lagi." << endl;
            count++;
            
        }
    }

    if (count == 3) {
        cout << "Anda sudah gagal login sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }

    
    cout << "Terima kasih telah menggunakan program" << endl;

    return 0;
}