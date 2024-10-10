#include <iostream>
#include <string>
#include <stack>
#include <queue>

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

void tambahKeStack(stack<string> &barangStack) {
    string namaBarang;
    cout << "Masukkan Nama Barang: ";
    cin.ignore(); 
    getline(cin, namaBarang);
    barangStack.push(namaBarang);

    cout << "Barang " << namaBarang << " berhasil ditambahkan ke Stack.\n";
    jeda();
}

void hapusDariStack(stack<string> &barangStack) {
    if (!barangStack.empty()) {
        string topBarang = barangStack.top();
        cout << "Barang " << topBarang << " dikeluarkan dari Stack.\n";
        barangStack.pop();
    } else {
        cout << "Stack kosong!\n";
    }
    jeda();
}

void cetakStack(stack<string> barangStack) {
    if (barangStack.empty()) {
        cout << "Stack kosong!\n";
    } else {
        cout << "Isi Stack (dari atas ke bawah):\n";
        while (!barangStack.empty()) {
            string topBarang = barangStack.top();
            cout << "Nama: " << topBarang << endl;
            barangStack.pop();
        }
    }
    jeda();
}

void tambahKeQueue(queue<string> &barangQueue) {
    string namaBarang;
    cout << "Masukkan Nama Barang: ";
    cin.ignore(); 
    getline(cin, namaBarang); 
    barangQueue.push(namaBarang);

    cout << "Barang " << namaBarang << " berhasil ditambahkan ke Queue.\n";
    jeda();
}

void hapusDariQueue(queue<string> &barangQueue) {
    if (!barangQueue.empty()) {
        string frontBarang = barangQueue.front();
        cout << "Barang " << frontBarang << " dikeluarkan dari Queue.\n";
        barangQueue.pop();
    } else {
        cout << "Queue kosong!\n";
    }
    jeda();
}

void cetakQueue(queue<string> barangQueue) {
    if (barangQueue.empty()) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Isi Queue (dari depan ke belakang):\n";
        while (!barangQueue.empty()) {
            string frontBarang = barangQueue.front();
            cout << "Nama: " << frontBarang << endl;
            barangQueue.pop(); 
        }
    }
    jeda();
}

int main() {
    Barang* head = nullptr;
    stack<string> barangStack; // Stack menyimpan nama barang
    queue<string> barangQueue; // Queue menyimpan nama barang

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
        cout << "6. Tambah Barang ke Stack\n";
        cout << "7. Keluarkan Barang dari Stack\n";
        cout << "8. Print Stack\n";
        cout << "9. Tambah Barang ke Queue\n";
        cout << "10. Keluarkan Barang dari Queue\n";
        cout << "11. Print Queue\n";
        cout << "12. Keluar\n";
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
                tambahKeStack(barangStack);
                break;
            case 7:
                hapusDariStack(barangStack);
                break;
            case 8:
                cetakStack(barangStack);
                break;
            case 9:
                tambahKeQueue(barangQueue);
                break;
            case 10:
                hapusDariQueue(barangQueue);
                break;
            case 11:
                cetakQueue(barangQueue);
                break;
            case 12:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 12);

    hapusSemuaBarang(head);

    return 0;
}
