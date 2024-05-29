// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <iomanip>
using namespace std;

// Penamaan variabel global unutk index array dan data cin
int vertexAmount;
int vertexWeight;
string vertexName;

// Fungsi untuk mengisi simpul
void fillVertex(string vertex[])
{
    cout << "Silahkan masukkan nama simpul" << endl;
    for (int i = 0; i < vertexAmount; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> vertexName;

        vertex[i] = vertexName;
    }

    cout << endl;
}

int main()
{
    // Penginputan index oleh user
    cout << "Masukkan jumlah simpul : ";
    cin >> vertexAmount;

    //  Deklarasi array sesuai index
    string vertex_191[vertexAmount];
    int matrix_191[vertexAmount][vertexAmount];

    // Pemanggilan fungsi
    fillVertex(vertex_191);

    cout << "Silahkan masukkan bobot antar simpul" << endl;

    // Pengisian bobot simpul
    for (int i = 0; i < vertexAmount; i++)
    {
        for (int j = 0; j < vertexAmount; j++)
        {
            cout << vertex_191[i] << " ------> " << vertex_191[j] << " = ";
            cin >> vertexWeight;

            matrix_191[i][j] = vertexWeight;
        }

        cout << endl;
    }

    cout << endl;

    cout << "Matriks bobot antar simpul" << endl;
    cout << setw(12) << "";

    // Mencetak header untuk nama simpul
    for (int i = 0; i < vertexAmount; i++)
    {
        cout << setw(12) << vertex_191[i];
    }

    cout << endl;

    //  Mencetak bobot setiap simpul
    for (int i = 0; i < vertexAmount; i++)
    {
        // Mencetak kolom untuk nama simpul
        cout << setw(12) << vertex_191[i];

        for (int j = 0; j < vertexAmount; j++)
        {
            cout << setw(12) << matrix_191[i][j];
        }

        cout << endl;
    }
}