#include <vector>
#include "Date.cpp"

class NhanVienVP
{
    private:
        int ma_nv;
        string name;
        Date birth;
        int luong;
    public:
        NhanVienVP(int = 0, string = "", Date = Date(), int = 0);
        NhanVienVP(const NhanVienVP &c);
        ~NhanVienVP() {}

        void SetLuong(int luong) { this->luong = luong; }

        int GetMaNV() const { return ma_nv; }
        string GetName() const { return name; }
        Date GetBirth() const { return birth; }
        int GetLuong() const { return luong; }

        void Nhap();
        void Xuat() const;

        friend istream &operator>>(istream &is, NhanVienVP &nv);
        friend ostream &operator<<(ostream &os, const NhanVienVP &nv);

} typedef NVVP;

NhanVienVP::NhanVienVP(int ma_nv, string name, Date birth, int luong)
{
    this->ma_nv = ma_nv;
    this->name = name;
    this->birth = birth;
    this->luong = luong;
}

NhanVienVP::NhanVienVP(const NhanVienVP &c)
{
    this->ma_nv = c.ma_nv;
    this->name = c.name;
    this->birth = c.birth;
    this->luong = c.luong;
}

void NhanVienVP::Nhap()
{
    cout <<"Nhap thong tin nhan vien van phong: " << endl;
    cout <<"+ Ma nhan vien: "; cin >> ma_nv;
    cout <<"+ Ho ten: "; cin.ignore(); getline(cin, name);
    cout <<"+ Ngay sinh: "<<endl; cin>>birth;
    cout <<"+ Luong: "; cin >> luong;
}

void NhanVienVP::Xuat() const
{
    cout << "Ma nhan vien: " << ma_nv << endl;
    cout << "Ho ten: " << name << endl;
    cout << "Ngay sinh: " << birth << endl; 
    cout << "Luong: " << to_string(luong) << endl;
}

istream &operator>>(istream &is, NhanVienVP &nv)
{
    nv.Nhap();
    return is;
}

ostream &operator<<(ostream &os, const NhanVienVP &nv)
{
    nv.Xuat();
    return os;
}

class DSNhanVienVP
{
    private:
        vector<NVVP> dsNhanVien;
    public:
        DSNhanVienVP() {}
        ~DSNhanVienVP() {}

        void Nhap();
        void Xuat() const;

        NVVP NVCoLuongCaoNhat() const;
        int TongLuong() const;
        NVVP NVCoTuoiCaoNhat() const;

        void SapXepTangDanTheoLuong();
};


void DSNhanVienVP::Nhap()
{
    int n;
    cout << "Nhap so luong nhan vien van phong: "; cin >> n;
    dsNhanVien.resize(n);
    for(int i = 0; i < n; i++)
        cin >> dsNhanVien[i];
}

void DSNhanVienVP::Xuat() const
{
    // cout << "Danh sach nhan vien van phong la: " << endl;
    for(int i = 0; i < dsNhanVien.size(); i++)
        cout << dsNhanVien[i] <<endl;
}

NVVP DSNhanVienVP::NVCoLuongCaoNhat() const
{
    int max = 0;
    for(int i = 1; i < dsNhanVien.size(); i++)
        if(dsNhanVien[i].GetLuong() > dsNhanVien[max].GetLuong())
            max = i;
    return dsNhanVien[max];
}

int DSNhanVienVP::TongLuong() const
{
    int tong = 0;
    for(int i = 0; i < dsNhanVien.size(); i++)
        tong += dsNhanVien[i].GetLuong();
    return tong;
}

NVVP DSNhanVienVP::NVCoTuoiCaoNhat() const
{
    int _s = 0;
    for(int i = 1; i < dsNhanVien.size(); i++)
        if(dsNhanVien[i].GetBirth() < dsNhanVien[_s].GetBirth())
            _s = i;
    return dsNhanVien[_s];
}

void DSNhanVienVP::SapXepTangDanTheoLuong()
{
    for(int i = 0; i < dsNhanVien.size() - 1; i++)
        for(int j = i + 1; j < dsNhanVien.size(); j++)
            if(dsNhanVien[i].GetLuong() > dsNhanVien[j].GetLuong())
                swap(dsNhanVien[i], dsNhanVien[j]);
}

int main()
{
    DSNhanVienVP ds;
    ds.Nhap();
    cout << " - Danh sach nhan vien van phong : " << endl;
    ds.Xuat();
    cout << " - Nhan vien co luong cao nhat: " << ds.NVCoLuongCaoNhat().GetName() << endl;
    cout << " - Tong luong phai tra: " << to_string(ds.TongLuong()) << endl;
    cout << " - Nhan vien co tuoi cao nhat: " << ds.NVCoTuoiCaoNhat().GetName() << endl;
    ds.SapXepTangDanTheoLuong();
    cout << " - Danh sach nhan vien van phong sau khi sap xep tang dan theo luong: " << endl;
    ds.Xuat();
    return 0;
}