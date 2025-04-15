#include "Dagiac.cpp"

int main()
{
    DaGiac dg;
    dg.Nhap();
    dg.Xuat();cout<<endl;
    cout << "Chu vi: " << dg.ChuVi() << endl;
    cout << "Dien tich: " << dg.DienTich() << endl;

    dg.TinhTien(2, 3);
    cout << "Da giac sau khi tinh tien: ";
    dg.Xuat();cout<<endl;

    dg.Quay(60);
    cout << "Da giac sau quay 60 do: ";
    dg.Xuat();cout<<endl;

    dg.PhongTo(2);
    cout << "Da giac sau khi phong to gap 2 lan: ";
    dg.Xuat();cout<<endl;

    dg.ThuNho(4);
    cout << "Da giac sau khi thu nho gap 2 lan: ";
    dg.Xuat();cout<<endl;

    return 0;

}