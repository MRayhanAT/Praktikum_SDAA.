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


Barang* merge(Barang* left, Barang* right) {
    if (!left) return right;
    if (!right) return left;

    Barang* result = nullptr;

    
    if (left->harga <= right->harga) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void split(Barang* source, Barang*& left, Barang*& right) {
    if (!source || !source->next) {
        left = source;
        right = nullptr;
        return;
    }

    Barang* slow = source;
    Barang* fast = source->next;

    
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    left = source;
    right = slow->next;
    slow->next = nullptr;  
}

void mergeSort(Barang*& head) {
    if (!head || !head->next) return;  

    Barang* left = nullptr;
    Barang* right = nullptr;

    
    split(head, left, right);

    
    mergeSort(left);
    mergeSort(right);

    
    head = merge(left, right);
}


void shellSort(Barang*& head) {
    if (!head) return;

    
    int n = 0;
    Barang* current = head;
    while (current) {
        n++;
        current = current->next;
    }

    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Barang* currentI = head;
            Barang* currentGap = head;
            for (int j = 0; j < i; j++) {
                if (j < gap) {
                    currentI = currentI->next;
                }
                currentGap = currentGap->next;
            }

            
            if (currentI->harga < currentGap->harga) {
                swap(currentI->harga, currentGap->harga);
                swap(currentI->nama, currentGap->nama);
                swap(currentI->stok, currentGap->stok);
            }
        }
    }
}


int main() {
    Barang* head = nullptr;
    stack<string> barangStack;
    queue<string> barangQueue;

    
    Barang* barang1 = buatBarang("Beras", 50, 10000);
    Barang* barang2 = buatBarang("Gula", 200, 5000);
    Barang* barang3 = buatBarang("Sayur", 75, 3000);
    Barang* barang4 = buatBarang("Kopi", 30, 15000);

    head = barang1;
    barang1->next = barang2;
    barang2->next = barang3;
    barang3->next = barang4;

    int pilihan;
    do {
        cout << "Menu:\n";
        cout << "1. Tampilkan Barang\n";
        cout << "2. Tambah Stok\n";
        cout << "3. Kurangi Stok\n";
        cout << "4. Tambah Jenis Barang\n";
        cout << "5. Kurangi Jenis Barang\n";
        cout << "6. Urutkan Barang berdasarkan Harga (Merge Sort)\n";
        cout << "7. Urutkan Barang berdasarkan Harga (Shell Sort)\n";
        cout << "8. Tambah Barang ke Stack\n";
        cout << "9. Hapus Barang dari Stack\n";
        cout << "10. Tampilkan Stack\n";
        cout << "11. Tambah Barang ke Queue\n";
        cout << "12. Hapus Barang dari Queue\n";
        cout << "13. Tampilkan Queue\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
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
                mergeSort(head);
                cout << "Barang berhasil diurutkan berdasarkan harga menggunakan Merge Sort!\n";
                jeda();
                break;
            case 7:
                shellSort(head);
                cout << "Barang berhasil diurutkan berdasarkan harga menggunakan Shell Sort!\n";
                jeda();
                break;
            case 8:
                tambahKeStack(barangStack);
                break;
            case 9:
                hapusDariStack(barangStack);
                break;
            case 10:
                cetakStack(barangStack);
                break;
            case 11:
                tambahKeQueue(barangQueue);
                break;
            case 12:
                hapusDariQueue(barangQueue);
                break;
            case 13:
                cetakQueue(barangQueue);
                break;
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                jeda();
                break;
        }
    } while (pilihan != 0);

    hapusSemuaBarang(head);
    return 0;
}
