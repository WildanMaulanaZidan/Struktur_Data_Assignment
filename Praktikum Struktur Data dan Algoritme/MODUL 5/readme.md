# <h1 align="center"> LAPORAN PRAKTIKUM MODUL 5 HASH TABLE </h1>

## Dasar Teori

### HASH TABLE 
Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini,
data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri.
Akses data akan menjadi sangat cepat jika Anda mengetahui indeks dari data yang diinginkan.

Dengan demikian, hash table menjadi struktur data di mana operasi penyisipan dan pencarian data terjadi sangat cepat terlepas dari ukuran data tersebut.
Hash table menggunakan array sebagai media penyimpanan dan tekniknya untuk menghasilkan indeks suatu elemen yang dimasukkan atau ditempatkan.

### FUNGSI HASH TABLE PADA DATA
Fungsi utamanya pada data adalah mempercepat proses akses data. Hal ini berkaitan dengan
peningkatan data dalam jumlah besar yang diproses oleh jaringan data global dan lokal.
Hash table adalah solusi untuk membuat proses akses data lebih cepat dan memastikan bahwa data dapat dipertukarkan dengan aman.

Di dalam banyak bidang, hash table dikembangkan dan digunakan karena menawarkan kelebihan dalam efisiensi waktu operasi,
mulai dari pengarsipan hingga pencarian data. Contohnya adalah bidang jaringan komputer yang mengembangkannya menjadi hybrid open hash table,
yang kemudian dipakai untuk memproses jaringan komputer.

### CARA MEMBUAT HASH TABLE 
Untuk membuat hash table, sepotong memori perlu diblokir dengan cara yang sama seperti saat membuat array.
Anda perlu membuat indeks yang didasarkan pada kunci dengan menggunakan fungsi hash karena indeks yang dihasilkan harus sesuai dengan potongan memori.

Ada dua pemeriksaan yang dibutuhkan saat menempatkan data baru pada hash table, yaitu nilai hash dari kunci dan bagaimana nilainya dibandingkan dengan objek lain.
Pemeriksaan ini diperlukan saat membuatnya dengan Python karena saat data dimasukkan, kunci akan di-hash dan di-mask agar diubah menjadi larik atau indeks yang efisien.

### TEKNIK-TEKNIK HASH TABLE
1. HASHING
   Hashing merupakan sebuah proses mengganti kunci yang diberikan atau string karakter menjadi nilai lain. Penggunaan hashing paling populer adalah pada hash table.
   Hash table menyimpan pasangan kunci dan nilai dalam daftar yang dapat diakses melalui indeksnya. Karena pasangan kunci dan nilai tidak terbatas,
   maka fungsinya akan memetakan kunci ke ukuran tabel dan kemudian nilainya menjadi indeks untuk elemen tertentu.

2. LINEAR PROBING
   Linear probing merupakan skema dalam pemrograman komputer untuk menyelesaikan collision pada hash table. Dalam skema ini,
   setiap sel dari hash table menyimpan satu pasangan kunci-nilai. Saat fungsi hash menyebabkan collision dengan memetakan kunci baru ke sel hash table yang sudah ditempati oleh kunci lain,
   maka linear probing akan mencari tabel untuk lokasi bebas terdekat dan menyisipkan kunci baru.

   Pencarian dilakukan dengan cara yang sama, yaitu dengan mencari tabel secara berurutan, mulai dari posisi yang diberikan oleh fungsi hash,
   hingga menemukan sel dengan kunci yang cocok atau sel kosong. Hash table adalah struktur data non trivial yang paling umum digunakan.
   Linear probing dapat memberikan kinerja tinggi karena lokasi referensi yang baik, namun lebih sensitif terhadap kualitas fungsi hash daripada beberapa skema resolusi collision lainnya [1].

## GUIDED 

### Guided 1

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value),
next(nullptr) {}
};

// Class hash table

class HashTable {
    private:
        Node** table;
    public:
        HashTable() {
            table = new Node*[MAX_SIZE]();
}
~HashTable() {
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
    }
}
delete[] table;
}

// Insertion
void insert(int key, int value) {
    int index = hash_func(key);
    Node* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    Node* node = new Node(key, value);
    node->next = table[index];
    table[index] = node;
}

// Searching
int get(int key) {
    int index = hash_func(key);
    Node* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

// Deletion
void remove(int key) {
    int index = hash_func(key);
    Node* current = table[index];
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Traversal
void traverse() {
    for (int i = 0; i < MAX_SIZE; i++) {
    Node* current = table[i];
    while (current != nullptr) {
        cout << current->key << ": " << current->value
<< endl;   

current = current->next;

            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();
    
    return 0;
}
```
#### Output Guided 1
![Output Guided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%205/GAMBAR/output%20guided%201.png)

Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam
hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node
merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan
modulus untuk memetakan setiap input kunci ke nilai indeks array.

### Guided 2

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it !=
table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name) {
    int hash_val = hashFunc(name);
    for (auto node : table[hash_val]) {
        if (node->name == name) {
            return node->phone_number;
        }
    }
    return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " <<
pair->phone_number << "]";
                }
                }
                cout << endl;
        }
    }
};

int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : "
<<employee_map.searchByName("Mistah") << endl;
cout << "Phone Hp Pastah : "
<<employee_map.searchByName("Pastah") << endl;

employee_map.remove("Mistah");

cout << "Nomer Hp Mistah setelah dihapus : "
<<employee_map.searchByName("Mistah") << endl << endl;

cout << "Hash Table : " << endl;

employee_map.print();

return 0;
}
```
#### Output Guided 2
![Output Guided 2](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%205/GAMBAR/output%20guided%202.png)

Pada program di atas, class HashNode merepresentasikan setiap node dalam hash
table, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap
digunakan untuk mengimplementasikan struktur hash table dengan menggunakan
vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan
untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi
insert digunakan untuk menambahkan data baru ke dalam hash table.

## UNGUIDED

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : a. Setiap mahasiswa memiliki NIM dan nilai. b. Program memiliki tampilan pilihan menu berisi poin C. c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
// WILDAN MAULANA ZIDAN 
// 2311102162

#include <iostream>
#include <iomanip>

using namespace std;

// Struktur data untuk mewakili mahasiswa
struct Mahasiswa {
    int NIM;
    int nilai;
    Mahasiswa* next;

    Mahasiswa(int n, int v) : NIM(n), nilai(v), next(nullptr) {}
};

// Kelas untuk Hash Table
class HashTable {
private:
    static const int tableSize = 10;
    Mahasiswa* table[tableSize];

    // Fungsi hash sederhana
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable() {
        for (int i = 0; i < tableSize; ++i)
            table[i] = nullptr;
    }

    // Menambahkan data baru ke dalam hash table
    void tambahData(int NIM, int nilai) {
        int index = hashFunction(NIM);
        if (table[index] == nullptr) {
            table[index] = new Mahasiswa(NIM, nilai);
        } else {
            Mahasiswa* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Mahasiswa(NIM, nilai);
        }
    }

    // Menghapus data berdasarkan NIM
    void hapusData(int NIM) {
        int index = hashFunction(NIM);
        if (table[index] != nullptr) {
            Mahasiswa* temp = table[index];
            Mahasiswa* prev = nullptr;
            while (temp != nullptr && temp->NIM != NIM) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Data dengan NIM " << NIM << " tidak ditemukan." << endl;
                return;
            }
            if (prev == nullptr) {
                table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Data dengan NIM " << NIM << " telah dihapus." << endl;
        } else {
            cout << "Data dengan NIM " << NIM << " tidak ditemukan." << endl;
        }
    }

    // Mencari data berdasarkan NIM
    void cariDataByNIM(int NIM) {
        int index = hashFunction(NIM);
        Mahasiswa* temp = table[index];
        while (temp != nullptr) {
            if (temp->NIM == NIM) {
                cout << "Data ditemukan: NIM = " << temp->NIM << ", Nilai = " << temp->nilai << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Data dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    // Mencari data berdasarkan rentang nilai (80-90)
    void cariDataByRange() {
        cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
        for (int i = 0; i < tableSize; ++i) {
            Mahasiswa* temp = table[i];
            while (temp != nullptr) {
                if (temp->nilai >= 80 && temp->nilai <= 90) {
                    cout << "NIM = " << temp->NIM << ", Nilai = " << temp->nilai << endl;
                }
                temp = temp->next;
            }
        }
    }

    // Destruktor untuk membersihkan memori
    ~HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            Mahasiswa* temp = table[i];
            while (temp != nullptr) {
                Mahasiswa* next = temp->next;
                delete temp;
                temp = next;
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int choice;
    int NIM, nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa berdasarkan NIM\n";
        cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80-90)\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                hashTable.tambahData(NIM, nilai);
                break;
            case 2:
                cout << "Masukkan NIM untuk menghapus data: ";
                cin >> NIM;
                hashTable.hapusData(NIM);
                break;
            case 3:
                cout << "Masukkan NIM untuk mencari data: ";
                cin >> NIM;
                hashTable.cariDataByNIM(NIM);
                break;
            case 4:
                hashTable.cariDataByRange();
                break;
            case 5:
                cout << "Terima kasih, program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}
```
#### Output Unguided 1
![Output Unguided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%205/GAMBAR/output%20unguided%201.png)

Kode di atas digunakan untuk menyimpan data mahasiswa, setiap mahasiswa diwakili oleh struktur data dengan NIM dan nilai, dan data disimpan dalam hash table menggunakan fungsi hash sederhana. kode di atas menyediakan opsi menu untuk menambah data baru, menghapus data menggunakan NIM, mencari data menggunakan NIM, dan mencari data berdasarkan rentang nilai 80 sampai 90.

## Kesimpulan 
Hash table adalah stuktur data yang efisien untuk menyimpan dan mengakses data menggunakan fungsi hash. Pada aplikasi yang menggunakan cpp, hash table dapat digunakan untuk berbagai macam aplikasi, termasuk menyimpan data mahasiswa, seperti terlihat pada contoh program diatas. Dengan bantuan Hash table, kita dapat melakukan operasi pencarian dan penghapusan data dalam waktu yang relatif konstan, jika fungsi hash yang digunakan terdistribusu dengan baik. 

## Referensi
[1] algorit.ma, "Apa itu Hash Table dan Bagaimana Penggunaannya?," Algoritma Data Science School, 22 Maret 2022. [Online]. Available: https://algorit.ma/blog/hash-table-adalah-2022/. [Accessed 16 April 2024].




