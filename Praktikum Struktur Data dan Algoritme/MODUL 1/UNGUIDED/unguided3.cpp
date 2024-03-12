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
/*Penjelasan Program:

**Program di atas menggunakan map untuk menyimpan data siswa, 
di mana nama siswa digunakan sebagai kunci (key) dan umur siswa sebagai nilai (value).
**Kemudian, program mengisi data siswa ke dalam map dengan menggunakan operator indeks [].
**Setelah itu, program mencetak nama dan umur setiap siswa dengan melakukan 
iterasi pada map menggunakan loop for.
**Dalam loop, siswa.first digunakan untuk mengakses kunci (nama siswa) dan siswa.
second digunakan untuk mengakses nilai (umur siswa) dari setiap elemen dalam map.*/

/*Perbedaan antara Array dan Map:

**Struktur Data: Array adalah struktur data yang menyimpan elemen-elemennya dalam urutan
teratur dan dapat diakses menggunakan indeks numerik.
Map adalah struktur data yang menyimpan elemen-elemennya dalam bentuk pasangan kunci-nilai
(key-value), di mana setiap kunci unik dan terkait dengan nilai tertentu.

**Akses Elemen: Dalam array, elemen dapat diakses menggunakan indeks numerik.
Misalnya, arr[0] untuk mengakses elemen pertama
Dalam map, elemen dapat diakses menggunakan kunci yang terkait. Misalnya, map["kunci"]
untuk mengakses nilai yang terkait dengan kunci "kunci".

**Kemampuan Penyimpanan:Array cocok digunakan ketika indeks elemen bersifat 
berurutan dan diketahui sebelumnya.
Map cocok digunakan ketika data harus diakses dengan kunci yang tidak 
berurutan atau tidak teratur.

**Kompleksitas Waktu:Pencarian elemen dalam array memiliki kompleksitas waktu O(1) 
untuk akses elemen menggunakan indeks numerik, tetapi O(n) untuk mencari elemen dengan 
nilai tertentu.*/