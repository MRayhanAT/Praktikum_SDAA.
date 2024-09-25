#include <iostream>
#include <string>

using namespace std;


struct Barang {
    string nama;
    int stok;
    float harga;
};

void jeda() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    system("cls"); 
}


void tampilkanBarang(Barang* barang, int jumlahBarang) {
    cout << "Daftar Barang di Toko:\n";
    for (int i = 0; i < jumlahBarang; i++) {
        cout << i + 1 << ". Nama: " << barang[i].nama 
             << ", Stok: " << barang[i].stok 
             << ", Harga: Rp " << barang[i].harga << endl;
    }
    jeda();
}


void tambahStok(Barang* barang, int jumlahBarang) {
    int index, jumlah;
    tampilkanBarang(barang, jumlahBarang);
    cout << "Pilih nomor barang yang ingin ditambahkan stok: ";
    cin >> index;
    if (index <= jumlahBarang) {
    cout << "Masukkan jumlah stok yang ingin ditambahkan: ";
    cin >> jumlah;
    barang[index - 1].stok += jumlah;
    cout << "Stok berhasil ditambahkan!\n";
    jeda();
    return;
    } else {
        cout << "Barang tidak ada di list\n";
        jeda();
        return;
    }
}

void kurangiStok(Barang* barang, int jumlahBarang) {
    int index, jumlah;
    tampilkanBarang(barang, jumlahBarang);
    cout << "Pilih nomor barang yang ingin dikurangi stok: ";
    cin >> index;
    cout << "Masukkan jumlah stok yang ingin dikurangi: ";
    cin >> jumlah;
    if (barang[index - 1].stok >= jumlah) {
        barang[index - 1].stok -= jumlah;
        cout << "Stok berhasil dikurangi!\n";
    } else {
        cout << "Stok tidak cukup!\n";
    }
    jeda();
}


void tambahJenisBarang(Barang* barang, int &jumlahBarang, const int maxBarang) {
    if (jumlahBarang >= maxBarang) {
        cout << "Tidak bisa menambah barang baru, kapasitas penuh!\n";
        jeda();
        return;
    }

    cout << "Masukkan nama barang baru: ";
    cin.ignore(); 
    getline(cin, barang[jumlahBarang].nama); 
    cout << "Masukkan jumlah stok: ";
    cin >> barang[jumlahBarang].stok; 
    cout << "Masukkan harga barang: ";
    cin >> barang[jumlahBarang].harga; 
    jumlahBarang++;
    cout << "Barang baru berhasil ditambahkan!\n";
    jeda();
}

void kurangiJenisBarang(Barang* barang, int &jumlahBarang) {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang yang bisa dihapus!\n";
        jeda();
        return;
    }

    tampilkanBarang(barang, jumlahBarang);
    int index;
    cout << "Pilih nomor barang yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > jumlahBarang) {
        cout << "Nomor barang tidak valid!\n";
        jeda();
        return;
    }

    for (int i = index - 1; i < jumlahBarang - 1; i++) {
        barang[i] = barang[i + 1];
    }

    jumlahBarang--; 
    cout << "Barang berhasil dihapus!\n";
    jeda();
}

    



int main() {
    const int maxBarang = 100; 
    Barang barang[maxBarang] = {
        {"Beras", 20, 10000},
        {"Gula", 15, 12000},
        {"Minyak Goreng", 10, 14000}
    };
    int jumlahBarang = 3; 

    int pilihan;

    do {
        cout << "\nSistem Stok Barang Toko Kelontong\n";
        cout << "1. Tampilkan Semua Barang\n";
        cout << "2. Tambah Stok Barang\n";
        cout << "3. Kurangi Stok Barang\n";
        cout << "4. Tambah Jenis Barang\n";
        cout << "5. Kurangi Jenis Barang\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanBarang(barang, jumlahBarang);
                break;
            case 2:
                tambahStok(barang, jumlahBarang);
                break;
            case 3:
                kurangiStok(barang, jumlahBarang);
                break;
            case 4:
                tambahJenisBarang(barang, jumlahBarang, maxBarang);
                break;
            case 5:
                kurangiJenisBarang(barang, jumlahBarang);
                break;
            case 6:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}