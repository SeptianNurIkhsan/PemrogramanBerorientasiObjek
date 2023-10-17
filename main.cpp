#include <iostream>

using namespace std;

class BangunDatar {
public:
    virtual double hitungLuas() {
        return 0;
    }

    virtual double hitungKeliling() {
        return 0;
    }
};

class Persegi : public BangunDatar {
private:
    double sisi;

public:
    Persegi(double s) : sisi(s) {}

    double hitungLuas() override {
        return sisi * sisi;
    }

    double hitungKeliling() override {
        return 4 * sisi;
    }
};

class PersegiPanjang : public BangunDatar {
private:
    double panjang;
    double lebar;

public:
    PersegiPanjang(double p, double l) : panjang(p), lebar(l) {}

    double hitungLuas() override {
        return panjang * lebar;
    }

    double hitungKeliling() override {
        return 2 * (panjang + lebar);
    }
};

class Segitiga : public BangunDatar {
private:
    double alas;
    double tinggi;

public:
    Segitiga(double a, double t) : alas(a), tinggi(t) {}

    double hitungLuas() override {
        return 0.5 * alas * tinggi;
    }

    double hitungKeliling() override {
        // Hitung keliling segitiga tidak diimplementasikan dalam contoh ini.
        return 0;
    }
};

class Lingkaran : public BangunDatar {
private:
    double jariJari;

public:
    Lingkaran(double r) : jariJari(r) {}

    double hitungLuas() override {
        return 3.14 * jariJari * jariJari;
    }

    double hitungKeliling() override {
        return 2 * 3.14 * jariJari;
    }
};

int main() {
    Persegi persegi(4);
    cout << "Luas Persegi: " << persegi.hitungLuas() << endl;
    cout << "Keliling Persegi: " << persegi.hitungKeliling() << endl;

    PersegiPanjang persegiPanjang(6, 10);
    cout << "Luas Persegi Panjang: " << persegiPanjang.hitungLuas() << endl;
    cout << "Keliling Persegi Panjang: " << persegiPanjang.hitungKeliling() << endl;

    Segitiga segitiga(3, 9);
    cout << "Luas Segitiga: " << segitiga.hitungLuas() << endl;

    Lingkaran lingkaran(14);
    cout << "Luas Lingkaran: " << lingkaran.hitungLuas() << endl;
    cout << "Keliling Lingkaran: " << lingkaran.hitungKeliling() << endl;

    return 0;
}