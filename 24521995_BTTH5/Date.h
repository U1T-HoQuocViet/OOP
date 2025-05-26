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
        ~Date();

        void Nhap();
        void Xuat() const;

        static int LaySoNgay(int month, int year);
        int LaySoNgay() const;

        int GetDay() const;
        int GetMonth() const;
        int GetYear() const;

        void SetDay(int day);
        void SetMonth(int month);
        void SetYear(int year);

        bool IsValid() const;

        static int QuyDoi(const Date &d);
        int KhoangCach(const Date &d) const;

        Date operator+(int);
        Date operator-(int);
        Date operator++();
        Date operator++(int);
        Date operator--();
        Date operator--(int);

        friend istream& operator>>(istream &is, Date &d);
        friend ostream& operator<<(ostream &os, const Date &d);
};

Date::Date(int day, int month, int year) : d(day), m(month), y(year) {}
Date::Date(const Date &d) : d(d.d), m(d.m), y(d.y) {}
Date::~Date() {}

void Date::Nhap()
{
    do
    {
        cout << "Nhap ngay/thang/nam: "<<endl;
        cin >> d >> m >> y;
    } while (!IsValid());
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

int Date::GetDay() const { return d; }
int Date::GetMonth() const { return m; }
int Date::GetYear() const { return y; }

void Date::SetDay(int day) { d = day; }
void Date::SetMonth(int month) { m = month; }
void Date::SetYear(int year) { y = year; }


bool Date::IsValid() const
{
    return (d > 0 && d <= LaySoNgay(m, y) && m > 0 && m <= 12 && y > 0);
}

Date Date::operator+(int t)
{
    Date temp(*this);
    temp.d += t;
    while(temp.d > LaySoNgay())
    {
        temp.d -= LaySoNgay();
        temp.m++;
        if(temp.m > 12)
        {
            temp.m = 1;
            temp.y++;
        }
    }
    return temp;
}

Date Date::operator-(int t)
{
    Date temp(*this);
    temp.d -= t;
    while(temp.d < 0)
    {
        temp.d += LaySoNgay();
        temp.m--;
        if(temp.m <= 0)
        {
            temp.m = 12;
            temp.y--;
        }
    }
    return temp;
}

Date Date::operator++()
{
    d++;
    if (d > LaySoNgay(m, y))
    {
        d = 1;
        m++;
        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    d++;
    if (d > LaySoNgay(m, y))
    {
        d = 1;
        m++;
        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
    return temp;
}

Date Date::operator--()
{
    d--;
    if (d < 1)
    {
        m--;
        if (m < 1)
        {
            m = 12;
            y--;
        }
        d = LaySoNgay(m, y);
    }
    return *this;
}

Date Date::operator--(int)
{
    Date temp = *this;
    d--;
    if (d < 1)
    {
        m--;
        if (m < 1)
        {
            m = 12;
            y--;
        }
        d = LaySoNgay(m, y);
    }
    return temp;
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