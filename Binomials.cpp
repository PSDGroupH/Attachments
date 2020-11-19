#include <iostream>
#include <random>
#include <fstream>
#include <windows.h>

void setcolr(int n) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, n);
}

int main()
{
    int n, accur;
    double p;
    std::ofstream file_output_1, file_output_2;
    
    std::cout << "=================================================" << '\n';
    setcolr(9);
    std::cout << "Kelompok H . Mesin Pengambil Binomial Secara Acak" << '\n';
    setcolr(7);
    std::cout << "=================================================" << '\n';
h:
    file_output_1.open("data_keluaran_binomial.csv");
    file_output_2.open("data_keluaran_binomial.dat");
    std::cout << "Masukan n="; setcolr(4);
    std::cin >> n; setcolr(7);
re:
    std::cout << "Masukan p="; setcolr(4);
    std::cin >> p; setcolr(7);
    if (p > 1) {
        setcolr(12);
        std::cout << "Mohon masukan nilai probabilitas kurang dari sama dengan satu" << std::endl;
        setcolr(7);
        goto re;
    }
    std::cout << "Masukan Akurasi e (banyaknya pengulangan)="; setcolr(4);
    std::cin >> accur; setcolr(7);

    //Membuat mesin generator distribusi binomial
    std::default_random_engine mach;
    std::binomial_distribution<int> dist(n, p);

    int* numStor = new int[n];

    for (int i = 0; i < n; i++) {
        numStor[i] = 0;
    }

    for (int i = 0; i < accur; i++) {
        int gnrBin = dist(mach);
        *(numStor + gnrBin) += 1;
    }

    //Tabel Distribusi
    file_output_1 << "Nomor Bilangan;Frekuensi Muncul" << '\n';
    for (int i = 0; i < n; i++) {
        file_output_1 << i << ";" << *(numStor + i) << '\n';
        file_output_2 << i << " " << *(numStor + i) << '\n';
    }

    file_output_1.close();
    file_output_2.close();
    delete[] numStor;

    setcolr(207);
    std::cout << "PERHATIAN!" << std::endl;
    setcolr(10);
    std::cout << "Hasil keluaran telah ditulis dalam file 'data_keluaran_binomial.csv' dan 'data_keluaran_binomial.dat' pada ";
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

    return 0;

}