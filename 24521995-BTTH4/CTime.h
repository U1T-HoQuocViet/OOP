#include <iostream>

using namespace std;

class Time
{
    private :
        int h ,m ,s;
    public :
        Time(int h = 0 ,int m = 0 ,int s = 0);
        Time(const Time &t);
        ~Time();
        
        void Nhap();
        void Xuat() const;
        
        int GetH() const; 
        int GetM() const; 
        int GetS() const; 
        
        void SetH(int h);
        void SetM(int m);
        void SetS(int s);
        
        Time operator+(int);
        Time operator-(int);
        Time operator++();
        Time operator++(int);
        Time operator--();
        Time operator--(int);
        
        friend istream& operator>>(istream &is ,Time &t);
        friend ostream& operator<<(ostream &os ,const Time &t);
};

Time::Time(int h, int m, int s) : h(h), m(m), s(s) {}
Time::Time(const Time &t) : h(t.h), m(t.m), s(t.s) {}
Time::~Time() {}

int Time::GetH() const { return h; }
int Time::GetM() const { return m; }
int Time::GetS() const { return s; }

void Time::SetH(int h) { this->h = h; }
void Time::SetM(int m) { this->m = m; }
void Time::SetS(int s) { this->s = s; }

void Time::Nhap()
{
    cin >> h >> m >> s;
}

void Time::Xuat() const
{
    cout << h << ":" << m << ":" << s;
}

Time Time::operator+(int t)
{
    Time temp(*this);
    temp.s += t;
    while(temp.s >= 60)
    {
        temp.s -= 60;
        temp.m++;
        if(temp.m >= 60)
        {
            temp.m = 0;
            temp.h++;
            if(temp.h >= 24)
                temp.h = 0;
        }
    }
    return temp;
}

Time Time::operator-(int t)
{
    Time temp(*this);
    temp.s -= t;
    while(temp.s < 0)
    {
        temp.s += 60;
        temp.m--;
        if(temp.m < 0)
        {
            temp.m = 59;
            temp.h--;
            if(temp.h < 0)
                temp.h = 23;
        }
    }
    return temp;
}

Time Time::operator++()
{
    s++;
    if(s >= 60)
    {
        s = 0;
        m++;
        if(m >= 60)
        {
            m = 0;
            h++;
            if(h >= 24)
                h = 0;
        }
    }
    return *this;
}

Time Time::operator++(int)
{
    Time temp = *this;
    s++;
    if(s >= 60)
    {
        s = 0;
        m++;
        if(m >= 60)
        {
            m = 0;
            h++;
            if(h >= 24)
                h = 0;
        }
    }
    return temp;
}

Time Time::operator--()
{
    s--;
    if(s < 0)
    {
        s = 59;
        m--;
        if(m < 0)
        {
            m = 59;
            h--;
            if(h < 0)
                h = 23;
        }
    }
    return *this;
}

Time Time::operator--(int)
{
    Time temp = *this;
    s--;
    if(s < 0)
    {
        s = 59;
        m--;
        if(m < 0)
        {
            m = 59;
            h--;
            if(h < 0)
                h = 23;
        }
    }
    return temp;
}

istream& operator>>(istream &is ,Time &t)
{
    t.Nhap();
    return is;
}

ostream& operator<<(ostream &os ,const Time &t)
{
    t.Xuat();
    return os;
}




