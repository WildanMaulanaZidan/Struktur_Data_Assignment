
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
