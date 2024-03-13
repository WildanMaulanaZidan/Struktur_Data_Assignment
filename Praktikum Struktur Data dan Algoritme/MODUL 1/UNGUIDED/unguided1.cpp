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