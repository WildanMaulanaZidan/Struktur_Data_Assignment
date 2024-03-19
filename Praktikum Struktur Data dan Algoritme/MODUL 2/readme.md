# <h1 align="center"> Laporan Praktikum Modul Array </h1>

## Dasar Teori

Array merupakan struktur data yang paling dasar. Sebelum mempelajari struktur data
lainnya, alangkah baiknya, kita perlu mempelajari Array terlebih dahulu. Berikut ini
adalah beberapa jenis array :

### Array satu dimensi 
  Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data 
dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. Setiap
elemen di dalam array memiliki sebuah indeks atau nomor yang digunakan
untuk mengakses elemen tersebut. Indeks dimulai dari 0 dan berakhir pada
jumlah elemen dikurangi satu.
  Contohnya, sebuah array satu dimensi yang berisi bilangan bulat {1, 2,
3, 4, 5} memiliki lima elemen dan indeksnya dimulai dari 0. Indeks 0 merujuk
pada elemen pertama, indeks 1 merujuk pada elemen kedua, dan seterusnya
hingga indeks 4 merujuk pada elemen kelima.

### Array dua dimensi
  Array dua dimensi adalah variable yang terdiri dari kumpulan array
satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom.
Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks
baris dan indeks kolom. Indeks baris menunjukkan posisi elemen dalam baris,
sementara indeks kolom menunjukkan posisi elemen dalam kolom.

### Array multidimensi
  Array multidimensi memiliki kesamaan dengan array satu dimensi dan
dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini
digunakan untuk merepresentasikan array dengan dimensi lebih dari dua atau
array yang memiliki lebih dari dua indeks, seperti array tiga dimensi, array
empat dimensi, array lima dimensi, dan seterusnya.

## Guided

### Guided 1 Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
 // PROGRAM INPUT ARRAY 3 DIMENSI
int main()
 {
 // Deklarasi array
    int arr[2][3][3];
 // Input elemen
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
 // Output Array
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
 // Tampilan array
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
    cout << endl;
    }
 }
```
Kode di atas meminta pengguna untuk memasukkan nilai-nilai ke dalam array tiga dimensi dan kemudian mencetak nilai-nilai tersebut

### Guided 2 Program Mencari Nilai Maksimal pada Array
```C++
#include <iostream>
using namespace std;

int main(){
    int maks, a, i = 1, lokasi;
    cout << "Masukan panjang array: ";
    cin >> a;
    int array [a];
    cout << "Masukan " << a << "angka\n";
    for (i = 0; i <a; i++){
        cout << "Array ke-" << (i) << ": ";
        cin >> array [i];
    }
    maks = array [0];
    for(i =0; i<a; i++){
        if (array[i] > maks){
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di array ke " << lokasi << endl;
}
```
Kode di atas mencari nilai maksimum dari sebuah array yang diisi oleh pengguna, setelah menemukan nilai maksimum, 
program mencetak nilai maksimum beserta indeksnya di dalam array.

## Unguided

### Unguided 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang
diinputkan oleh user! 
Data array : 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
nomor genap : 2, 4, 6, 8, 10,
nomoe ganjil : 1, 3, 5, 7, 9
```C++
#include <iostream>
using namespace std;

int main() {
    const int size_162 = 10;
    int data_162[size_162];

  cout << "Masukkan 10 angka secara berurut: ";
    for (int i = 0; i < size_162; ++i) {
      cin >> data_162[i];
    }

  cout << "Data array: ";
    for (int i = 0; i < size_162; ++i) {
      cout << data_162[i];
        if (i < size_162 - 1) {
          cout << ", ";
        }
    }
  cout << endl;

  cout << "Nomor genap: ";
    for (int i = 0; i < size_162; ++i) {
        if (data_162[i] % 2 == 0) {
          cout << data_162[i];
            if (i < size_162 - 1) {
              cout << ", ";
            }
        }
    }
  cout << endl;

  cout << "Nomor ganjil: ";
    for (int i = 0; i < size_162; ++i) {
        if (data_162[i] % 2 != 0) {
          cout << data_162[i];
            if (i < size_162 - 1) {
              cout << ", ";
            }
        }
    }
  cout << endl;

    return 0;
}
```

