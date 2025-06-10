#include "KhachHang/QuanLyMuaHang.h"

int main() {
    QuanLyMuaHang qlmh;

    qlmh.TaiTepKhachHang("test.inp");

    qlmh.GhiTepKhachHang("test.out");

    return 0;
}