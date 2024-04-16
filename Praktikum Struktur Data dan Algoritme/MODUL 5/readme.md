# <h1 align="center"> LAPORAN PRAKTIKUM MODUL 5 HASH TABLE </h1>

## Dasar Teori

### HASH TABLE 
Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini,
data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri.
Akses data akan menjadi sangat cepat jika Anda mengetahui indeks dari data yang diinginkan.

Dengan demikian, hash table menjadi struktur data di mana operasi penyisipan dan pencarian data terjadi sangat cepat terlepas dari ukuran data tersebut.
Hash table menggunakan array sebagai media penyimpanan dan tekniknya untuk menghasilkan indeks suatu elemen yang dimasukkan atau ditempatkan.

### FUNGSI HASH TABLE PADA DATA
Fungsi utamanya pada data adalah mempercepat proses akses data. Hal ini berkaitan dengan
peningkatan data dalam jumlah besar yang diproses oleh jaringan data global dan lokal.
Hash table adalah solusi untuk membuat proses akses data lebih cepat dan memastikan bahwa data dapat dipertukarkan dengan aman.

Di dalam banyak bidang, hash table dikembangkan dan digunakan karena menawarkan kelebihan dalam efisiensi waktu operasi,
mulai dari pengarsipan hingga pencarian data. Contohnya adalah bidang jaringan komputer yang mengembangkannya menjadi hybrid open hash table,
yang kemudian dipakai untuk memproses jaringan komputer.

### CARA MEMBUAT HASH TABLE 
Untuk membuat hash table, sepotong memori perlu diblokir dengan cara yang sama seperti saat membuat array.
Anda perlu membuat indeks yang didasarkan pada kunci dengan menggunakan fungsi hash karena indeks yang dihasilkan harus sesuai dengan potongan memori.

Ada dua pemeriksaan yang dibutuhkan saat menempatkan data baru pada hash table, yaitu nilai hash dari kunci dan bagaimana nilainya dibandingkan dengan objek lain.
Pemeriksaan ini diperlukan saat membuatnya dengan Python karena saat data dimasukkan, kunci akan di-hash dan di-mask agar diubah menjadi larik atau indeks yang efisien.

### TEKNIK-TEKNIK HASH TABLE
1. HASHING
   Hashing merupakan sebuah proses mengganti kunci yang diberikan atau string karakter menjadi nilai lain. Penggunaan hashing paling populer adalah pada hash table.
   Hash table menyimpan pasangan kunci dan nilai dalam daftar yang dapat diakses melalui indeksnya. Karena pasangan kunci dan nilai tidak terbatas,
   maka fungsinya akan memetakan kunci ke ukuran tabel dan kemudian nilainya menjadi indeks untuk elemen tertentu.

2. LINEAR PROBING
   Linear probing merupakan skema dalam pemrograman komputer untuk menyelesaikan collision pada hash table. Dalam skema ini,
   setiap sel dari hash table menyimpan satu pasangan kunci-nilai. Saat fungsi hash menyebabkan collision dengan memetakan kunci baru ke sel hash table yang sudah ditempati oleh kunci lain,
   maka linear probing akan mencari tabel untuk lokasi bebas terdekat dan menyisipkan kunci baru.

   Pencarian dilakukan dengan cara yang sama, yaitu dengan mencari tabel secara berurutan, mulai dari posisi yang diberikan oleh fungsi hash,
   hingga menemukan sel dengan kunci yang cocok atau sel kosong. Hash table adalah struktur data non trivial yang paling umum digunakan.
   Linear probing dapat memberikan kinerja tinggi karena lokasi referensi yang baik, namun lebih sensitif terhadap kualitas fungsi hash daripada beberapa skema resolusi collision lainnya [1].
