#include "KhachHang.h"

class KHDacBiet : public KhachHang
{

    public:
        KHDacBiet(string = "", int = 0, int = 0);

        int TinhTien() const;
        string GetLoaiKhachHang() const;
};

KHDacBiet::KHDacBiet(string ten_khach_hang, int so_luong_hang, int don_gia_hang)
    : KhachHang(ten_khach_hang, so_luong_hang, don_gia_hang) {}

int KHDacBiet::TinhTien() const
{
    return so_luong_hang * don_gia_hang * 0.5 * 1.1;
}

string KHDacBiet::GetLoaiKhachHang() const
{
    return "Khach Hang Dac Biet";
}