#include "GiaoDichBDS/QuanLyGD_BDS.h"


int main() 
{
    QuanLyBDS qlbd;
    qlbd.NhapDSGiaoDichBDS();

    qlbd.SoLuongTungGiaoDich();

    cout << "Trung binh thanh tien chung cu: " << qlbd.TrungBinhThanhTienChungCu() << endl;

    GiaoDichNhaPho* gd_nha_pho_cao_nhat = qlbd.TimGiaoDichNhaPhoCaoNhat();
    if (gd_nha_pho_cao_nhat != nullptr) 
    {
        cout << "Giao dich nha pho cao nhat: " << endl;
        gd_nha_pho_cao_nhat->Xuat();
    } 
    else 
    {
        cout << "Khong co giao dich nha pho nao." << endl;
    }

    qlbd.XuatCacGiaoDichVaoNgayCuThe();
    return 0;
}