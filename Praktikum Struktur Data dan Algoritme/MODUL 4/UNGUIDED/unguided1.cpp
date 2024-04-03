// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class LinkedList {
private:
    Mahasiswa* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // tambah depan
    void tambahDepan(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
    }

    // tambah belakng 
    void tambahBelakang(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Mahasiswa* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // tambah tengah
    void tambahTengah(string nama, string nim, int posisi) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;

        if (posisi == 1 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Mahasiswa* temp = head;
        for (int i = 1; i < posisi - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ubah depan
    void ubahDepan(string nama, string nim) {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }
        head->nama = nama;
        head->nim = nim;
        cout << "Data berhasil diubah\n";
    }

    // ubah belakang
void ubahBelakang(string nama, string nim, int posisi) {
    if (head == nullptr) {
        cout << "List kosong\n";
        return;
    }

    Mahasiswa* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    if (posisi < 1 || posisi > count) {
        cout << "Posisi tidak valid\n";
        return;
    }

    temp = head;
    for (int i = 1; i < posisi; ++i) {
        temp = temp->next;
    }

    cout << "Masukkan Nama Baru : ";
    cin >> temp->nama;
    cout << "Masukkan NIM Baru : ";
    cin >> temp->nim;

    cout << "Data berhasil diubah\n";
}



    // ubah tengah
    void ubahTengah(string nama, string nim, int posisi) {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Mahasiswa* temp = head;
        for (int i = 1; i < posisi && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid\n";
            return;
        }

        temp->nama = nama;
        temp->nim = nim;
        cout << "Data berhasil diubah\n";
    }

// hapus depan
    void hapusDepan() {
    if (head == nullptr) {
        cout << "List sudah kosong\n";
        return;
    }
    Mahasiswa* temp = head;
    head = head->next;
    delete temp;
    }

// hapus belakang
    void hapusBelakang() {
    if (head == nullptr) {
        cout << "List sudah kosong\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Mahasiswa* temp = head;
    Mahasiswa* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = nullptr;
    }   

    // hapus tengah
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "List sudah kosong\n";
            return;
        }
        if (posisi == 1) {
            hapusDepan();
            return;
        }

        Mahasiswa* temp = head;
        Mahasiswa* prev = nullptr;
        for (int i = 1; i < posisi && temp != nullptr; ++i) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // tampilan data
    void tampilkanData() {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }
        Mahasiswa* temp = head;
        cout << "DATA MAHASISWA\n";
        cout << "NAMA\t\tNIM\n";
        while (temp != nullptr) {
            cout << temp->nama << "\t\t" << temp->nim << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList DataMahasiswa;

    // Menambahkan data sesuai urutan
    DataMahasiswa.tambahBelakang("Jawad", "23300001");
    DataMahasiswa.tambahBelakang("Wildan", "2311102162");
    DataMahasiswa.tambahBelakang("Farrel", "23300003");
    DataMahasiswa.tambahBelakang("Denis", "23300005");
    DataMahasiswa.tambahBelakang("Anis", "23300008");
    DataMahasiswa.tambahBelakang("Bowo", "23300015");
    DataMahasiswa.tambahBelakang("Gahar", "23300040");
    DataMahasiswa.tambahBelakang("Udin", "23300048");
    DataMahasiswa.tambahBelakang("Ucok", "23300050");
    DataMahasiswa.tambahBelakang("Budi", "23300099");

    int Pilih1_11;
    string nama, nim;
    int posisi;

    do {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. Tampilkan\n";
        cout << "0. Keluar\n";
        cout << "Pilih Operasi : ";
        cin >> Pilih1_11;

        switch (Pilih1_11) {
            case 1:
                cout << "-Tambah Depan-\n";
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                DataMahasiswa.tambahDepan(nama, nim);
                cout << "Data telah ditambahkan\n";
                break;
            case 2:
                cout << "-Tambah Belakang-\n";
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                DataMahasiswa.tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan\n";
                break;
            case 3:
                cout << "-Tambah Tengah-\n";
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                DataMahasiswa.tambahTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan\n";
                break;
            case 4:
                cout << "-Ubah Depan-\n";
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                DataMahasiswa.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "-Ubah Belakang-\n";
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                cout << "Masukan Posisi : ";
                cin >> posisi;
                DataMahasiswa.ubahBelakang(nama, nim, posisi);
                break;
            case 6:
                cout << "-Ubah Tengah-\n";
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                DataMahasiswa.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                cout << "-Hapus Depan-\n";
                DataMahasiswa.hapusDepan();
                cout << "Data berhasil dihapus\n";
                break;
            case 8:
                cout << "-Hapus Belakang-\n";
                DataMahasiswa.hapusBelakang();
                cout << "Data berhasil dihapus\n";
                break;
            case 9:
                cout << "-Hapus Tengah-\n";
                cout << "Masukkan posisi : ";
                cin >> posisi;
                DataMahasiswa.hapusTengah(posisi);
                cout << "Data berhasil dihapus\n";
                break;
            case 10:
                // Tambahkan kode untuk menghapus seluruh list
                break;
            case 11:
                DataMahasiswa.tampilkanData();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (Pilih1_11 != 0);

    return 0;
}
