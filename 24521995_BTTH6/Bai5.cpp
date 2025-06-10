#include "GiaSuc/NongTrai.h"

int main() {
    NongTrai nt;

    nt.NhapDanhSachGiaSuc();

    nt.SoLuongTungLoai();
    
    cout << "Tong so lit sua da cho: " << nt.TongSoLitSuaDaCho() << endl;

    return 0;
}

