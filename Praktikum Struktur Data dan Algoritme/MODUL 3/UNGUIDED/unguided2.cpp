// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
using namespace std;

struct Node {
    string namaProduk;
    int harga;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

// Fungsi untuk menambahkan data di akhir linked list
void tambahData(string nama, int harga) {
    Node* newNode = new Node;
    newNode->namaProduk = nama;
    newNode->harga = harga;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Fungsi untuk menampilkan data
void tampilkanData() {
    Node* current = head;
    if (current == NULL) {
        cout << "Tidak ada data yang tersedia" << endl;
        return;
    }

    cout << "Nama Produk\t\tHarga" << endl;
    while (current != NULL) {
        cout << current->namaProduk << "\t\t\t" << current->harga << endl;
        current = current->next;
    }
}

// Fungsi untuk menambahkan data di urutan tertentu
void tambahDataUrutanTertentu(string nama, int harga, string namaSebelumnya) {
    Node* newNode = new Node;
    newNode->namaProduk = nama;
    newNode->harga = harga;

    Node* current = head;
    while (current != NULL && current->namaProduk != namaSebelumnya) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Produk sebelumnya tidak ditemukan" << endl;
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    if (current == tail) {
        tail = newNode;
    }
}

// Fungsi untuk menghapus data
void hapusData(string nama) {
    if (head == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    Node* current = head;
    while (current != NULL && current->namaProduk != nama) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Produk tidak ditemukan" << endl;
        return;
    }

    if (current->prev == NULL) {
        head = current->next;
    } else {
        current->prev->next = current->next;
    }

    if (current->next == NULL) {
        tail = current->prev;
    } else {
        current->next->prev = current->prev;
    }

    delete current;
}


// Fungsi untuk mengubah data
void updateData(string nama, string namaBaru, int hargaBaru) {
    Node* current = head;
    while (current != NULL && current->namaProduk != nama) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Produk tidak ditemukan" << endl;
        return;
    }

    current->namaProduk = namaBaru;
    current->harga = hargaBaru;
}

int main() {
    // Menambahkan data awal
    tambahData("Originote", 60000);
    tambahData("Somethinc", 150000);
    tambahData("Skintific", 100000);
    tambahData("Wardah", 50000);
    tambahData("Hanasui", 30000);

    int pilihan;
    string nama, namaSebelumnya;
    int harga;

    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "\t1. Tambah Data" << endl;
        cout << "\t2. Hapus Data" << endl;
        cout << "\t3. Update Data" << endl;
        cout << "\t4. Tambah Data Urutan Tertentu" << endl;
        cout << "\t5. Hapus Data Urutan Tertentu" << endl;
        cout << "\t6. Hapus Seluruh Data" << endl;
        cout << "\t7. Tampilkan Data" << endl;
        cout << "\t8. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin >> nama;
                cout << "Masukkan harga: ";
                cin >> harga;
                tambahData(nama, harga);
                break;
            case 2:
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> nama;
                hapusData(nama);
                break;
            case 3:
                cout << "Masukkan nama produk yang akan diubah: ";
                cin >> nama;
                cout << "Masukkan nama produk baru: ";
                cin >> namaSebelumnya;
                cout << "Masukkan harga baru: ";
                cin >> harga;
                updateData(nama, namaSebelumnya, harga);
                break;
            case 4:
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> nama;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan nama produk sebelumnya: ";
                cin >> namaSebelumnya;
                tambahDataUrutanTertentu(nama, harga, namaSebelumnya);
                break;
            case 5:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama;
                hapusData(nama);
                break;
            case 6:
                while (head != NULL) {
                    hapusData(head->namaProduk);
                }
                cout << "Seluruh data berhasil dihapus" << endl;
                break;
            case 7:
                cout << endl;
                tampilkanData();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);

    return 0;
}
