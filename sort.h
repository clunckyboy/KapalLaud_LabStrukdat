#include <algorithm>
using namespace std;

void sortirProduk() {
   int pilih;
   vector<Produk> sortedProduk = daftarProduk;
   cout << "Pilih cara pengurutan" << endl;
   cout << "1. Berdasarkan kategori" << endl;
   cout << "2. Berdasarkan Harga" << endl;
   cout << "Masukkan pilihan (1-2) : "; cin >> pilih;

   if (pilih == 1) {
      sort(sortedProduk.begin(), sortedProduk.end(), [](const Produk &x, const Produk &y) {
         return x.kategori == y.kategori ? x.nama < y.nama : x.kategori < y.kategori;
      });

      system("cls");
      string kategori = "";
      for(const auto &i : sortedProduk) {
         if (i.kategori != kategori) {
            kategori = i.kategori;
            cout << "\n============================" << endl;
            cout << "        "<<kategori<<"      " << endl;
            cout << "============================" << endl ;  
         }
         cout << i.nama << " || Rp " << fixed << setprecision(0) << i.harga << endl;
      } 
   } else if (pilih == 2) {
      system("cls");
      int opsi;
      cout << "1. Dari yang termurah" << endl;
      cout << "2. Dari yang termahal" << endl;
      cout << "Pilih cara : "; cin >> opsi;

      if (opsi == 1) {
         system("cls");
         sort(sortedProduk.begin(), sortedProduk.end(), [](const Produk &x, const Produk &y) {
            return x.harga < y.harga;
         });

        cout << "\nTermurah ke termahal :\n\n";
        for (const auto &i : sortedProduk) {
            cout << i.nama << " || " << i.kategori << " || Rp " << fixed << setprecision(0) << i.harga << endl;
         }

      } else if (opsi == 2) {
         system("cls");
         sort(sortedProduk.begin(), sortedProduk.end(), [](const Produk &x, const Produk &y) {
            return x.harga > y.harga;
         });

        cout << "\nTermahal ke termurah :\n\n";
        for (const auto &i : sortedProduk) {
            cout << i.nama << " || " << i.kategori << " || Rp " << fixed << setprecision(0) << i.harga << endl;
         }
      } else {cout << "Pilihan tidak valid!"; return;}
   } else { cout << "Pilihan tidak valid!";}
}
