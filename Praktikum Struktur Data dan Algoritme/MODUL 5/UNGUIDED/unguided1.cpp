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
