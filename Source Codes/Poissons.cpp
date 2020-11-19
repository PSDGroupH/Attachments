#include <iostream>
#include <random>
#include <fstream>
#include <algorithm>
#include <windows.h>

int maxValue(std::vector<int>& _numStorVec) {
    int biggest = _numStorVec[0];
    for (int i = 0; i < _numStorVec.size(); i++) {
        if (_numStorVec[i] > biggest) {
            biggest = _numStorVec[i];
        }
    }
    return biggest;
}

void setcolr(int n) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, n);
}

int main()
{
    double n, lambda;
    std::ofstream file_output_1, file_output_2;

    std::cout << "=================================================" << '\n';
    setcolr(9);
    std::cout << "Kelompok H . Mesin Pengambil Poisson Secara Acak" << '\n';
    setcolr(7);
    std::cout << "=================================================" << '\n';
h:
    file_output_1.open("data_keluaran_poisson.csv");
    file_output_2.open("data_keluaran_poisson.dat");

    std::cout << "Masukan n (banyaknya pengulangan)="; setcolr(4);
    std::cin >> n; setcolr(7);
    std::cout << "Masukan lambda="; setcolr(4);
    std::cin >> lambda; setcolr(7);

    //Membuat mesin generator distribusi poisson
    std::default_random_engine mach;
    std::poisson_distribution<int> dist(lambda);

    std::vector<int> numStorVec;

    for (int i = 0; i < n; i++) {
        numStorVec.push_back(dist(mach));
    }

    int max = maxValue(numStorVec);

    int* numStor = new int[max];

    for (int i = 0; i < max; i++) {
        *(numStor + i) = 0;
    }

    for (int i = 0; i < n; i++) {
        *(numStor + numStorVec[i]) += 1;
    }

    //Tabel Distribusi
    file_output_1 << "Bilangan;Frekuensi Bilangan" << std::endl;
    for (int i = 0; i < max; i++) {
        file_output_1 << i << ";" << *(numStor + i) << '\n';
        file_output_2 << i << " " << *(numStor + i) << '\n';
    }

    file_output_1.close();
    file_output_2.close();

    setcolr(207);
    std::cout << "PERHATIAN!" << std::endl;
    setcolr(10);
    std::cout << "Hasil keluaran telah ditulis dalam file 'data_keluaran_poisson.csv' dan 'data_keluaran_poisson.dat' pada ";
    setcolr(12);
    std::cout << "folder / direktori yang sama dengan program ini.";
    setcolr(10);
    std::cout << " Buka file (.csv) dengan program Ms.Excel."; setcolr(11);
    std::cout << "\n+++++++++++++++++++++++\nPengolahan Selesai!\n+++++++++++++++++++++++\n";
    setcolr(10);
    std::cout << "Masukan 'p' untuk lakukan ulang dan masukan karakter apa saja untuk keluar" << std::endl;
    setcolr(7);
    std::string y;
    std::cin >> y;
    if (y == "p") {
        goto h;
    }
    
}