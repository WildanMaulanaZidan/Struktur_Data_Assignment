# <h1 align="center"> LAPORAN PRAKTIKUM MODUL 3 SINGLE AND DOUBLE LINKED LIST </h1>

## Dasar Teori

### Single Linked List
Linked List adalah salah satu bentuk struktur data, berisi kumpulan data
(node) yang tersusun secara sekuensial, saling sambungmenyambung,
dinamis dan terbatas.
- Linked List sering disebut juga Senarai Berantai
- Linked List saling terhubung dengan bantuan variabel pointer
- Masing-masing data dalam Linked List disebut dengan node (simpul) yang
menempati alokasi memori secara dinamis dan biasanya berupa struct
yang terdiri dari beberapa field.
Single Linked List adalah sebuah LINKED LIST yang menggunakan sebuah variabel
pointer saja untuk menyimpan banyak data dengan metode LINKED LIST, suatu
daftar isi yang saling berhubungan.
Single Linked List adalah sekumpulan dari node yang saling terhubung dengan node
lain melalui sebuah pointer.
Single Linked List hanya memiliki satu arah dan tidak memiliki dua arah atau bulak
balik, dua arah tersebut disebut dengan double linked list.
Pada Implementasinya, Single Linked List terdapat dua variasi yaitu circular dan noncircular[1].

### Double linked list
Linked List adalah suatu struktur data linier. linked list dibentuk secara dinamik. Pada
saat awal program dijalankan elemen linked list belum data. Elemen linked list
(disebut node) dibentuk sambil jalan sesuai instruksi. sebuah node linked list diakses
dengan menggunakan pointer yang mengacu ke node tersebut.
Banyak yang mengira Double Linked List Circulate adalah Double Linked List
Circulate pointer next dan prev nya menunjuk ke dirinya sendiri secara circular.
Memang benar demikian tapi Double Linked List Circulate tidak hanya itu saja[2].

## Guided

### 1. Guided 1 Latihan Single Linked List
``` C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Kode di atas ini memiliki fungsi untuk inisialisasi linked list, menambahkan elemen
di depan, belakang, dan tengah, menghitung jumlah elemen, menghapus elemen didepan, belakang, dan tengah, 
serta mengubah nilai elemen di depan, belakang, dan tengah.

### 2. Guided 2 Latihan Double Linked List
``` C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Kode di atas merupakan double linked list adalah struktur data linear di mana setiap elemen memiliki pointer ke elemen sebelumnya dan setelahnya. kode ini memungkinkan pengguna untuk melakukan berbagai operasi seperti menambahkan data ke awal daftar, menghapus data dari awal daftar, memperbarui data, menghapus semua data, dan menampilkan isi dari daftar. 

## Unguided

### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk
menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan
dari user. Lakukan operasi berikut:
    a. Masukkan data sesuai urutan berikut. (Gunakan insert depan,
    belakang atau tengah). Data pertama yang dimasukkan adalah
    nama dan usia anda.
        [Nama_anda] [Usia_anda]
        John 19
        Jane 20
        Michael 18
        Yusuke 19
        Akechi 20
        Hoshino 18
        Karin 18
    b. Hapus data Akechi
    c. Tambahkan data berikut diantara John dan Jane : Futaba 18
    d. Tambahkan data berikut diawal : Igor 20
    e. Ubah data Michael menjadi : Reyn 18
    f. Tampilkan seluruh data

``` C++
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
```
### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan
operasi untuk menambah data, menghapus, dan update di tengah / di
urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya
menampilkan Nama produk dan harga.
Nama Produk Harga
Originote 60.000
Somethinc 150.000
Skintific 100.000
Wardah 50.000
Hanasui 30.000

Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini
  Toko Skincare Purwokerto
  1. Tambah Data
  2. Hapus Data
  3. Update Data
  4. Tambah Data Urutan Tertentu
  5. Hapus Data Urutan Tertentu
  6. Hapus Seluruh Data
  7. Tampilkan Data
  8. Exit
  Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
  ini :

Nama Produk Harga
Originote 60.000
Somethinc 150.000
Azarine 65.000
Skintific 100.000
Cleora 55.000

``` C++
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
```
#### Output Guided 1
![Output Unguided 1]()
Kode ini memiliki fungsi-fungsi seperti inisialisasi, pengecekan kekosongan,
penambahan depan, belakang, tengah dan penghapusan data, serta tampilkan data
keseluruhan. 

#### Output Guided 2
![Output Unguided 2]()
Kode ini adalah sebuah program manajemen toko skincare yang menggunakan linked list untuk menyimpan data produk-produk skincare beserta harganya. 
Kode ini memungkinkan pengguna untuk menambahkan data produk baru, menghapus data produk, mengubah data produk, menambahkan data produk pada urutan tertentu, menghapus data produk pada urutan tertentu, menghapus seluruh data produk, dan menampilkan seluruh data produk yang tersimpan.

#### Full Code Screnshoot
![Output Full Code Screnshoot]()

## Kesimpulan

## Referensi
[1]
[2]

