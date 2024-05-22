# <h1 align="center"> Laporan Praktikum Modul Algoritma Searching</h1>

## Dasar Teori

### Algoritma Sequential

Sequential Search adalah proses membandingkan setiap elemen array satu persatu secara beruntun dimulai dari elemen pertama hingga elemen yang dicari ditemukan atau hingga elemen terakhir dari array.
Metode Sequential Search atau disebut pencarian beruntun dapat digunakan untuk melakukan pencarian data baik pada array yang sudah terurut maupun yang belum terurut.
Proses yang terjadi pada metode pencarian ini adalah sebagai berikut: (1)Membaca array data. (2) Menentukan data yang dicari. (3) Mulai dari data pertama sampai dengan
data terakhir, data yang dicari dibandingkan dengan masing-masing data di dalam array. Jika data yang dicari tidak ditemukan maka semua data atau elemen array dibandingkan sampai
selesai. Jika data yang dicari ditemukan maka perbandingan akan dihentikan

Adapun Proses Algoritma Sequential Searching adalah sebagai berikut:
a. Pertama data melakukan perbandingan satu per satu secara berurutan dalam kumpulan data dengan data yang di cari sampai data tersebut ditemukan atau tidak ditemukan.
b. Pada dasarnya, pencarian ini hanya melakukan pengulangan data dari 1 sampai dengan jumlah data (n).
c. Setiap pengulangan, dibandingkan data ke-i dengan data yang sedang dicari.
d. Apabila data sama dengan yang dicari, berarti data telah berhasil di temukan. Sebaliknya apabila sampai akhir melakukan pengulangan tidak ada data yang sama dengan yang dicari, berarti data tidak ada yang ditemukan.
Urutan Algoritma Sequential Searching:
1. i <- 0
2. Ketemu <- false
3. Selama ( tidak ketemu ) dan ( i < N ) kerjakan baris 4
4. Jika ( Data[i] = key ) maka ketemu <- true Jika tidak i <- i + 1
5. Jika ( Ketemu ) maka i adalah indeks dari data yang dicari[1]

### Algoritma Binary Search
Pencarian biner (Binary Search) adalah metode pencarian data pada array yang telah terurut. Metode ini lebih efisien daripada metode pencarian linier dimana semua
elemen di dalam array diuji satu per satu sampai ditemukan elemen yang diinginkan. Selain dari pencarian biner, terdapat juga pencarian interpolasi (interpolation search),
pencarian lompat (jump search), yang sama-sama bekerja pada data yang terurut. Pencarian pada data yang terurut menghasilkan pencarian yang cepat. Pencarian
interpolasi mempunyai kekompleksan waktu rata-rata adalah O (log log n), sedangkan pencarian lompat adalah O(kn1/(k+1)). Kekompleksan waktu untuk pencarian biner
adalah O (log n) seperti yang dikemukakan oleh Knuth. 

Prinsip pencarian biner dapat dijelaskan sebagai berikut Misalkan indeks kiri adalah i dan indeks kanan adalah j. Pada mulanya, kita inisialisasi i dengan 1 dan j dengan n.

1. Bagi dua elemen larik pada elemen tengah. Elemen tengah adalah elemen dengan indeks k = (i + j) div 2. ( Elemen tengah L[K], membagi larik menjadi dua bagianyaitu bagian kiri L[i..j] dan bagian kanan L[k+1..j])
2. Periksa apakah L[K] = x, jika L[K] = x maka pencarian selesai sebab x sudah ditemukan. Tetapi jika L[K] ≠ x, harus ditentukan apakah pencarian akan dilakukan di larik bagian kiri atau dilarik bagian kanan. Jika L[K] < x, maka
   pencarian dilakukan lagi pada larik bagian kiri. Sebaliknya, jika L[K] > x maka pencarian dilakukan lagi pada larik bagian kanan.
3. Ulangi langkah pertama hingga x ditemukan atau i > j yaitu ukuran larik sudah nol[2].

## Guided

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++){
        if (data[i] == cari){
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout<< "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu){
        cout << "\n angka " << cari << " ditemukan pada indeks ke -" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort(int arr[], int n) {
    int temp, min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
            min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void binary_search(int arr[], int n, int target) {
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target) {
            b_flag = 1;
            break;
        } else if (arr[tengah] < target) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
    cout << "\nData ditemukan pada index ke-" << tengah <<endl;
    else
    cout << "\nData tidak ditemukan\n";
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";

// Tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
// Urutkan data dengan selection sort

    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
// Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
// Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
```

#### Output 
![Output Guided 2](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%208/GAMBAR/Output%20Guided2.png)

Kode diatas melakukan pencarian biner (binary search) pada array yang telah diurutkan menggunakan algoritma selection sort,
Hasil pencarian biner ditampilkan, menunjukkan apakah nilai tersebut ditemukan dalam array dan pada indeks ke berapa.

## Unguided

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int binarySearch(char arr[], int l, int r, char x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Cek apakah x ada di tengah-tengah
        if (arr[m] == x) {
            return m;
        }

        // Jika x lebih besar, maka abaikan bagian kiri
        if (arr[m] < x) {
            l = m + 1;
        }
        // Jika x lebih kecil, maka abaikan bagian kanan
        else {
            r = m - 1;
        }
    }

    return -1;
}

int main() {
    string kalimat;
    char huruf;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    int n = kalimat.length();
    char arr[n + 1];
    copy(kalimat.begin(), kalimat.end(), arr);
    arr[n] = '\0';

    sort(arr, arr + n);

    int result = binarySearch(arr, 0, n - 1, huruf);

    if (result != -1) {
        cout << "Huruf '" << huruf << "' ditemukan di index " << result << " setelah diurutkan." << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
```
#### Output Unguided 1
![Output Unguided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%208/GAMBAR/Output%20Unguided%202.png)

Kode diatas adalah Algoritma Binary Search bekerja pada array yang terurut, Jika huruf ditemukan, program akan mencetak indeks posisi huruf setelah diurutkan,
Jika huruf tidak ditemukan, program akan memberitahu bahwa huruf tidak ada dalam kalimat.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <string>

using namespace std;

int hitungVokal(const string& kalimat) {
    int jumlahVokal = 0;
    string vokal = "aeiouAEIOU";

    for (char c : kalimat) {
        if (vokal.find(c) != string::npos) {
            jumlahVokal++;
        }
    }

    return jumlahVokal;
}

int main() {
    string kalimat;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = hitungVokal(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}

```

#### Output Unguided 2
![Output Unguided 2](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%208/GAMBAR/Output%20Unguided1.png)

Kode diatas adalah cara mudah untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang diinput oleh pengguna.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
// WILDAN MAULANA ZIDAN 
// 2311102162

#include <iostream>

using namespace std;

int hitungAngkaEmpat(int data[], int ukuran) {
    int jumlahEmpat = 0;

    for (int i = 0; i < ukuran; ++i) {
        if (data[i] == 4) {
            jumlahEmpat++;
        }
    }

    return jumlahEmpat;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int ukuran = sizeof(data) / sizeof(data[0]);

    int jumlahEmpat = hitungAngkaEmpat(data, ukuran);

    cout << "Jumlah angka 4 dalam array: " << jumlahEmpat << endl;

    return 0;
}

```

#### Output Unguided 3
![Output Unguided 3](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%208/GAMBAR/Output%20Unguided3..png)

Kode diatas kita bisa menghitung berapa banyak angka 4 yang terdapat dalam array data menggunakan algoritma Sequential Search.

## Kesimpulan 


## Referensi 
