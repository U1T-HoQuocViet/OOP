#include "KhachHang.h"

class KHBinhThuong : public KhachHang
{

    public:
        KHBinhThuong(string = "", int = 0, int = 0);

        int TinhTien() const;
        string GetLoaiKhachHang() const;
};

KHBinhThuong::KHBinhThuong(string ten_khach_hang, int so_luong_hang, int don_gia_hang)
    : KhachHang(ten_khach_hang, so_luong_hang, don_gia_hang) {}

int KHBinhThuong::TinhTien() const
{
    return so_luong_hang * don_gia_hang * 1.1;
}

string KHBinhThuong::GetLoaiKhachHang() const
{
    return "Khach Hang Binh Thuong";
}