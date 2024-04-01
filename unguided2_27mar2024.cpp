#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama_produk;
    int harga;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

//menambahkan data di depan linked list
void insertDepan(string nama_produk, int harga) {
    Node* newNode = new Node;
    newNode->nama_produk = nama_produk;
    newNode->harga = harga;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;
}

//menambahkan data di belakang linked list
void insertBelakang(string nama_produk, int harga) {
    Node* newNode = new Node;
    newNode->nama_produk = nama_produk;
    newNode->harga = harga;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (tail != nullptr)
        tail->next = newNode;
    else
        head = newNode;
    tail = newNode;
}

//menambahkan data di urutan tertentu
void insertTengah(string nama_produk, int harga, string nama_sebelum, string nama_setelah) {
    Node* newNode = new Node;
    newNode->nama_produk = nama_produk;
    newNode->harga = harga;
    Node* temp = head;
    while (temp != nullptr && temp->nama_produk != nama_sebelum) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data " << nama_sebelum << " tidak ditemukan" << endl;
        return;
    }
    if (temp->next == nullptr) {
        insertBelakang(nama_produk, harga);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

//menghapus data dari linked list
void hapusData(string nama_produk) {
    if (head == nullptr) {
        cout << "Linked list kosong" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr && temp->nama_produk != nama_produk) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    if (temp == head) {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
    } else if (temp == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete temp;
}

//mengubah data pada linked list
void ubahData(string nama_produk_lama, string nama_produk_baru, int harga_baru) {
    Node* temp = head;
    while (temp != nullptr && temp->nama_produk != nama_produk_lama) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    temp->nama_produk = nama_produk_baru;
    temp->harga = harga_baru;
}

//menampilkan seluruh data pada linked list
void printtampilkanData(){
    if ( head == NULL){
        cout << "Buat linked list terlebih dahulu" << endl;
    }else{
        cout << "Data Produk : " << endl;
        Node* cur = head;  
        cout << " _______________________________________ "<< endl;
        cout << "| Nama Produk \t\t| Harga Produk\t|" << endl;
         cout << " _______________________________________ "<< endl;
        while ( cur -> next != head){
        // print
        cout << "| " << cur -> nama_produk << "\t\t| "<< cur -> harga << endl;
        //step
        cur = cur -> next;
        }
    }
}

//menampilkan data awal
void tampilkanDataAwal() {
    cout << "________________________________"<< endl;
    cout << "|Nama Produk  |\t\tHarga  |" << endl;
    cout << "________________________________"<< endl;
    cout << "|Originote    |\t\t60.000 |" << endl;
    cout << "|Somethinc    |\t\t150.000|" << endl;
    cout << "|Skintific    |\t\t100.000|" << endl;
    cout << "|Wardah       |\t\t50.000 |" << endl;
    cout << "|Hanasui      |\t\t30.000 |" << endl;
    cout << "________________________________"<< endl;
}

    int main() {
    // Memasukkan data awal pada linked list
    insertBelakang("Originote", 60000);
    insertBelakang("Somethinc", 150000);
    insertBelakang("Skintific", 100000);
    insertBelakang("Wardah", 50000);
    insertBelakang("Hanasui", 30000);

    // Menampilkan data awal
    tampilkanDataAwal();

    // Menu program
    int menu;
    string nama_produk, nama_sebelum, nama_setelah, nama_produk_baru;
    int harga, harga_baru;

    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                insertBelakang(nama_produk, harga);
                break;
            case 2:
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> nama_produk;
                hapusData(nama_produk);
                break;
            case 3:
                cout << "Masukkan nama produk yang akan diupdate: ";
                cin >> nama_produk;
                cout << "Masukkan nama produk baru: ";
                cin >> nama_produk_baru;
                cout << "Masukkan harga baru: ";
                cin >> harga_baru;
                ubahData(nama_produk, nama_produk_baru, harga_baru);
                break;
            case 4:
                cout << "Masukkan nama produk baru: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan nama produk sebelumnya: ";
                cin >> nama_sebelum;
                cout << "Masukkan nama produk setelahnya: ";
                cin >> nama_setelah;
                insertTengah(nama_produk, harga, nama_sebelum, nama_setelah);
                break;
            case 5:
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> nama_produk;
                hapusData(nama_produk);
                break;
            case 6:
                while (head != nullptr) {
                    hapusData(head->nama_produk);
                }
                break;
            case 7:
                printtampilkanData();
                break;

            case 8:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Menu tidak valid." << endl;
        }
    } while (menu != 8);

    return 0;
}