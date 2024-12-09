#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
#include <iomanip>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Produk {
    int id;
    string nama;
    string kategori;
    double harga;
};
vector<Produk> keranjang;

struct Pembayaran {
    int idTransaksi;
    vector<Produk> keranjang;
    double totalHarga;
};
vector<Pembayaran> riwayatPembayaran;

vector<Produk> daftarProduk = {
        {1, "Smartphone Samsung Galaxy S23", "Elektronik", 12000000},
        {2, "Laptop ASUS ROG Zephyrus G14", "Elektronik", 25000000},
        {3, "TV LED LG 43 Inch", "Elektronik", 6500000},
        {4, "Earbuds Apple AirPods Pro", "Elektronik", 3500000},
        {5, "Kamera DSLR Canon EOS 90D", "Elektronik", 17000000},
        {6, "Sepeda MTB Polygon", "Fitness", 5000000},
        {7, "Dumbbell 5kg", "Fitness", 200000},
        {8, "Matras Yoga", "Fitness", 250000},
        {9, "Mesin Elliptical", "Fitness", 7500000},
        {10, "Resistance Band", "Fitness", 100000},
        {11, "Serum Wajah Vitamin C", "Kecantikan", 150000},
        {12, "Masker Wajah Aloe Vera", "Kecantikan", 75000},
        {13, "Lipstik Matte L'Oreal", "Kecantikan", 120000},
        {14, "Parfum Chanel", "Kecantikan", 2500000},
        {15, "Sabun Cuci Muka Himalaya", "Kecantikan", 35000},
        {16, "Roti Tawar Serba Roti", "Konsumsi", 15000},
        {17, "Kopi Arabica 100g", "Konsumsi", 50000},
        {18, "Mie Instan", "Konsumsi", 5000},
        {19, "Susu UHT Indomilk 1 Liter", "Konsumsi", 18000},
        {20, "Teh Kotak Sosro 500ml", "Konsumsi", 7500},
};
    
unordered_map<int, Produk> hashProduk;
int idTransaksiawal = 1;

void inisialisasiHash() {
    for (const auto &i : daftarProduk) {
        hashProduk[i.id] = i;
    }
}

#include "array.h"
#include "graph.h"
#include "hash.h"
#include "sort.h"
#include "search.h"

// Fungsi untuk menampilkan produk
void tampilkanProduk() {
    for (const auto &produk : daftarProduk) {
        cout << produk.id << ". " << produk.nama << " - " << produk.kategori << " - Rp " << fixed << setprecision(2) << produk.harga << endl;
    }
}
