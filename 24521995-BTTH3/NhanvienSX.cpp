#include <vector>
#include "Date.cpp"

class NhanVienSX
{
    private:
        int ma_nv;
        string name;
        Date birth;
        int so_san_pham;
        int don_gia_sp;
    public:
        NhanVienSX(int = 0, string = "", Date = Date(), int = 0, int = 0);
        NhanVienSX(const NhanVienSX &c);
        ~NhanVienSX();

        void SetSoSanPham(int so_san_pham) { this->so_san_pham = so_san_pham; }
        void SetDonGiaSP(int don_gia_sp) { this->don_gia_sp = don_gia_sp; }

        int GetMaNV() const { return ma_nv; }
        string GetName() const { return name; }
        Date GetBirth() const { return birth; }
        int GetSoSanPham() const { return so_san_pham; }
        int GetDonGiaSP() const { return don_gia_sp; }

        void Nhap();
        void Xuat() const;

        int TienLuong() const;

        friend istream &operator>>(istream &is, NhanVienSX &nv);
        friend ostream &operator<<(ostream &os, const NhanVienSX &nv);

} typedef NVSX;

NhanVienSX::NhanVienSX(int ma_nv, string name, Date birth, int so_san_pham, int don_gia_sp)
{
    this->ma_nv = ma_nv;
    this->name = name;
    this->birth = birth;
    this->so_san_pham = so_san_pham;
    this->don_gia_sp = don_gia_sp;
}

NhanVienSX::NhanVienSX(const NhanVienSX &c)
{
    this->ma_nv = c.ma_nv;
    this->name = c.name;
    this->birth = c.birth;
    this->so_san_pham = c.so_san_pham;
    this->don_gia_sp = c.don_gia_sp;
}

NhanVienSX::~NhanVienSX() {}

void NhanVienSX::Nhap()
{
    cout <<"Nhap thong tin nhan vien san xuat: " << endl;
    cout <<"+ Ma nhan vien: "; cin >> ma_nv;
    cout <<"+ Ho ten: "; cin.ignore(); getline(cin, name);
    cout <<"+ Ngay sinh: "<<endl; cin>>birth;
    cout <<"+ So san pham: "; cin >> so_san_pham;
    cout <<"+ Don gia san pham: "; cin >> don_gia_sp;
}

void NhanVienSX::Xuat() const
{
    cout << "Ma nhan vien: " << ma_nv << endl;
    cout << "Ho ten: " << name << endl;
    cout << "Ngay sinh: " << birth << endl; 
    cout << "So san pham: " << so_san_pham << endl;
    cout << "Don gia san pham: " << to_string(don_gia_sp) << endl;
}

int NhanVienSX::TienLuong() const
{
    return so_san_pham * don_gia_sp;
}

istream &operator>>(istream &is, NhanVienSX &nv)
{
    nv.Nhap();
    return is;
}

ostream &operator<<(ostream &os, const NhanVienSX &nv)
{
    nv.Xuat();
    return os;
}

class DSNhanVienSX
{
    private:
        vector<NVSX> dsNhanVien;
    public:
        DSNhanVienSX();
        ~DSNhanVienSX();

        void Nhap();
        void Xuat() const;

        NVSX NVCoLuongThapNhat() const;
        int TongLuong() const;
        NVSX NVCoTuoiCaoNhat() const;

        void SapXepTangDanTheoLuong();
};

DSNhanVienSX::DSNhanVienSX() {}
DSNhanVienSX::~DSNhanVienSX() {}

void DSNhanVienSX::Nhap()
{
    int n;
    cout << "Nhap so luong nhan vien: "; cin >> n;
    dsNhanVien.resize(n);
    for(int i = 0; i < n; i++)
        cin >> dsNhanVien[i];
}

void DSNhanVienSX::Xuat() const
{
    
    for(int i = 0; i < dsNhanVien.size(); i++)
        cout << dsNhanVien[i]<<endl;
}

NVSX DSNhanVienSX::NVCoLuongThapNhat() const
{
    int min = 0;
    for(int i = 1; i < dsNhanVien.size(); i++)
        if(dsNhanVien[i].TienLuong() < dsNhanVien[min].TienLuong())
            min = i;
    return dsNhanVien[min];
}

int DSNhanVienSX::TongLuong() const
{
    int tong = 0;
    for(int i = 0; i < dsNhanVien.size(); i++)
        tong += dsNhanVien[i].TienLuong();
    return tong;
}

NVSX DSNhanVienSX::NVCoTuoiCaoNhat() const
{
    int _s = 0;
    for(int i = 1; i < dsNhanVien.size(); i++)
        if(dsNhanVien[i].GetBirth() < dsNhanVien[_s].GetBirth())
            _s = i;
    return dsNhanVien[_s];
}

void DSNhanVienSX::SapXepTangDanTheoLuong()
{
    for(int i = 0; i < dsNhanVien.size() - 1; i++)
        for(int j = i + 1; j < dsNhanVien.size(); j++)
            if(dsNhanVien[i].TienLuong() > dsNhanVien[j].TienLuong())
                swap(dsNhanVien[i], dsNhanVien[j]);
}

int main()
{
    DSNhanVienSX ds;
    ds.Nhap();
    cout << " - Danh sach nhan vien san xuat la: " << endl;
    ds.Xuat();
    cout << " - Nhan vien co luong thap nhat: " << ds.NVCoLuongThapNhat().GetName() << endl;
    cout << " - Tong luong phai tra: " << ds.TongLuong() << endl;
    cout << " - Nhan vien co tuoi cao nhat: " << ds.NVCoTuoiCaoNhat().GetName() << endl;
    
    ds.SapXepTangDanTheoLuong();
    cout << " - Danh sach nhan vien sau khi sap xep tang dan theo luong: " << endl;
    ds.Xuat();
}