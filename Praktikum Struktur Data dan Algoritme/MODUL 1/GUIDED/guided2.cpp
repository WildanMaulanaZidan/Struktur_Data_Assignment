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
    printf("Umur: %s\n", mhs2.age);
    return 0; 
}