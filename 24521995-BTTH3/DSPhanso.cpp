#include "Phanso.cpp"
#include <algorithm>
#include <math.h>
#include <vector>


class DSPhanso
{
    private:
        vector<PhanSo> dsPhanSo;
    public:
        DSPhanso();
        ~DSPhanso();

        void Nhap();
        void Xuat() const;

        float Tong() const;
        PS TongPS() const; 
        PS TimLonNhat() const;
        PS TimNhoNhat() const;
        PS TimPSTheoTuSo() const; //tim phan so co tu so la so nguyen to lon nhat

        void SapXepTangDan();
        void SapXepGiamDan();
};

DSPhanso::DSPhanso() {}
DSPhanso::~DSPhanso() {}

void DSPhanso::Nhap()
{
    int n;
    cout << "Nhap so phan so: ";cin >> n;
    dsPhanSo.resize(n);
    for(int i = 0; i < n; i++)
        cin >> dsPhanSo[i];
}

void DSPhanso::Xuat() const
{
    cout << "Cac phan so la: " << endl;
    for(int i = 0; i < dsPhanSo.size(); i++)
        cout << dsPhanSo[i] << (i == dsPhanSo.size() - 1 ? "." : ", ");
}

float DSPhanso::Tong() const
{
    float tong = 0;
    for(int i = 0; i < dsPhanSo.size(); i++)
        tong += dsPhanSo[i].GiaTri();
    return tong;
}

PhanSo DSPhanso::TongPS() const
{
    PhanSo tong;
    for(int i = 0; i < dsPhanSo.size(); i++)
        tong = tong + dsPhanSo[i];
    return tong;
}

PhanSo DSPhanso::TimLonNhat() const
{
    PhanSo max = dsPhanSo[0];
    for(int i = 1; i < dsPhanSo.size(); i++)
        if(dsPhanSo[i].GiaTri() > max.GiaTri())
            max = dsPhanSo[i];
    return max;
}

PhanSo DSPhanso::TimNhoNhat() const
{
    PhanSo min = dsPhanSo[0];
    for(int i = 1; i < dsPhanSo.size(); i++)
        if(dsPhanSo[i].GiaTri() < min.GiaTri())
            min = dsPhanSo[i];
    return min;
}

PhanSo DSPhanso::TimPSTheoTuSo() const
{
    int max = -1;
    int m_Prime = 0;
    for(int i = 1; i < dsPhanSo.size(); i++)
        if(IsPrime(dsPhanSo[i].GetTuso()) && dsPhanSo[i].GetTuso() > m_Prime)
        {
            m_Prime = dsPhanSo[i].GetTuso();
            max = i;
        }
    if(max != -1)
        return dsPhanSo[max];
    return PhanSo();
}

void DSPhanso::SapXepTangDan()
{
    sort(dsPhanSo.begin(), dsPhanSo.end(), [](const PhanSo &a, const PhanSo &b) {
        return a.GiaTri() < b.GiaTri();
    });
}
void DSPhanso::SapXepGiamDan()
{
    sort(dsPhanSo.begin(), dsPhanSo.end(), [](const PhanSo &a, const PhanSo &b) {
        return a.GiaTri() > b.GiaTri();
    });
}

int main()
{
    DSPhanso ds;
    ds.Nhap();
    ds.Xuat();cout<<endl;
    cout << "Tong gia tri cac phan so: " << ds.Tong() << endl;
    cout << "Tong phan so: ";ds.TongPS().Xuat();cout<<endl;
    cout << "Phan so lon nhat: ";ds.TimLonNhat().Xuat();cout<<endl;
    cout << "Phan so nho nhat: ";ds.TimNhoNhat().Xuat();cout<<endl;
    cout << "Phan so co tu so la so nguyen to lon nhat: ";ds.TimPSTheoTuSo().Xuat();cout<<endl;

    ds.SapXepTangDan();
    cout << "Cac phan so sau khi sap xep tang dan: ";ds.Xuat();cout<<endl;

    ds.SapXepGiamDan();
    cout << "Cac phan so sau khi sap xep giam dan: ";ds.Xuat();cout<<endl;

    return 0;
}