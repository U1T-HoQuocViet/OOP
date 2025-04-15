#include <iostream>

using namespace std;

int daysofmonth[]{31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31};
class NgayThangNam
{
    public : 
        NgayThangNam(int d ,int m ,int y) { Set(d ,m ,y); }

        NgayThangNam() {}

    private:    
        int ngay;
        int thang;
        int nam;

    public:
        bool KiemTraNgayHopLe() const
        {
            return KiemTraNgayHopLe(ngay ,thang ,nam);
        }

        int LaySoNgay() const
        {
            return LaySoNgay(thang ,nam);
        }
    
        static bool KiemTraNgayHopLe(int d ,int m ,int y)
        {
            if(d < 0|| d > LaySoNgay(m ,y))
                return false;
            if(m < 0 || m > 12)
                return false;
            return true;
        }

        static int LaySoNgay(int m ,int y)
        {
            if(m > 12 || m < 1)
                return -1;
            return daysofmonth[m - 1] + ((y%4 == 0 && y%100 != 0 && m == 2)?1:0);
        }

        void Set(int d ,int m ,int y) 
        {
            if(KiemTraNgayHopLe(d ,m ,y))
            {
                ngay = d;
                thang = m;
                nam = y;
            }
        }

        void Nhap() 
        { 
            do
            {
                cout<<"Ngay  : ";cin>>ngay;
                cout<<"Thang : ";cin>>thang;
                cout<<"Nam   : ";cin>>nam;
            } while(!KiemTraNgayHopLe());
        }
        
        void Xuat() const
        {
            cout<<ngay<<"/"<<thang<<"/"<<nam;
        }

        bool operator>(const NgayThangNam &ntn) const
        {
            if(nam == ntn.nam)
            {
                if(thang == ntn.thang)
                {
                    return ngay > ntn.ngay;
                }
                return thang > ntn.thang;
            }
            return nam > ntn.nam;
        }

        bool operator<(const NgayThangNam &ntn) const
        {
            if(nam == ntn.nam)
            {
                if(thang == ntn.thang)
                {
                    return ngay < ntn.ngay;
                }
                return thang < ntn.thang;
            }
            return nam < ntn.nam;
        }


        friend istream& operator>>(istream &is ,NgayThangNam &ntn)
        {
            ntn.Nhap();
            return is;
        }
        friend ostream& operator<<(ostream &os ,const NgayThangNam &ntn)
        {
            ntn.Xuat();
            return os;
        }

} typedef Date;

