# <h1 align="center"> LAPORAN PRAKTIKUM MODUL 1 TIPE DATA </h1>

## Dasar Teori

Tipe data adalah adalah sebuah pengklasifikasian data berdasarkan jenis data
tersebut. Tipe data dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah
data akan digunakan. Adapun tipe data yang akan dipelajari, sebagai berikut :
1. Tipe data Primitif
2. Tipe data Abstrak
3. Tipe data Koleksi

### 1.Tipe data Primitif
Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem, tipe data
primitif ini disediakan oleh banyak bahasa pemrograman, perbedaannya terletak pada
jumlah bit yang dialokasikan untuk setiap bit pada tipe data primitif tergantung pada
bahasa pemrograman,compiler dan sistem operasinya.

### 2.Tipe Data Abstrak
Tipe data abstrak atau yang biasa disebut Abstrak Data Tipe(ADT) merupakan
tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi
banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data.

### 3.Tipe Data Koleksi
Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk
mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe
data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah
besar data dengan cara yang terstruktur.

## Guided

### Guided 1 : tipe data primitif
```C++
#include <iostream>
using namespace std;

int main(){
    char op;
    float num1, num2;

    cin >> op;
    cin >> num1 >> num2;

    switch (op){
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '/':
            cout << num1 / num2;
            break;
        default:
        cout << "Error! operator is not correct";
    }

    return 0;
}
```
Kode di atas meminta pengguna untuk memasukkan operator matematika (+, -, *, atau /) dan dua angka. Kemudian, program ini menggunakan pernyataan switch-case untuk memilih operasi yang sesuai sesuai dengan operator yang dimasukkan. 

### Guided 2 : tipe data abstrak
```C++
#include <iostream>

struct Mahasiswa{
    const char *name;
    const char *address;
    int age;
};

int main(){
    struct Mahasiswa mhs1, mhs2;

    mhs1.name = "maomao";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "jishin";
    mhs2.address = "bandung";
    mhs2.age = 30;

    //Mencetak isi struck
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0; 
}
```
Kode di atas mendefinisikan sebuah struct Mahasiswa dengan tiga atribut: name, address, dan age. Variabel mhs1 dan mhs2 dari tipe Mahasiswa dideklarasikan dan diinisialisasi dalam main(). Informasi tentang kedua mahasiswa dicetak menggunakan printf()

### Guided 3 : tipe data koleksi
```C++
#include<iostream>
using namespace std;
int main(){
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    cout << "Isi array pertama : "<< nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat: " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```
Kode di atas membuat array nilai dengan 5 elemen, kemudian menginisialisasi setiap elemen dengan nilai tertentu.

## Unguided

### Unguided 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

float hitungluas_162(float panjang_162, float lebar_162){
    return panjang_162*lebar_162;
}
float hitungkeliling_162(float panjang_162, float lebar_162){
    return 2 * (panjang_162 + lebar_162);
}
int main(){
    float panjang_162, lebar_162;

    cout <<"Masukan panjang persegi panjang: ";
    cin >> panjang_162;
    cout << "Masukan lebar persegi panjang: ";
    cin >> lebar_162;

    float luas = hitungluas_162(panjang_162, lebar_162);
    cout << "Luas persegi panjang: " << luas << endl;

    float keliling = hitungkeliling_162(panjang_162, lebar_162);
    cout << "Keliling persegi panjang: " << keliling << endl;

    return 0;
}
```
### Unguided 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
Class dan struct adalah konsep yang digunakan dalam OOP (Object Oriented Programming) di C++. Kedua konstruksi memiliki penulisan yang sama, tetapi terdapat perbedaan dalam kegunaannya.

Struct (struktur) adalah tipe data yang dapat melakukan penyimpanan beberapa data dengan default public. Pembuatan tipe data baru dalam C dilakukan dengan menggunakan kata kunci struct. Struktur bermanfaat untuk mengelompokan sejumlah data dengan tipe yang berlainan.

Class, pada sisi lain, adalah sesuatu yang mempunyai data (sifat) dan fungsi (kelakuan) untuk mendeskripsikan suatu objek. Class defaultnya itu private, jadi jika objek anggota dari class itu sendiri ingin dipublikasikan, maka harus menggunakan (public).
```C++

#include <iostream>
using namespace std;

class Kucing_162{
    public:
        string nama_162;
        int umur_162;

        void infoKucing_162(){
            cout << "Nama Kucing: " << nama_162 << endl;
            cout << "Umur Kucing: " << umur_162 << endl;
        }
};

struct siswa{
    string Nama_162;
    int Umur_162;
    string Kelas_162;
};

int main(){
    // class
    Kucing_162 kucing1;

    kucing1.nama_162 = "maomao";
    kucing1.umur_162 = 5;

    kucing1.infoKucing_162();
    
    cout << endl;
    // struct
    siswa siswa1;

    siswa1.Nama_162 = "NAM";
    siswa1.Umur_162 = 27;
    siswa1.Kelas_162 = "IF11E";

    cout << "Nama: " << siswa1.Nama_162 << endl;
    cout << "Umur: " << siswa1.Umur_162 << endl;
    cout << "Kelas: " << siswa1.Kelas_162 << endl;
    return 0;
}

```
### Unguided 3.Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.
```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> dataSiswa;

    dataSiswa["yanti"] = 15;
    dataSiswa["yanto"] = 16;
    dataSiswa["yeni"] = 14;

    cout << "Data Siswa:" << endl;
    for (const auto& siswa : dataSiswa) {
        cout << siswa.first << ": " << siswa.second << " tahun" << endl;
    }

    return 0;
}
```
Fungsi map dalam C++ adalah sebuah container yang digunakan untuk menyimpan elemen dalam bentuk key-value pair. Setiap elemen dalam map dapat diakses menggunakan kunci.

Perbedaan antara array dan map adalah:
1. Array adalah sebuah data structure yang digunakan untuk menyimpan beberapa data dengan tipe yang sama, sedangkan map adalah sebuah data       structure yang digunakan untuk menyimpan data dalam bentuk key-value pair.
2. Array memiliki indeks yang berurutan, sedangkan map tidak memiliki indeks yang berurutan.
3. Array tidak mengizinkan nilai yang sama, sedangkan map mengizinkan nilai yang sama.

## Output

#### Output 1
![Praktikum Struktur Data dan Algoritme/MODUL 1/GAMBAR OUTPUT/output unguided 1.png]()
