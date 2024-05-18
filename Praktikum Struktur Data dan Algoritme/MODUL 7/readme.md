# <h1 align="center"> Laporan Praktikum Modul Queue </h1>

## Dasar Teori

Algoritma Queue
Algoritma adalah metode efektif yang diekspresikan sebagai rangkaian terbatas. Algoritma juga meruapakan kumpulan perintah untuk menyelesaikan suatu masalah.
Perintah-perintah ini dapat diterjemahkan secara bertahap dari awal hingga akhir. Masalah tersebut dapat berupa apa saja,
dengan syarat untuk setiap permasalahan memiliki kriteria kondisi awal yang harus dipenuhi sebelum menjalankan sebuah algoritma.
Algoritma juga memiliki pengualangan proses (iterasi), dan juga memiliki keputusan hingga keputusan selesai[1].(Maulana, 2017) 

Queue atau antrian adalah suatu jenis struktur data yang dapat diproses dengan sifat FIFO (First In First Out), dimana elemen yang pertama kali masuk ke antrian akan keluar pertama kali.
Ada dua jenis operasi yang bisa dilakukan di antrian: enqueue (memasukkan elemen baru ke dalam elemen) dan dequeue (adalah mengeluarkan satu elemen dari suatu antrian).
Antrian dapat dibuat dengan menggunakan: Linear Array dan Circular Array 

First-In First-Out (FIFO) adalah sebuah metode pemecahan dalam masalah antrian yang dapat diterapkan dengan cara laporan pengaduan yang pertama kali masuk diasumsikan keluar pertama kali.
Hal ini sudah berjalan sesuai dengan mekanisme antrian pada umumnya, dimana antrian yang pertama kali masuk akan diselesaikan atau dilayani terlebih dahulu.
Penggunaan algoritma FIFO ini dimaksudkan agar urutan antrian pasien tetap pada urutan yang benar tanpa merubah urutan yang sudah ada.
Penerapan algoritma ini membuat tidak mungkin pasien dapat melakukan kecurangan terhadap antrian yang dapat menimbulkan masalah yang sama seperti ketika antrian dijalankan secara offline atau luring[2].

## Guided

### Guided 1

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
        queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
            } else {
                cout << i + 1 << ". (kosong)" << endl;
            }
    }
}

int main() {
enqueueAntrian("Andi");
enqueueAntrian("Maya");
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
dequeueAntrian();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
clearQueue();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
return 0;
}
```

#### Outout Guided 1
![Output Guided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%207/GAMBAR/Output%20Guided.png)

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr; 
Node* back = nullptr;  

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Node* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". " << current->data << endl;
        current = current->next;
        i++;
    }
    if (i == 1) {
        cout << "Antrian kosong" << endl;
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}

```
![Output Unguided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%207/GAMBAR/Output%20Unguided1.png)

Kode di atas

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
using namespace std;

struct Node {
    string namaMahasiswa; 
    string nimMahasiswa; 
    Node* next;
};

Node* front = nullptr; 
Node* back = nullptr; 

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim) {
    Node* newNode = new Node();
    newNode->namaMahasiswa = nama;
    newNode->nimMahasiswa = nim;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Node* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". Nama: " << current->namaMahasiswa 
             << ", NIM: " << current->nimMahasiswa << endl;
        current = current->next;
        i++;
    }
    if (i == 1) {
        cout << "Antrian kosong" << endl;
    }
}

int main() {
    enqueueAntrian("yanto", "233456");
    enqueueAntrian("yanti", "234321");
    enqueueAntrian("idan", "231114");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}

```
![Output Unguided 2](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%207/GAMBAR/Output%20Unguided%202%2C.png)

Kode di atas

## Kesimpulan


## Referensi
[1] 	A. Rizky, "LOGIC : Jurnal Ilmu Komputer dan Pendidikan," PENERAPAN ALGORITMA QUEUE PADA APLIKASI PEMESANAN OBAT BERBASIS MOBILE PADA
APOTEK ARUBA FARMA DEPOK, vol. 1, no. 5, pp. 1168-1177, 2023. 
[2] 	R. Gunawan, "Jurnal Mahasiswa Teknik Informatika," IMPLEMENTASI METODE QUEUE PADA SISTEM ANTRIAN ONLINE BERBASIS WEB STUDI KASUS UPTD
PUSKESMAS SANANWETAN, vol. 7, no. 3, pp. 1538-1545, 2023. 

