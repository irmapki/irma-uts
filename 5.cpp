#include <iostream>
#include <iomanip> // Include untuk manipulasi output
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Mahasiswa {
  string nama, jurusan, NIM;
  Mahasiswa *selanjutnya;
};

Mahasiswa *kepala, *ekor, *nodeBaru, *saatIni, *hapus;

// create Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3]) {
  kepala = new Mahasiswa();
  kepala->nama = dataBaru[0];
  kepala->jurusan = dataBaru[1];
  kepala->NIM = dataBaru[2];
  ekor = kepala;
  ekor->selanjutnya = kepala;
}

// add first
void tambahAwal(string data[3]) {
  if (kepala == NULL) {
    cout << "Buat Linked List dulu!!" << endl;
  } else {
    nodeBaru = new Mahasiswa();
    nodeBaru->nama = data[0];
    nodeBaru->jurusan = data[1];
    nodeBaru->NIM = data[2];
    nodeBaru->selanjutnya = kepala;
    ekor->selanjutnya = nodeBaru;
    kepala = nodeBaru;
  }
}

// add Last
void tambahAkhir(string data[3]) {
  if (kepala == NULL) {
    cout << "Buat Linked List dulu!!" << endl;
  } else {
    nodeBaru = new Mahasiswa();
    nodeBaru->nama = data[0];
    nodeBaru->jurusan = data[1];
    nodeBaru->NIM = data[2];
    nodeBaru->selanjutnya = kepala;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
  }
}

// add Middle
void tambahTengah(string data[3], int posisi) {
  if (kepala == NULL) {
    cout << "Buat Linked List dulu!!" << endl;
  } else {
    if (posisi == 1) {
      cout << "Posisi satu bukan posisi tengah!!!" << endl;
    } else {
      nodeBaru = new Mahasiswa();
      nodeBaru->nama = data[0];
      nodeBaru->jurusan = data[1];
      nodeBaru->NIM = data[2];

      // traversing
      int nomor = 1;
      saatIni = kepala;
      while (nomor < posisi - 1) {
        saatIni = saatIni->selanjutnya;
        nomor++;
      }
      nodeBaru->selanjutnya = saatIni->selanjutnya;
      saatIni->selanjutnya = nodeBaru;
    }
  }
}

void printCircular() {
  if (kepala == NULL) {
    cout << "Buat Linked List dulu!!" << endl;
  } else {
    cout << "Data Mahasiswa" << endl;
    cout << "____________________________________________________" << endl; 
    cout << "| Nama                | Jurusan            | NIM     |" << endl;
    cout << "____________________________________________________" << endl; 
    saatIni = kepala;
    while (saatIni->selanjutnya != kepala) {
      // print
      cout << "| " << setw(20) << left << saatIni->nama
           << "| " << setw(18) << left << saatIni->jurusan
           << "| " << setw(8) << left << saatIni->NIM << " |" << endl;
      saatIni = saatIni->selanjutnya;
    }
    // print last node
    cout << "| " << setw(20) << left << saatIni->nama
         << "| " << setw(18) << left << saatIni->jurusan
         << "| " << setw(8) << left << saatIni->NIM << " |" << endl;
    cout << "____________________________________________________" << endl;
  }
}

int main() {
  string dataBaru[3] = {"Irma Cantik", "DKV", "12223"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[3] = {"Eko", "Farmasi", "9999"};
  tambahAwal(data);

  printCircular();

  string data2[3] = {"Agus", "PAI", "8999"};
  tambahAkhir(data2);

  printCircular();

  string data3[3] = {"Sulhan", "Ayah Ganteng", "6776"};
  tambahTengah(data3, 2);

  printCircular();

  return 0;
}
