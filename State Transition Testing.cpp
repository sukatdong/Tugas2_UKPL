#include <iostream>

using namespace std;

// Enum untuk mewakili status pengecekan bilangan
enum NumberCheckState {
    START,
    DIGIT,
    ACCEPT,
    REJECT
};

// Fungsi untuk melakukan pengecekan bilangan
NumberCheckState checkNumber(int number) {
    if (number <= 0) {
        return REJECT;
    }

    NumberCheckState currentState = START;
    int digitCount = 0;

    while (number > 0) {
        int digit = number % 10;
        number /= 10;

        switch (currentState) {
            case START:
                if (digit >= 1 && digit <= 9) {
                    currentState = DIGIT;
                    digitCount++;
                } else {
                    currentState = REJECT;
                }
                break;
            case DIGIT:
                if (digit >= 0 && digit <= 9) {
                    currentState = DIGIT;
                    digitCount++;
                } else {
                    currentState = REJECT;
                }
                break;
            default:
                break;
        }
    }

    if (currentState == DIGIT && digitCount > 0) {
        return ACCEPT;
    } else {
        return REJECT;
    }
}

int main() {
    int number;
    cout << "Masukkan bilangan: ";
    cin >> number;

    NumberCheckState result = checkNumber(number);

    if (result == ACCEPT) {
        cout << "Bilangan diterima" << endl;
    } else {
        cout << "Bilangan ditolak" << endl;
    }

    return 0;
}

/*Program di atas menggunakan State Transition Testing untuk mengecek apakah suatu bilangan adalah bilangan bulat positif.
Enum NumberCheckState digunakan untuk mewakili setiap status pengecekan bilangan.
Fungsi checkNumber digunakan untuk memeriksa bilangan berdasarkan aturan yang ditentukan.

Dalam fungsi checkNumber, dilakukan pengecekan digit per digit dalam bilangan. 
Jika digit pertama adalah angka antara 1 hingga 9, status berubah menjadi DIGIT dan jumlah digit dihitung. 
Jika digit selanjutnya juga merupakan angka, status tetap di DIGIT dan jumlah digit ditambah. 
Jika digit selanjutnya bukan angka, status berubah menjadi REJECT.
Program membaca bilangan dari input pengguna menggunakan cin.
Setelah bilangan dibaca, program memanggil fungsi checkNumber untuk memeriksa bilangan tersebut.

Hasil pengecekan bilangan (ACCEPT atau REJECT) ditampilkan menggunakan cout.
Dengan menggunakan State Transition Testing, program ini melakukan pengecekan transisi status digit dalam bilangan. 
Jika bilangan memenuhi kondisi transisi yang valid, bilangan tersebut diterima (ACCEPT) sebagai bilangan bulat positif. 
Jika bilangan tidak memenuhi kondisi transisi yang valid, bilangan ditolak (REJECT).
*/
