#include <iostream>
#include <string>

using namespace std;

struct Barang {
    string nama;
    int stok;
    float harga;
    Barang* next; 
};


Barang* buatBarang(string nama, int stok, float harga) {
    Barang* baru = new Barang;
    baru->nama = nama;
    baru->stok = stok;
    baru->harga = harga;
    baru->next = nullptr;
    return baru;
}


void hapusSemuaBarang(Barang* &head) {
    while (head != nullptr) {
        Barang* temp = head;
        head = head->next;
        delete temp;
    }
}

void jeda() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    system("cls");
}

void tampilkanBarang(Barang* head) {
    cout << "Daftar Barang di Toko:\n";
    int i = 1;
    while (head != nullptr) {
        cout << i << ". Nama: " << head->nama 
             << ", Stok: " << head->stok 
             << ", Harga: Rp " << head->harga << endl;
        head = head->next;
        i++;
    }
    jeda();
}

void tambahStok(Barang* head) {
    int index, jumlah;
    cout << "Daftar Barang di Toko:\n";
    int i = 1;

    Barang* temp = head;
    while (temp != nullptr) {
        cout << i << ". Nama: " << temp->nama 
             << ", Stok: " << temp->stok 
             << ", Harga: Rp " << temp->harga << endl;
        temp = temp->next;
        i++;
    }
    
    cout << "Pilih nomor barang yang ingin ditambahkan stok: ";
    cin >> index;

    Barang* current = head;
    for (int i = 1; i < index && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        cout << "Masukkan jumlah stok yang ingin ditambahkan: ";
        cin >> jumlah;
        current->stok += jumlah;
        cout << "Stok berhasil ditambahkan!\n";
    } else {
        cout << "Barang tidak ditemukan!\n";
    }
    jeda();
}

void kurangiStok(Barang* head) {
    int index, jumlah;
    tampilkanBarang(head);
    cout << "Pilih nomor barang yang ingin dikurangi stok: ";
    cin >> index;

    Barang* current = head;
    for (int i = 1; i < index && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        cout << "Masukkan jumlah stok yang ingin dikurangi: ";
        cin >> jumlah;
        if (current->stok >= jumlah) {
            current->stok -= jumlah;
            cout << "Stok berhasil dikurangi!\n";
        } else {
            cout << "Stok tidak cukup!\n";
        }
    } else {
        cout << "Barang tidak ditemukan!\n";
    }
    jeda();
}

void tambahJenisBarang(Barang* &head) {
    string nama;
    int stok;
    float harga;

    cout << "Masukkan nama barang baru: ";
    cin.ignore(); 
    getline(cin, nama); 
    cout << "Masukkan jumlah stok: ";
    cin >> stok; 
    cout << "Masukkan harga barang: ";
    cin >> harga;

    Barang* baru = buatBarang(nama, stok, harga);

    if (head == nullptr) {
        head = baru;
    } else {
        Barang* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = baru;
    }

    cout << "Barang baru berhasil ditambahkan!\n";
    jeda();
}

void kurangiJenisBarang(Barang* &head) {
    if (head == nullptr) {
        cout << "Tidak ada barang yang bisa dihapus!\n";
        jeda();
        return;
    }

    tampilkanBarang(head);
    int index;
    cout << "Pilih nomor barang yang ingin dihapus: ";
    cin >> index;

    if (index == 1) {
        Barang* temp = head;
        head = head->next;
        delete temp;
    } else {
        Barang* current = head;
        for (int i = 1; i < index - 1 && current->next != nullptr; i++) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Barang* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            cout << "Nomor barang tidak valid!\n";
        }
    }

    cout << "Barang berhasil dihapus!\n";
    jeda();
}

int main() {
    Barang* head = nullptr;

    head = buatBarang("Beras", 20, 10000);
    head->next = buatBarang("Gula", 15, 12000);
    head->next->next = buatBarang("Minyak Goreng", 10, 14000);

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
                tampilkanBarang(head);
                break;
            case 2:
                tambahStok(head);
                break;
            case 3:
                kurangiStok(head);
                break;
            case 4:
                tambahJenisBarang(head);
                break;
            case 5:
                kurangiJenisBarang(head);
                break;
            case 6:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 6);

    hapusSemuaBarang(head);

    return 0;
}
