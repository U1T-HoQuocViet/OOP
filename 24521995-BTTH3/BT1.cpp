#include "Tamgiac.cpp"

int main()
{
    TamGiac tg;
    tg.Nhap();
    tg.Xuat();cout<<endl;

    cout << "Chu vi: " << tg.ChuVi() << endl;
    cout << "Dien tich: " << tg.DienTich() << endl;
    cout << "Loai tam giac: " << tg.LoaiTamGiac() << endl;

    tg.TinhTien(2, 3);
    cout << "Tam giac sau khi tinh tien: ";
    tg.Xuat();cout<<endl;

    tg.Quay(60);
    cout << "Tam giac sau quay 60 do: ";
    tg.Xuat();cout<<endl;

    tg.PhongTo(2);
    cout << "Tam giac sau khi phong to gap 2 lan: ";
    tg.Xuat();cout<<endl;

    tg.ThuNho(4);
    cout << "Tam giac sau khi thu nho gap 2 lan: ";
    tg.Xuat();cout<<endl;
}