// TaiXiu.cpp

#include "TaiXiu.h"

using namespace std;

TaiXiu::TaiXiu(float _wallet) {
    this->wallet = _wallet;
}

void TaiXiu::start() {
    // fstream file;
    // file.open("wallet.bin", ios::binary);
    int i = 0;
    while (true) {
        system("cls");
        float tienCuoc;
        string dat;
        cout <<     "#####################################\n"
            <<      "#     Nha cai den tu Vanphat111     #\n"
            <<      "#   Nguoi ko chs ko bao gio thang   #\n"
            <<      "#####################################\n\n";
        if (i != 0) cout << "Phien truoc: " << *this << endl;
        cout << "wallet: " << this->wallet << endl;
        roll();
        cout << "Moi dat tien cuoc (Cuoc = 0 => thoat): ";
        cin >> tienCuoc;
        if (tienCuoc == 0) {
            // file << this->wallet;
            break;
        }
        cout << "Moi dat ben: ";
        cin >> dat;
        if (checkWinLose(dat)) wallet += tienCuoc;
        else wallet -= tienCuoc;
        cout << "Ket thuc phien: " << *this;
        _sleep(1000);
        i++;
    }
}

bool TaiXiu::checkWinLose(string input) {
    int chosse;
    if (input[0] == 'T' || input[0] == 't') chosse = 1;
    else if (input[0] == 'X' || input[0] == 'x') chosse = 2;
    
    int n;
    if (this->x1 + this->x2 + this->x3 > 10) n = 1;
    else n = 2;
    return chosse == n;
}

void TaiXiu::roll() {
    this->x1 = randomNumber() % 6 + 1;
    this->x2 = randomNumber() % 6 + 1;
    this->x3 = randomNumber() % 6 + 1;
}

std::ostream &operator<<(std::ostream &out, TaiXiu &TaiXiu) {
    out << "[" << TaiXiu.x1 << ", " << TaiXiu.x2 << ", " << TaiXiu.x3 <<"]";
    return out;
}

std::istream &operator>>(std::istream &in, TaiXiu &TaiXiu) {
    in >> TaiXiu.wallet;
    return in;
}
