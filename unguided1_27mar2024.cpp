#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Deklarasi global pointer head
Node* head = nullptr;

// Fungsi untuk menyisipkan data di depan linked list
void insertDepan(string nama, int usia) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menyisipkan data di belakang linked list
void insertBelakang(string nama, int usia) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menyisipkan data di tengah linked list
void insertTengah(string nama, int usia, string nama_sebelum, string nama_setelah) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    Node* temp = head;
    while (temp != nullptr && temp->nama != nama_sebelum) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data " << nama_sebelum << " tidak ditemukan" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk menghapus data dari linked list
void hapusData(string nama) {
    if (head == nullptr) {
        cout << "Linked list kosong" << endl;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->nama != nama) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
}

// Fungsi untuk mengubah data pada linked list
void ubahData(string nama_lama, string nama_baru, int usia_baru) {
    Node* temp = head;
    while (temp != nullptr && temp->nama != nama_lama) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    temp->nama = nama_baru;
    temp->usia = usia_baru;
}

// Fungsi untuk menampilkan seluruh data pada linked list
void tampilkanData() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->nama << " " << temp->usia << endl;
        temp = temp->next;
    }
}

int main() {
    // Menambahkan data pertama (nama dan usia Anda)
    string nama_anda;
    int usia_anda;
    cout << "Masukkan nama Anda: ";
    cin >> nama_anda;
    cout << "Masukkan usia Anda: ";
    cin >> usia_anda;
    insertDepan(nama_anda, usia_anda);
    insertBelakang ("John", 19);
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);
    cout << endl;

    // Menampilkan data awal
    cout << "Data awal:" << endl;
    tampilkanData();

    // Menghapus data Akechi
    hapusData("Akechi");

    // Menambahkan data lain sesuai urutan yang diminta
    insertTengah("Futaba", 18, "John", "Jane");
    insertDepan("Igor", 20);

    // Menampilkan seluruh data
    cout << "Data setelah operasi tambah dan dihapus:" << endl;
    tampilkanData();

    // Mengubah data Michael menjadi Reyn dengan usia 18
    ubahData("Michael", "Reyn", 18);

     // Menampilkan seluruh data setelah operasi hapus dan ubah
    cout << "\nData setelah operasi diubah :" << endl;
    tampilkanData();

    return 0;
}