# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>

## Dasar Teori

### Graph

Graph merupakan representasi dari suatu masalah yang digambarkan sebagai sekumpulan noktah atau simpul (vertex) yang dihubungkan
dengan sekumpulan garis atau sisi (edge). Secara singkat suatu graph dapat ditulis sebagai G = (V,E) yang dalam hal ini:

V = Himpunan berhingga dan tidak kosong dari simpul-simpul (vertex) = { v1, v2,…vn }
E =Himpunan sisi yang menghubungkan sepasang simpul. = { e1, e2,…en } Simpul pada graph dapat dinomori dengan huruf, seperti v,w,…, dengan bilangan asli 1,
2,3,…, atau gabungan keduanya. Sisi (edge) yang menghubungkan dua simpul (vertex) vi dan vj dinyatakan dengan pasangan (vi ,vj) atau dengan lambang e1, e2 , 
dengankata lain, jika e adalah sisi yang menghubungkan simpul vi dan vj, maka e dapat ditulis sebagai e = (vi , vj).[1].

### Tree

Pohon ( tree) adalah graph terhubung yang tidak  mengandung sirkuit. Pohon (tree) merupakan stuktur data yang tidak linier yang  digambarkan dengan hubungan yang bersifat hirarkis antar satu elemen.

Jenis pohon dalam sturktur data sebagai berikut : 
1. Full binary tree
   Binary tree yang tiap nodenya memiliki satu root dan dua child dan harus memiliki panjang yang saman
2. Complete binary tree
   Pohon ini mirip dengan Full Bianry Tree, namun pada tiap sub tree boleh memiliki panjang path yang berbeda node kecuali leaf yang meiliki 0 atau 2 anak
3. Skewed binary tree
   Pohon yang semua nodenya kecuali daun hanya memiliki satu anak (child).[2]

## Guided

### 1. Graph
```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};
    int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph(){
    for (int baris = 0; baris <7; baris ++){
        cout <<" " << setiosflags (ios::left)<<setw (15)<< simpul [baris] << " : ";
        for (int kolom = 0; kolom<7; kolom++){
            if (busur[baris][kolom]!=0){
                cout << " " << simpul[kolom]<< "(" << busur[baris][kolom]<< ")";
            }
        }
        cout << endl;
    }
}

int main(){

tampilGraph();
return 0;

}
```
![Output Guided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%209/gambar/output%20guided1.png)

Kode di atas

### 2. Tree
```C++
#include <iostream>
using namespace std;
// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};
// pointer global
Pohon *root;
// Inisialisasi
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"

                 << endl;

            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
                return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"

                 << endl;

            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " <<

                data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&

                node->parent->right == node)

                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node

                     && node->parent->left == node)

                cout << "Sibling : " << node->parent->right->data <<

                    endl;

            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" <<

                    endl;

            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}
int main()
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
}
```
![Output Guided 2](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%209/gambar/output%20guided%202.a.png)
![](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%209/gambar/output%20guided%202.b.png)

Kode di atas

## Unguided

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
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
    string vertex[vertexAmount];
    int matrix[vertexAmount][vertexAmount];

    // Pemanggilan fungsi
    fillVertex(vertex);

    cout << "Silahkan masukkan bobot antar simpul" << endl;

    // Pengisian bobot simpul
    for (int i = 0; i < vertexAmount; i++)
    {
        for (int j = 0; j < vertexAmount; j++)
        {
            cout << vertex[i] << " ------> " << vertex[j] << " = ";
            cin >> vertexWeight;

            matrix[i][j] = vertexWeight;
        }

        cout << endl;
    }

    cout << endl;

    cout << "Matriks bobot antar simpul" << endl;
    cout << setw(12) << "";

    // Mencetak header untuk nama simpul
    for (int i = 0; i < vertexAmount; i++)
    {
        cout << setw(12) << vertex[i];
    }

    cout << endl;

    //  Mencetak bobot setiap simpul
    for (int i = 0; i < vertexAmount; i++)
    {
        // Mencetak kolom untuk nama simpul
        cout << setw(12) << vertex[i];

        for (int j = 0; j < vertexAmount; j++)
        {
            cout << setw(12) << matrix[i][j];
        }

        cout << endl;
    }
}
```
![Output Unguide 1]()

Kode di atas

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
    char data_162;
    Node *left_162, *right_162, *parent_162; // pointer
};

Node *root_162;

class Tree
{
public:
    Tree()
    {
        root_162 = nullptr;
    }

    bool isEmpty()
    {
        return root_162 == nullptr;
    }

    Node *makeNode(char data_162)
    {
        Node *newNode_162 = new Node;
        newNode_162->data_162 = data_162;
        newNode_162->left_162 = nullptr;
        newNode_162->right_162 = nullptr;
        newNode_162->parent_162 = nullptr;

        return newNode_162;
    }

    void makeBranch(char data_162)
    {
        if (isEmpty())
        {
            root_162 = makeNode(data_162);
            cout << "\nNode " << data_162 << " berhasil dibuat menjadi root_162." << endl;
        }
        else
        {
            cout << "\nPohon sudah dibuat" << endl;
        }
    }

    Node *insertLeft(char data_162, Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
            return nullptr;
        }
        else
        {
            if (node == nullptr)
            {
                cout << "Node tersebut tidak valid atau tidak ada" << endl;
                return nullptr;
            }

            if (node->left_162 != nullptr)
            {
                cout << "\nNode " << node->data_162 << " sudah ada child kiri!"
                     << endl;

                return nullptr;
            }
            else
            {
                Node *newNode_162 = makeNode(data_162);
                newNode_162->parent_162 = node;
                node->left_162 = newNode_162;
                cout << "\nNode " << data_162 << " berhasil ditambahkan ke child kiri " << node->data_162 << endl;
                return newNode_162;
            }
        }
    }

    Node *insertRight(char data_162, Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
            return nullptr;
        }
        else
        {
            if (node == nullptr)
            {
                cout << "Node tersebut tidak valid atau tidak ada" << endl;
                return nullptr;
            }

            if (node->right_162 != nullptr)
            {
                cout << "\nNode " << node->data_162 << " sudah ada child kanan!"

                     << endl;

                return nullptr;
            }
            else
            {
                Node *newNode_162 = makeNode(data_162);
                newNode_162->parent_162 = node;
                node->right_162 = newNode_162;
                cout << "\nNode " << data_162 << " berhasil ditambahkan ke child kanan " << node->data_162 << endl;
                return newNode_162;
            }
        }
    }

    void update(char data_162, Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
        }
        else
        {
            if (!node)
                cout << "\nNode yang ingin diganti tidak ada!!" << endl;
            else
            {
                char temp = node->data_162;
                node->data_162 = data_162;
                cout << "\nNode " << temp << " berhasil diubah menjadi " << data_162 << endl;
            }
        }
    }

    void retrieve(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
        }
        else
        {
            if (!node)
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            else
            {
                cout << "\nData node : " << node->data_162 << endl;
            }
        }
    }

    void find(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
        }
        else
        {
            if (!node)
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            else
            {
                cout << "\nData Node : " << node->data_162 << endl;
                cout << "Rootroot : " << root_162->data_162 << endl;

                if (!node->parent_162)
                {
                    cout << "Parent : (tidak punya parent_162)" << endl;
                }
                else
                {
                    cout << "Parent : " << node->parent_162->data_162 << endl;
                }

                if (node->parent_162 != nullptr && node->parent_162->left_162 != node && node->parent_162->right_162 == node)
                {
                    cout << "Sibling : " << node->parent_162->left_162->data_162 << endl;
                }
                else if (node->parent_162 != nullptr && node->parent_162->right_162 != node && node->parent_162->left_162 == node)
                {
                    cout << "Sibling : " << node->parent_162->right_162->data_162 << endl;
                }
                else
                {
                    cout << "Sibling : (tidak punya sibling)" << endl;
                }

                if (!node->left_162)
                {
                    cout << "Child Kiri : (tidak punya Child kiri)" << endl;
                }
                else
                {
                    cout << "Child Kiri : " << node->left_162->data_162 << endl;
                }

                if (!node->right_162)
                {
                    cout << "Child Kanan : (tidak punya Child kanan)" << endl;
                }
                else
                {
                    cout << "Child Kanan : " << node->right_162->data_162 << endl;
                }
            }
        }
    }

    // Penelusuran (Traversal)
    // preOrder
    void preOrder(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            if (node != nullptr)
            {
                cout << " " << node->data_162 << ", ";
                preOrder(node->left_162);
                preOrder(node->right_162);
            }
        }
    }

    // inOrder
    void inOrder(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            if (node != nullptr)
            {
                inOrder(node->left_162);
                cout << " " << node->data_162 << ", ";
                inOrder(node->right_162);
            }
        }
    }

    // postOrder
    void postOrder(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            if (node != nullptr)
            {
                postOrder(node->left_162);
                postOrder(node->right_162);
                cout << " " << node->data_162 << ", ";
            }
        }
    }

    // Hapus Node Tree
    void deleteTree(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            if (node != nullptr)
            {
                if (node != root_162)
                {
                    if (node->parent_162->left_162 == node)
                        node->parent_162->left_162 = nullptr;
                    else if (node->parent_162->right_162 == node)
                        node->parent_162->right_162 = nullptr;
                }

                deleteTree(node->left_162);
                deleteTree(node->right_162);

                if (node == root_162)
                {
                    delete root_162;
                    root_162 = nullptr;
                }
                else
                {
                    delete node;
                }
            }
        }
    }

    // Hapus SubTree
    void deleteSub(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            deleteTree(node->left_162);
            deleteTree(node->right_162);

            cout << "\nNode subtree " << node->data_162 << " berhasil dihapus."
                 << endl;
        }
    }

    // Hapus Tree
    void clear()
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!!" << endl;
        else
        {
            deleteTree(root_162);
            cout << "\nNode berhasil dihapus." << endl;
        }
    }

    // Cek Size Tree
    int size(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!!" << endl;
            return 0;
        }
        else
        {
            if (!node)
            {
                return 0;
            }
            else
            {
                return 1 + size(node->left_162) + size(node->right_162);
            }
        }
    }

    // Cek Height Level Tree
    int height(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
            return 0;
        }
        else
        {
            if (!node)
            {
                return 0;
            }
            else
            {
                int heightKiri = height(node->left_162);
                int heightKanan = height(node->right_162);
                if (heightKiri >= heightKanan)
                {
                    return heightKiri + 1;
                }
                else
                {
                    return heightKanan + 1;
                }
            }
        }
    }

    // Karakteristik Tree
    void characteristic()
    {
        int s = size(root_162);
        int h = height(root_162);
        cout << "\nSize Tree : " << s << endl;
        cout << "Height Tree : " << h << endl;
        if (h != 0)
            cout << "Average Node of Tree : " << s / h << endl;
        else
            cout << "Average Node of Tree : 0" << endl;
    }

    // Fungsi untuk mendapatkan Node root_162
    Node *getRoot()
    {
        return root_162;
    }

    // Fungsi untuk menemukan node tertentu
    Node *findNode(char data_162, Node *node)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data_162 == data_162)
            return node;
        Node *leftResult = findNode(data_162, node->left_162);
        if (leftResult != nullptr && leftResult->data_162 == data_162)
            return leftResult;
        return findNode(data_162, node->right_162);
    }
};

void displayMenu()
{
    cout << "\nMenu:" << endl;
    cout << "1. Buat node root_162" << endl;
    cout << "2. Tambahkan child kiri" << endl;
    cout << "3. Tambahkan child kanan" << endl;
    cout << "4. Ubah node" << endl;
    cout << "5. Tampilkan data_162 node" << endl;
    cout << "6. Cari node" << endl;
    cout << "7. Preorder traversal" << endl;
    cout << "8. Inorder traversal" << endl;
    cout << "9. Postorder traversal" << endl;
    cout << "10. Hapus subtree" << endl;
    cout << "11. Hapus seluruh tree" << endl;
    cout << "12. Tampilkan karakteristik tree" << endl;
    cout << "13. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main()
{
    Tree tree;
    int choice;
    char data_162, targetData;
    Node *currentNode = nullptr, *targetNode;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (tree.isEmpty())
            {
                cout << "Masukkan data_162 untuk root_162: ";
                cin >> data_162;
                tree.makeBranch(data_162);
                currentNode = tree.getRoot();
            }
            else
            {
                cout << "Tree sudah dibuat!" << endl;
            }
            break;

        case 2:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin ditambah child-nya: ";
                cin >> targetData;
                cout << "Masukkan data_162 untuk child kiri: ";
                cin >> data_162;

                targetNode = tree.findNode(targetData, currentNode);

                tree.insertLeft(data_162, targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 3:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin ditambah child-nya: ";
                cin >> targetData;
                cout << "Masukkan data_162 untuk child kanan: ";
                cin >> data_162;

                targetNode = tree.findNode(targetData, currentNode);

                tree.insertRight(data_162, targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 4:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin diganti: ";
                cin >> targetData;
                cout << "Masukkan data_162 baru untuk pohon: ";
                cin >> data_162;

                targetNode = tree.findNode(targetData, currentNode);

                tree.update(data_162, targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 5:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin ditampilkan: ";
                cin >> targetData;

                targetNode = tree.findNode(targetData, currentNode);

                tree.retrieve(targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 6:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin dicari: ";
                cin >> targetData;

                targetNode = tree.findNode(targetData, currentNode);

                tree.find(targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 7:
            if (!tree.isEmpty())
            {
                cout << "Preorder traversal: ";
                tree.preOrder(tree.getRoot());
                cout << endl;
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 8:
            if (!tree.isEmpty())
            {
                cout << "Inorder traversal: ";
                tree.inOrder(tree.getRoot());
                cout << endl;
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 9:
            if (!tree.isEmpty())
            {
                cout << "Postorder traversal: ";
                tree.postOrder(tree.getRoot());
                cout << endl;
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 10:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin di delete sub tree-nya: ";
                cin >> targetData;

                targetNode = tree.findNode(targetData, currentNode);

                tree.deleteSub(targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 11:
            if (!tree.isEmpty())
            {
                tree.clear();
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 12:
            if (!tree.isEmpty())
            {
                tree.characteristic();
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 13:
            cout << "Keluar dari program." << endl;
            break;

        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (choice != 13);

    return 0;
}
```
![]()

Kode di atas






