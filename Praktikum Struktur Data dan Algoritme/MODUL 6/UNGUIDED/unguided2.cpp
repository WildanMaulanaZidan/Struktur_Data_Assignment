// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <stack>

using namespace std;

int main() {

  string kalimat;
  stack<char> tumpukan;
  
  cout << endl;
  cout << "Masukkan kalimat (minimal 3 kata): ";
  getline(cin, kalimat);

  if (kalimat.length() < 3) {
    cout << "Kalimat minimal harus 3 kata!" << endl;
    return 1;
  }

  for (char c : kalimat) {
    tumpukan.push(c);
  }

  kalimat = "";
  while (!tumpukan.empty()) {
    kalimat += tumpukan.top();
    tumpukan.pop();
  }

  cout << "Kalimat terbalik: " << kalimat << endl;

  return 0;
}