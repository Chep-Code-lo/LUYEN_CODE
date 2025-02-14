#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
struct date
{
    int ngay;
    int thang;
    int nam;
};
void nhap(date &x)
{
    cin >> x.ngay;
    cin >> x.thang;
    cin >> x.nam;
}
bool namnhuan(date x)
{
    return (x.nam % 400 == 0) || (x.nam % 4 == 0 && x.nam % 100 != 0);
}
bool check(date x)
{
    if (x.thang == 2)
    {
        if (namnhuan(x) && x.ngay > 29)
            return false;
        if (!namnhuan(x) && x.ngay > 28)
            return false;
    }
    else if (x.thang == 1 || x.thang == 3 || x.thang == 5 || x.thang == 7 || x.thang == 8 || x.thang == 10 || x.thang == 12)
    {
        if (x.ngay > 31)
            return false;
    }
    else
    {
        if (x.ngay > 30)
            return false;
    }
    if (x.thang > 12 || x.thang < 0)
        return false;
    if (x.nam < 0)
        return false;
    return true;
}
ll tong_ngay(date x)
{
    ll kq = 0;
    if (x.thang == 1)
        return x.ngay;
    kq = 31;
    if (x.thang == 2)
        return x.ngay + kq;
    if (x.thang > 2 && namnhuan(x))
    {
        kq += 29;
        if (x.thang == 3)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 4)
            return x.ngay + kq;
        kq += 30;
        if (x.thang == 5)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 6)
            return x.ngay + kq;
        kq += 30;
        if (x.thang == 7)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 8)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 9)
            return x.ngay + kq;
        kq += 30;
        if (x.thang == 10)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 11)
            return x.ngay + kq;
        kq += 30;
        if (x.thang == 12)
            return x.ngay + kq;
    }
    else
    {
        kq += 28;
        if (x.thang == 3)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 4)
            return x.ngay + kq;
        kq += 30;
        if (x.thang == 5)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 6)
            return x.ngay + kq;
        kq += 30;
        if (x.thang == 7)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 8)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 9)
            return x.ngay + kq;
        kq += 30;
        if (x.thang == 10)
            return x.ngay + kq;
        kq += 31;
        if (x.thang == 11)
            return x.ngay + kq;
        kq += 30;
        if (x.thang == 12)
            return x.ngay + kq;
    }
}
ll dem_nam_nhuan(date x)
{
    return x.nam / 4 - x.nam / 100 + x.nam / 400;
}
ll ketqua(date x)
{
    ll kq = 0;
    x.nam--;
    ll n = dem_nam_nhuan(x);
    kq += (n) * 366;
    kq += (x.nam - n) * 365;
    kq += tong_ngay(x) - 1;
    return kq;
}
int main()
{
    date tg1;
    date tg2;
    nhap(tg1);
    nhap(tg2);
    if (!check(tg1))
    {
        cout << "-1";
        return 0;
    }
    if (!check(tg2))
    {
        cout << "-1";
        return 0;
    }
    ll kq1 = ketqua(tg1);
    ll kq2 = ketqua(tg2);
    if (kq1 > kq2)
    {
        cout << kq1 - kq2;
        return 0;
    }
    else
        cout << kq2 - kq1;
    return 0;
}