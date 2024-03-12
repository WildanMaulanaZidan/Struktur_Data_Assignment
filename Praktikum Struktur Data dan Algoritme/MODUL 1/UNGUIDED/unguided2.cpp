/*Class dan struct adalah dua cara di C++ untuk mendefinisikan tipe data 
yang dapat menggabungkan data dan fungsi yang beroperasi pada data tersebut.
Meskipun keduanya mirip, ada perbedaan utama dalam default aksesibilitas dan bagaimana 
mereka digunakan.*/

/*Class:

*Class adalah struktur data yang dapat menggabungkan data (variabel anggota) 
dan fungsi (metode) yang beroperasi pada data tersebut.
*Anggota variabel dan fungsi dalam class dapat memiliki tingkat aksesibilitas tertentu 
(misalnya, public, private, atau protected).*/
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
int main(){
    Kucing_162 kucing1;

    kucing1.nama_162 = "maomao";
    kucing1.umur_162 = "5";

    kucing1.infoKucing_162();
    return 0;
}

/*Struct:

*Struct adalah tipe data yang mirip dengan class tetapi dengan 
default aksesibilitas yang berbeda.
*Anggota variabel dalam struct secara default memiliki tingkat aksesibilitas public.
*Struct sering digunakan untuk menyimpan sekumpulan data yang terkait tanpa adanya 
operasi atau metode yang terkait.*/
#include <iostream>
using namespace std;

struct siswa{
    string nama_162;
    int umur_162;
    string kelas_162;
};

int main(){
    siswa siswa1;

    siswa1.nama_162 = "NAM";
    siswa1.umur_162 = 27;
    siswa1.kelas_162 = "IF11E";

    cout << "Nama: " << siswa1.nama_162 << endl;
    cout << "Umur: " << siswa1.umur_162 << endl;
    cout << "Kelas: " << siswa1.kelas_162 << endl;

    return o;
}
