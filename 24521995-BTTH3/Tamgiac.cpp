#include "Diem.cpp"

class TamGiac
{
    private:
        Diem A, B, C;
        void LayDoDai3Canh(float &, float &, float &) const;

    public:
        TamGiac(const Diem A = Diem() ,const Diem B = Diem() ,const Diem C = Diem());
        TamGiac(float x1 ,float y1, float x2, float y2, float x3, float y3);

        Diem GetA() const;
        Diem GetB() const; 
        Diem GetC() const;

        void SetA(Diem A);
        void SetB(Diem B);
        void SetC(Diem C);
        void SetABC(Diem A, Diem B, Diem C);

        void Nhap();
        void Xuat() const;

        bool KiemTraHopLe() const;

        string LoaiTamGiac() const;
        float ChuVi() const;
        float DienTich() const;

        void TinhTien(float dx ,float dy);
        void Quay(float goc);
        void PhongTo(float n);
        void ThuNho(float n);
};

void TamGiac::LayDoDai3Canh(float &a, float &b, float &c) const
{
    a = A.KhoangCach(B);
    b = B.KhoangCach(C);
    c = C.KhoangCach(A);
}

TamGiac::TamGiac(Diem A, Diem B, Diem C) : A(A), B(B), C(C) {}
TamGiac::TamGiac(float x1 ,float y1, float x2, float y2, float x3, float y3) : A(x1,y1), B(x2,y2), C(x3,y3) {}

Diem TamGiac::GetA() const { return A; }
Diem TamGiac::GetB() const { return B; }
Diem TamGiac::GetC() const { return C; }

void TamGiac::SetA(Diem A) { this->A = A; }
void TamGiac::SetB(Diem B) { this->B = B; }
void TamGiac::SetC(Diem C) { this->C = C; }
void TamGiac::SetABC(Diem A, Diem B, Diem C) { this->A = A; this->B = B; this->C = C; }

void TamGiac::Nhap()
{
    cout << "Nhap toa do cac dinh : " << endl;
    cout << "Nhap dinh A: " << endl;cin>>A;
    cout << "Nhap dinh B: " << endl;cin>>B;
    cout << "Nhap dinh C: " << endl;cin>>C;
}

void TamGiac::Xuat() const
{
    cout << "Cac dinh cua tam giac la: " << A << " ,"<< B << " ,"<< C;
}

bool TamGiac::KiemTraHopLe() const
{
    float a, b, c;
    LayDoDai3Canh(a, b, c);
    return (a + b > c && a + c > b && b + c > a);
}

string TamGiac::LoaiTamGiac() const
{
    float a, b, c;
    LayDoDai3Canh(a, b, c);
    if(!KiemTraHopLe()) 
        return "Khong phai tam giac";
    if (a == b && b == c) 
        return "Tam giac deu";
    if (a == b || a == c || b == c) 
        if(a*a + b*b - c*c <= eps || a*a + c*c - b*b <= eps || b*b + c*c - a*a <= eps)
            return "Tam giac vuong can";
        else
            return "Tam giac can";
    if(a*a + b*b - c*c <= eps || a*a + c*c - b*b <= eps || b*b + c*c - a*a <= eps)
        return "Tam giac vuong";
    return "Tam giac thuong";
}

float TamGiac::ChuVi() const
{
    float a, b, c;
    LayDoDai3Canh(a, b, c);
    return a + b + c;
}

float TamGiac::DienTich() const
{
    float a, b, c;
    LayDoDai3Canh(a, b, c);
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void TamGiac::TinhTien(float dx ,float dy)
{
    A.Move(dx, dy);
    B.Move(dx, dy);
    C.Move(dx, dy);
}
void TamGiac::Quay(float goc)
{
    A.Move(A.GetX() * cos(goc) - A.GetY() * sin(goc), A.GetX() * sin(goc) + A.GetY() * cos(goc));
    B.Move(B.GetX() * cos(goc) - B.GetY() * sin(goc), B.GetX() * sin(goc) + B.GetY() * cos(goc));
    C.Move(C.GetX() * cos(goc) - C.GetY() * sin(goc), C.GetX() * sin(goc) + C.GetY() * cos(goc));
}

void TamGiac::PhongTo(float n)
{
    A.SetXY(A.GetX() * n, A.GetY() * n);
    B.SetXY(B.GetX() * n, B.GetY() * n);
    C.SetXY(C.GetX() * n, C.GetY() * n);
}

void TamGiac::ThuNho(float n)
{
    A.SetXY(A.GetX() / n, A.GetY() / n);
    B.SetXY(B.GetX() / n, B.GetY() / n);
    C.SetXY(C.GetX() / n, C.GetY() / n);
}