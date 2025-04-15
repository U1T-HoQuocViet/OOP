#include <iostream>
#include <math.h>

using namespace std;

#define eps 1e-6

class Diem
{
    private:
        float x, y;
    public:
        Diem(float x = 0, float y = 0) : x(x), y(y) {}
        Diem(const Diem &d) : x(d.x), y(d.y) {}
        ~Diem() {}

        void Nhap()
        {
            cin >> x >> y;
        }
        void Xuat() const
        {
            cout << "(" << x << ", " << y << ")";
        }
        float GetX() const { return x; }
        float GetY() const { return y; }
        void SetX(float x) { this->x = x; }
        void SetY(float y) { this->y = y; }
        void SetXY(float x, float y) { this->x = x; this->y = y; }

        float KhoangCach(const Diem & d) const
        {
            return sqrt((x - d.x)*(x-d.x) + (y - d.y)*(y - d.y));
        }

        void Move(float dx, float dy)
        {
            x += dx;
            y += dy;
        }

        void operator=(const Diem &d)
        {
            x = d.x;
            y = d.y;
        }

        bool operator==(const Diem &d)
        {
            return (x == d.x && y == d.y);
        }

        friend istream& operator>>(istream &is ,Diem &d)
        {
            d.Nhap();
            return is;
        }

        friend ostream& operator<<(ostream &os ,const Diem &d)
        {
            d.Xuat();
            return os;
        }
};