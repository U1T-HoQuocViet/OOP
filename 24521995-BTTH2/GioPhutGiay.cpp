
#include <iostream>

using namespace std;



class GioPhutGiay
{
    public :
        GioPhutGiay(int h ,int m ,int s)
        {
            Set(h ,m ,s);
        }

        GioPhutGiay()
        {

        }

    private :
        int giay;
        int phut;
        int gio;

        bool KiemTraHopLe()
        {
            return KiemTraHopLe(gio ,phut ,giay);
        }

    public :
        void Set(int h ,int m ,int s)
        {
            if(KiemTraHopLe(h ,m ,s))
            {
                this->giay = s;
                this->phut = m;
                this->gio = h;
            }
        }

        static bool KiemTraHopLe(int h ,int m ,int s)
        {
            if(h < 0 || h > 23)
                return false;
            if(m < 0 || m > 59)
                return false;
            if(s < 0 || s > 59)
                return false;
            return true;
        }

        void Nhap()
        {
            do
            {
                cout<<"Nhap gio/phut/giay : "<<endl;
                cin>>gio>>phut>>giay;
            } while(!KiemTraHopLe());
        }

        void Xuat() const
        {
            cout<<gio<<":"<<phut<<":"<<giay<<endl;
        }

        void TinhCongThemMotGiay()
        {
            giay += 1;
            if(giay > 59)
            {
                giay = 0;
                phut += 1;
                if(phut > 59)
                    phut = 0;
                    gio += 1;
                    if(gio > 23)
                        gio = 0;
            }
        }
    
} typedef Time;

int main()
{
    GioPhutGiay a;
    a.Nhap();
    cout<<"Thoi gian hien tai : ";a.Xuat();
    a.TinhCongThemMotGiay();
    cout<<"Thoi gian cong them 1 giay : ";a.Xuat();
}