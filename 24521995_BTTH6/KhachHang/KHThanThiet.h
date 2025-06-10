#include "KhachHang.h"

class KHThanThiet : public KhachHang
{
    private:
        int so_nam_than_thiet;

    public:
        KHThanThiet(string = "", int = 0, int = 0, int = 0);

        void Nhap(ifstream&);
        int TinhTien() const;
        string GetLoaiKhachHang() const;
};

KHThanThiet::KHThanThiet(string ten_khach_hang, int so_luong_hang, int don_gia_hang, int so_nam_than_thiet)
    : KhachHang(ten_khach_hang, so_luong_hang, don_gia_hang), so_nam_than_thiet(so_nam_than_thiet) {}

void KHThanThiet::Nhap(ifstream& file)
{
    // KhachHang::Nhap(file);
    getline(file, ten_khach_hang);
    file >> so_luong_hang >> don_gia_hang >> so_nam_than_thiet;
    file.ignore();
}

int KHThanThiet::TinhTien() const
{
    return so_luong_hang * don_gia_hang * (1 - max(0.5, 0.05 * so_nam_than_thiet)) * 1.1;
}

string KHThanThiet::GetLoaiKhachHang() const
{
    return "Khach Hang Thanh Thiet";
}