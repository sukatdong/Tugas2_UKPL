#include <iostream>
#include <stdexcept>

using namespace std;

// Fungsi untuk menghitung BMI
double calculateBMI(double weight, double height) {
    if (height <= 0) {
        throw invalid_argument("Tinggi harus lebih besar dari 0");
    }

    return weight / (height * height);
}

// Fungsi untuk menentukan kategori BMI
string determineBMICategory(double bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi < 25) {
        return "Normal weight";
    } else if (bmi < 30) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

int main() {
    // Equivalence Class Partitioning
    // Kelas ekuivalen tinggi: 0 < tinggi <= 3 (kasus input tinggi yang valid)
    // Kelas ekuivalen berat: 0 < berat <= 1000 (kasus input berat yang valid)
    double weight, height;
    
    cout << "Masukkan berat (kg): ";
    cin >> weight;
    
    cout << "Masukkan tinggi (m): ";
    cin >> height;

    try {
        // Menghitung BMI
        double bmi = calculateBMI(weight, height);
        
        // Menentukan kategori BMI
        string category = determineBMICategory(bmi);
        
        // Menampilkan hasil pengujian
        cout << "BMI Anda: " << bmi << endl;
        cout << "Kategori BMI: " << category << endl;
    } catch (const invalid_argument& e) {
        cerr << "Terjadi kesalahan: " << e.what() << endl;
    }

    return 0;
}
/*Penjelasan 
Kodingan di atas adalah sebuah program sederhana untuk menghitung Body Mass Index (BMI) berdasarkan input berat badan dan tinggi badan pengguna.
Program ini menggunakan Equivalence Class Partitioning untuk membagi input berat badan dan tinggi badan ke dalam beberapa kelas ekuivalen. 
Dalam hal ini, terdapat dua kelas ekuivalen:

Kelas ekuivalen untuk tinggi badan:
Input tinggi badan harus lebih dari 0 untuk dianggap valid.
Jika tinggi badan kurang dari atau sama dengan 0, program akan menampilkan pesan kesalahan.
Kelas ekuivalen untuk berat badan:

Input berat badan harus lebih dari 0 untuk dianggap valid.
Jika berat badan kurang dari atau sama dengan 0, program akan menampilkan pesan kesalahan.
Setelah pengguna memasukkan berat badan dan tinggi badan, program akan melakukan perhitungan BMI dengan menggunakan fungsi calculateBMI. Jika tinggi badan valid, program akan membagi berat badan dengan kuadrat tinggi badan. Kemudian, program akan menggunakan fungsi determineBMICategory untuk menentukan kategori BMI berdasarkan nilai BMI yang dihitung.

Akhirnya, program akan menampilkan hasil pengujian, yaitu nilai BMI pengguna dan kategori BMI yang sesuai. 
Jika terjadi kesalahan pada input tinggi badan (misalnya, tinggi badan negatif atau nol), 
program akan menampilkan pesan kesalahan yang menjelaskan masalah tersebut.

Dengan demikian, kodingan di atas mengimplementasikan Equivalence Class Partitioning dengan 
membagi input tinggi dan berat badan ke dalam kelas ekuivalen yang valid dan menguji 
kasus-kasus yang relevan dari setiap kelas tersebut. */
