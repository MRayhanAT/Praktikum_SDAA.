#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>

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

int fibonacciSearch(Barang* head, int x) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < x) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    Barang* current = head;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, x - 1);
        for (int j = 0; j < i && current != nullptr; j++) {
            current = current->next;
        }

        if (current->stok < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
            current = head;
            for (int j = 0; j <= offset; j++) {
                current = current->next;
            }
        } else if (current->stok > x) {
            fibM = fibMMm2;
            fibMMm1 -= fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return offset + i;
        }
    }

    if (fibMMm1 && current->stok == x) {
        return offset + 1;
    }
    return -1;
}

int jumpSearch(Barang* head, float x, int n) {
    int step = sqrt(n);
    int prev = 0;
    Barang* current = head;
    for (int i = 0; i < step && current != nullptr; i++) {
        current = current->next;
    }
    while (current->harga < x && prev < n) {
        prev = step;
        for (int i = 0; i < step && current != nullptr; i++) {
            current = current->next;
        }
        if (prev >= n) {
            return -1;
        }
    }
    while (current->harga < x && prev < n) {
        prev++;
                current = current->next;
    }
    if (current->harga == x) {
        return prev;
    }
    return -1;
}

int boyerMooreSearch(Barang* head, string pattern) {
    int m = pattern.length();
    int n = 0;
    Barang* current = head;

    while (current != nullptr) {
        n++;
        current = current->next;
    }

    current = head;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (current->nama[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i; 
        }
        current = current->next;
    }
    return -1;
}

int main() {
    Barang* head = nullptr;
    Barang* barang1 = buatBarang("Beras", 50, 10000);
    Barang* barang2 = buatBarang("Gula", 200, 5000);
    Barang* barang3 = buatBarang("Sayur", 75, 3000);
    Barang* barang4 = buatBarang("Kopi", 30, 15000);

    head = barang1;
    barang1->next = barang2;
    barang2->next = barang3;
    barang3->next = barang4;

    stack<string> barangStack;
    queue<string> barangQueue;

    int pilihan;
    do {
        cout << "Menu:\n";
        cout << "1. Tampilkan Barang\n";
        cout << "2. Tambah Stok Barang\n";
        cout << "3. Kurangi Stok Barang\n";
        cout << "4. Tambah Jenis Barang\n";
        cout << "5. Kurangi Jenis Barang\n";
        cout << "6. Tambah ke Stack\n";
        cout << "7. Hapus dari Stack\n";
        cout << "8. Cetak Stack\n";
        cout << "9. Tambah ke Queue\n";
        cout << "10. Hapus dari Queue\n";
        cout << "11. Cetak Queue\n";
        cout << "12. Cari Stok dengan Fibonacci Search\n";
        cout << "13. Cari Harga dengan Jump Search\n";
        cout << "14. Cari Nama dengan Boyer-Moore Search\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilkanBarang(head); break;
            case 2: tambahStok(head); break;
            case 3: kurangiStok(head); break;
            case 4: tambahJenisBarang(head); break;
            case 5: kurangiJenisBarang(head); break;
            case 6: tambahKeStack(barangStack); break;
            case 7: hapusDariStack(barangStack); break;
            case 8: cetakStack(barangStack); break;
            case 9: tambahKeQueue(barangQueue); break;
            case 10: hapusDariQueue(barangQueue); break;
            case 11: cetakQueue(barangQueue); break;
            case 12: {
                int stok;
                cout << "Masukkan stok yang dicari: ";
                cin >> stok;
                int index = fibonacciSearch(head, stok);
                if (index != -1) {
                    cout << "Stok " << stok << " ditemukan pada indeks " << index << endl;
                } else {
                    cout << "Stok " << stok << " tidak ditemukan." << endl;
                }
                jeda();
                break;
            }
            case 13: {
                float harga;
                cout << "Masukkan harga yang dicari: ";
                cin >> harga;
                int index = jumpSearch(head, harga, 4);
                if (index != -1) {
                    cout << "Harga " << harga << " ditemukan pada indeks " << index << endl;
                } else {
                    cout << "Harga " << harga << " tidak ditemukan." << endl;
                }
                jeda();
                break;
            }
            case 14: {
                string pattern;
                cout << "Masukkan nama barang yang dicari: ";
                cin.ignore();
                getline(cin, pattern);
                int index = boyerMooreSearch(head, pattern);
                if (index != -1) {
                    cout << "Nama barang \"" << pattern << "\" ditemukan pada indeks " << index << endl;
                } else {
                    cout << "Nama barang \"" << pattern << "\" tidak ditemukan." << endl;
                }
                jeda();
                break;
            }
            case 0: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid.\n"; jeda();
        }
    } while (pilihan != 0);

    hapusSemuaBarang(head);
    return 0;
}

