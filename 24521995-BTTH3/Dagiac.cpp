// #include "Diem.cpp"
#include "Tamgiac.cpp"
#include <vector>


class DaGiac
{
    private:
        int n;
        vector<Diem> dsDiem;
    public:
        DaGiac() {}
        ~DaGiac() {}

        void SetDiem(int i ,const Diem & d)
        {
            if(i >= 0 && i < n)
                dsDiem[i] = d;
        }

        Diem GetDiem(int i) const
        {
            if(i >= 0 && i < n)
                return dsDiem[i];
            return Diem();
        }

        void Nhap();
        void Xuat() const;

        float ChuVi() const;
        float DienTich() const;

        void TinhTien(float dx ,float dy);
        void Quay(float goc);
        void PhongTo(float n);
        void ThuNho(float n);
};

void DaGiac::Nhap()
{
    cout << "Nhap so dinh: ";cin >> n;
    dsDiem.resize(n);
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap dinh " << i + 1 << ": " << endl;
        cin >> dsDiem[i];
    }
}

void DaGiac::Xuat() const
{
    cout << "Cac dinh cua da giac la: ";
    for(int i = 0; i < n; i++)
    {
        cout << dsDiem[i] << (i == n - 1 ? "." : ", ");
    }
}

float DaGiac::ChuVi() const
{
    float chuvi = 0;
    for(int i = 0; i < n; i++)
    {
        chuvi += dsDiem[i].KhoangCach(dsDiem[(i + 1) % n]);
    }
    return chuvi;
}

float DaGiac::DienTich() const
{
    TamGiac temp;
    float dientich = 0;
    for(int i = 1; i < n - 1; i++)
    {
        temp.SetABC(dsDiem[0], dsDiem[i], dsDiem[i + 1]);
        dientich += temp.DienTich();
    }
    return dientich;
}

void DaGiac::TinhTien(float dx ,float dy)
{
    for(int i = 0; i < n; i++)
        dsDiem[i].Move(dx, dy);
}
void DaGiac::Quay(float goc)
{
    for(int i = 0; i < n; i++)
        dsDiem[i].Move(dsDiem[i].GetX() * cos(goc) - dsDiem[i].GetY() * sin(goc), dsDiem[i].GetX() * sin(goc) + dsDiem[i].GetY() * cos(goc));
}
void DaGiac::PhongTo(float n)
{
    for(int i = 0; i < n; i++)
        dsDiem[i].SetXY(dsDiem[i].GetX() * n, dsDiem[i].GetY() * n);
}
void DaGiac::ThuNho(float n)
{
    for(int i = 0; i < n; i++)
        dsDiem[i].SetXY(dsDiem[i].GetX() / n, dsDiem[i].GetY() / n);
}