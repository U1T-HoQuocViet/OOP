#include "NhanVien.h"

class KiemChungVien : public NhanVien 
{
    private:
        int so_loi_tim_duoc;

    public:
        KiemChungVien(string = "", string = "", int = 0, string = "", string = "", ll = 0, int = 0);

        int GetSoLoiTimDuoc() const;

        void SetSoLoiTimDuoc(int);

        void Nhap();
        void Xuat() const;
        string GetLoaiNV() const;
        ll TinhLuong() const;
};

KiemChungVien::KiemChungVien(string ma_nv, string ten_nv, int tuoi_nv, string sdt, string email, ll luong_co_ban, int so_loi)
    : NhanVien(ma_nv, ten_nv, tuoi_nv, sdt, email, luong_co_ban), so_loi_tim_duoc(so_loi) {}

int KiemChungVien::GetSoLoiTimDuoc() const { return so_loi_tim_duoc; }

void KiemChungVien::SetSoLoiTimDuoc(int so_loi) { this->so_loi_tim_duoc = so_loi; }

void KiemChungVien::Nhap() 
{
    NhanVien::Nhap();
    cout << "Nhap so loi tim duoc: ";
    cin >> so_loi_tim_duoc;
}

void KiemChungVien::Xuat() const 
{
    NhanVien::Xuat();
    cout << "+ So gio lam viec: " << so_loi_tim_duoc << endl;
}

string KiemChungVien::GetLoaiNV() const 
{
    return "Kiem Chung Vien";
}

ll KiemChungVien::TinhLuong() const 
{
    return luong_co_ban + so_loi_tim_duoc * 50000;
}