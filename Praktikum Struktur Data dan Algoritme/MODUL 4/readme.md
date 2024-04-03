# <h1 align="center"> LAPORAN PRAKTIKUM MODUL 4 LINKED LIST CIRCULAR DAN NON CIRCULAR </h1>

## Dasar Teori
### Linked List Circular

Linked List Circular, seperti single linked list atau double dengan simpul pertama, "head", dan simpul terakhir, "tail", terhubung.
Dalam single linked list atau double, kita dapat menemukan awal dan akhir daftar hanya dengan memeriksa apakah tautannya NULL. 
Namun untuk Linked List Circular , diperlukan kode yang lebih kompleks untuk secara eksplisit memeriksa node awal dan akhir dalam aplikasi tertentu.
Linked List Circular cocok untuk daftar yang perlu Anda putar terus-menerus. [1]

### Linked List NON Circular

Linked list adalah strukur data linier berbentuk rantai simpul di mana setiap simpul menyimpan 2 item, 
yaitu nilai data dan pointer ke simpul elemen berikutnya. 
Berbeda dengan array, elemen linked list tidak ditempatkan dalam alamat memori yang berdekatan melainkan elemen ditautkan menggunakan pointer.
Ukuran elemen dari linked list dapat bertambah secara dinamis dan mudah untuk menyisipkan dan menghapus elemen karena tidak seperti array,
kita hanya perlu mengubah pointer elemen sebelumnya dan elemen berikutnya untuk menyisipkan atau menghapus elemen.[2]

## Guided

### 1. Linked List NON Circular

```C++
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
### Output
![Output Guided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20Guided1.png)

Kode diatas merupakan implementasi dari penggunaan single linked list non circular. 
Di dalam kode tersebut terdapat banyak prosedur dan fungsi untuk mengolah single linked list seperti Insert, Delete, Update, countList.
Masing-masing memiliki kegunaanya sendiri, seperti namanya Menambahkan data, Menghapus data, Mengupdate data,
baik di depan atau belakang atau tengah serta lainya.

### 2. Linked List Circular
```C++
// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi struct Node
struct Node{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

// pengecekan 
int isEmpty(){
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data){
    baru = new Node;
    baru ->data = data;
    baru -> next = NULL;
}

// Hitung List
int hitungList(){
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL){
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;

}

// Tambah Depan
void insertDepan(string data){
    // buat node baru
    buatNode(data);

    if(isEmpty() == 1){
        head = baru; 
        tail = head;
        baru->next = head;
    }else{
        while(tail -> next != head){
            tail = tail ->next;
        }
        baru -> next = head;
        head = baru;
        tail ->next =head;
    }
}

// Tambah Belakang 
void insertBelakang(string data){
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1){
        head= baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail ->next != head){
            tail = tail ->next;
        }
        tail ->next = baru;
        baru ->next = head;
    }
}

// Tambah Tengah 
void insertTengah (string data, int posisi){
    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru -> next = head;
    } else {
        baru ->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi -1){
            bantu = bantu -> next;
            nomor++;
        }
        baru ->next = bantu ->next;
        bantu ->next = baru;
    }
}

// Hapus Depan
void hapusDepan(){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;

        if (hapus -> next == head){
            head = NULL;
            tail = NULL;

            delete hapus;
        } else {
            while (tail -> next != hapus){
                tail = tail -> next;
            }
            head = head -> next;
            tail -> next = head;
            hapus -> next = NULL;

            delete hapus;
        }
    } else {
        cout << "List masih kosong!"<< endl;
    }
}

// Hapus Belakang
void hapusBelakang(){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;
        if (hapus->next == head){
            head = NULL;
            tail = NULL;

            delete hapus;
        } else {
            while (hapus ->next != head){
                hapus = hapus->next;
            }
            while ( tail->next != hapus){
                tail = tail ->next;
            }
            tail ->next = head;
            hapus -> next = NULL;

            delete hapus;
        }
    } else {
        cout << "list masih Kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi){
    if (isEmpty() == 0){
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList(){
    if (head != NULL){
        hapus = head->next;

        while (hapus != head){
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil (){
    if (isEmpty() == 0){
        tail = head;
        do {
            cout << tail ->data << endl;
            tail = tail ->next;
        } while (tail !=head);
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main (){
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```
### Output
![Output Guided 2](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20Guided2.png)

Kode diatas merupakan implementasi dari penggunaan single linked list circular. Di dalam kode tersebut terdapat banyak prosedur dan fungsiuntuk mengolah single linked list seperti Insert, Delete, Update, countList.
Masing-masing memiliki kegunaanya sendiri, seperti namanya Menambahkan data, Menghapus data, Mengupdate data, baik di depan atau belakang atau tengah serta lainya.
Yang membedakan dengan single linked list non circular terletak pada penyesuaian prosedur- prosedur, agar node next dari tail selalu mengarah ke head.

## Unguided

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:
```C++
// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class LinkedList {
private:
    Mahasiswa* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // tambah depan
    void tambahDepan(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
    }

    // tambah belakng 
    void tambahBelakang(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Mahasiswa* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // tambah tengah
    void tambahTengah(string nama, string nim, int posisi) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;

        if (posisi == 1 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Mahasiswa* temp = head;
        for (int i = 1; i < posisi - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ubah depan
    void ubahDepan(string nama, string nim) {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }
        head->nama = nama;
        head->nim = nim;
        cout << "Data berhasil diubah\n";
    }

    // ubah belakang
void ubahBelakang(string nama, string nim, int posisi) {
    if (head == nullptr) {
        cout << "List kosong\n";
        return;
    }

    Mahasiswa* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    if (posisi < 1 || posisi > count) {
        cout << "Posisi tidak valid\n";
        return;
    }

    temp = head;
    for (int i = 1; i < posisi; ++i) {
        temp = temp->next;
    }

    cout << "Masukkan Nama Baru : ";
    cin >> temp->nama;
    cout << "Masukkan NIM Baru : ";
    cin >> temp->nim;

    cout << "Data berhasil diubah\n";
}



    // ubah tengah
    void ubahTengah(string nama, string nim, int posisi) {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Mahasiswa* temp = head;
        for (int i = 1; i < posisi && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid\n";
            return;
        }

        temp->nama = nama;
        temp->nim = nim;
        cout << "Data berhasil diubah\n";
    }

// hapus depan
    void hapusDepan() {
    if (head == nullptr) {
        cout << "List sudah kosong\n";
        return;
    }
    Mahasiswa* temp = head;
    head = head->next;
    delete temp;
    }

// hapus belakang
    void hapusBelakang() {
    if (head == nullptr) {
        cout << "List sudah kosong\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Mahasiswa* temp = head;
    Mahasiswa* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = nullptr;
    }   

    // hapus tengah
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "List sudah kosong\n";
            return;
        }
        if (posisi == 1) {
            hapusDepan();
            return;
        }

        Mahasiswa* temp = head;
        Mahasiswa* prev = nullptr;
        for (int i = 1; i < posisi && temp != nullptr; ++i) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // tampilan data
    void tampilkanData() {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }
        Mahasiswa* temp = head;
        cout << "DATA MAHASISWA\n";
        cout << "NAMA\t\tNIM\n";
        while (temp != nullptr) {
            cout << temp->nama << "\t\t" << temp->nim << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList DataMahasiswa;

    // Menambahkan data sesuai urutan
    DataMahasiswa.tambahBelakang("Jawad", "23300001");
    DataMahasiswa.tambahBelakang("Wildan", "2311102162");
    DataMahasiswa.tambahBelakang("Farrel", "23300003");
    DataMahasiswa.tambahBelakang("Denis", "23300005");
    DataMahasiswa.tambahBelakang("Anis", "23300008");
    DataMahasiswa.tambahBelakang("Bowo", "23300015");
    DataMahasiswa.tambahBelakang("Gahar", "23300040");
    DataMahasiswa.tambahBelakang("Udin", "23300048");
    DataMahasiswa.tambahBelakang("Ucok", "23300050");
    DataMahasiswa.tambahBelakang("Budi", "23300099");

    int Pilih1_11;
    string nama, nim;
    int posisi;

    do {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. Tampilkan\n";
        cout << "0. Keluar\n";
        cout << "Pilih Operasi : ";
        cin >> Pilih1_11;

        switch (Pilih1_11) {
            case 1:
                cout << "-Tambah Depan-\n";
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                DataMahasiswa.tambahDepan(nama, nim);
                cout << "Data telah ditambahkan\n";
                break;
            case 2:
                cout << "-Tambah Belakang-\n";
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                DataMahasiswa.tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan\n";
                break;
            case 3:
                cout << "-Tambah Tengah-\n";
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                DataMahasiswa.tambahTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan\n";
                break;
            case 4:
                cout << "-Ubah Depan-\n";
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                DataMahasiswa.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "-Ubah Belakang-\n";
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                cout << "Masukan Posisi : ";
                cin >> posisi;
                DataMahasiswa.ubahBelakang(nama, nim, posisi);
                break;
            case 6:
                cout << "-Ubah Tengah-\n";
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                DataMahasiswa.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                cout << "-Hapus Depan-\n";
                DataMahasiswa.hapusDepan();
                cout << "Data berhasil dihapus\n";
                break;
            case 8:
                cout << "-Hapus Belakang-\n";
                DataMahasiswa.hapusBelakang();
                cout << "Data berhasil dihapus\n";
                break;
            case 9:
                cout << "-Hapus Tengah-\n";
                cout << "Masukkan posisi : ";
                cin >> posisi;
                DataMahasiswa.hapusTengah(posisi);
                cout << "Data berhasil dihapus\n";
                break;
            case 10:
                // Tambahkan kode untuk menghapus seluruh list
                break;
            case 11:
                DataMahasiswa.tampilkanData();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (Pilih1_11 != 0);

    return 0;
}

```
### Output
Tampilan Awal Program

![Tampilan Awal Program](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20Unguided1.png)

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![Output Unguided 2](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20Unguided1.2.png)

### 3. Lakukan printah berikut:
a) Penambahan data Wati 2330004 diantara Farrel dan Denis

![Output a](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20a.png)


b) Hapus data denis

![Output b](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20b.png)


c) Tambahkan data berikut di awal: Owi 2330000

![Output c](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20c.png)


d) Tambahkan data berikut di akhir: David 2330010

![Output d](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20d.png)


e) Ubah data Udin menjadi data berikut: Idin 23300045

![Output e](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20e.png)


f) Ubah data terkahir menjadi berikut: Lucy 23300101

![Output f](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20f.png)


g) Hapus data awal

![Output g](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20g.png)


h) Ubah data awal menjadi berikut: Bagas 2330002

![Output h](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20h.png)


i) Hapus data akhir

![Output i](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20i.png)


j) Tampilkan seluruh data

![Output j](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%204/GAMBAR%20OUTPUT/Output%20j.png)
