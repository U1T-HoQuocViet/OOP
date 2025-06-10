#pragma once

#include <iostream>

using namespace std;

int daysofmonth[]{31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31};
class Date
{
    private:
        int d, m, y;
    public:
        Date(int day = 1, int month = 1, int year = 2000);
        Date(const Date &d);

        void Nhap();
        void Xuat() const;

        int GetDay() const { return d; }
        int GetMonth() const { return m; }
        int GetYear() const { return y; }

        static int LaySoNgay(int month, int year);
        int LaySoNgay() const;

        static int QuyDoi(const Date &d);
        int KhoangCach(const Date &d) const;

        bool KiemTraHopLe() const;
};

Date::Date(int day, int month, int year) : d(day), m(month), y(year) {}
Date::Date(const Date &d) : d(d.d), m(d.m), y(d.y) {}

void Date::Nhap()
{
    cin >> d >> m >> y;
}

void Date::Xuat() const
{
    cout << d << "/" << m << "/" << y;
}

int Date::LaySoNgay(int month, int year)
{
    if(month > 12 || month < 1)
        return -1;
    return daysofmonth[month - 1] + ((year % 4 == 0 && year % 100 != 0 && month == 2) ? 1 : 0);
}

int Date::LaySoNgay() const
{
    return LaySoNgay(m, y);
}

bool Date::KiemTraHopLe() const
{
    return (d > 0 && d <= LaySoNgay(m, y) && m > 0 && m <= 12 && y > 0);
}

istream& operator>>(istream &is, Date &d)
{
    d.Nhap();
    return is;
}

ostream& operator<<(ostream &os, const Date &d)
{
    d.Xuat();
    return os;
}

int Date::QuyDoi(const Date &d)
{
    return d.y * 365 + d.m * 30 + d.d + d.y/4 - d.y/100 + d.y/400;
}

int  Date::KhoangCach(const Date &d) const
{
    int days1 = QuyDoi(*this);
    int days2 = QuyDoi(d);

    return abs(days1 - days2);
}