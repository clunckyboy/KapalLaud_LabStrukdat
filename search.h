//Mencari produk berdasarkan ID
void cariProduk(int id) {
    auto i = hashProduk.find(id);
    if (i != hashProduk.end()) {
        cout << "=================================================\n";
        cout << "                Produk Ditemukan!\n";
        cout << "=================================================\n";
        cout << " Nama               : " << i->second.nama << endl;
        cout << " Kategori           : " << i->second.kategori << endl;
        cout << " Harga              : Rp " << fixed << setprecision(0) << i->second.harga << endl;
        cout << "=================================================\n";
    } else {
        cout << "Produk tidak ditemukan.\n";
    }
}