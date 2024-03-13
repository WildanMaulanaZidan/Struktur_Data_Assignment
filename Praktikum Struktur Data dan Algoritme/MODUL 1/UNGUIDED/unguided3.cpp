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
