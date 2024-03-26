// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    // komponen/member
    string nama;
    int usia;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    return head == NULL;
}

// Tambah Depan
void insertDepan(string nama, int usia) {
    // Buat Node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(string nama, int usia) {
    // Buat Node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Tambah Tengah
void insertTengah(string nama, int usia, string namaSebelum) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;

    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }

    Node *bantu = head;
    while (bantu != NULL && bantu->nama != namaSebelum) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    baru->next = bantu->next;
    bantu->next = baru;
}

// Hapus Node dengan nama tertentu
void hapus(string nama) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }

    Node *hapus;
    Node *bantu;

    // Jika data yang akan dihapus adalah data pertama
    if (head->nama == nama) {
        hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    // Traverse hingga menemukan data atau sampai akhir list
    bantu = head;
    while (bantu->next != NULL && bantu->next->nama != nama) {
        bantu = bantu->next;
    }

    // Jika data ditemukan
    if (bantu->next != NULL) {
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

// Ubah data
void ubahData(string nama, string namaBaru, int usiaBaru) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }

    Node *bantu = head;
    while (bantu != NULL && bantu->nama != nama) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        bantu->nama = namaBaru;
        bantu->usia = usiaBaru;
    }
}

// Tampilkan seluruh data
void tampilkan() {
    Node *bantu = head;
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }
    while (bantu != NULL) {
        cout << bantu->nama << " " << bantu->usia << endl;
        bantu = bantu->next;
    }
}

int main() {
    init();

    // a. Masukkan data sesuai urutan berikut
    insertDepan("Igor", 20);
    insertDepan("wildan", 19);
    insertBelakang("John", 19);
    insertTengah("Futaba", 18, "John");
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);
    hapus("Akechi");
    insertTengah("Futaba", 18, "John");
    insertDepan("Igor", 20);
    ubahData("Michael", "Reyn", 18);
    cout << "Data Mahasiswa:" << endl;
    tampilkan();

    return 0;
}
