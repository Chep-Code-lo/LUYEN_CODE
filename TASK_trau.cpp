#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct PHANSO
{
    long long t, m;
};

long long gcd(long long a, long long b)
{

    a = abs(a);
    b = abs(b);
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void Nhap(PHANSO a[1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].t >> a[i].m;
    }
}

void Xuat(PHANSO a[1000], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << a[i].t << " " << a[i].m;
    }
}

void toigian(PHANSO &x)
{
    int boi = gcd(x.t, x.m);

    if (x.m < 0)
    {
        x.m *= -1;
        x.t *= -1;
    }

    x.t = x.t / boi;
    x.m = x.m / boi;
}

int sosanh(PHANSO a, PHANSO b)
{
    toigian(a);
    toigian(b);

    if (a.t * b.m > a.m * b.t)
        return 1;

    else if (a.t * b.m < a.m * b.t)
        return -1;

    else
        return 0;
}

PHANSO tong(PHANSO a, PHANSO b)
{
    PHANSO sum;
    sum.t = a.t * b.m + a.m * b.t;
    sum.m = a.m * b.m;
    toigian(sum);
    return sum;
}

PHANSO maxps(PHANSO a[1000], int n)
{

    PHANSO max = a[0];
    for (int i = 1; i < n; i++)
    {

        if (sosanh(a[i], max) == 1)
            max = a[i];
    }

    toigian(max);

    return max;
}

PHANSO tich(PHANSO a, PHANSO b)
{

    a.t = a.t * b.t;

    a.m = a.m * b.m;

    toigian(a);

    return a;
}

bool check(PHANSO x)
{

    if (x.t % x.m == 0)
        return true;

    return false;
}

void latNguoc(PHANSO &x)
{

    int cnt = x.t;

    x.t = x.m;

    x.m = cnt;

    toigian(x);
}

int main()
{
    file_trau("TASK");
    PHANSO a[1000];

    int n;
    cin >> n;

    Nhap(a, n);

    cout << maxps(a, n).t << " " << maxps(a, n).m << endl;

    PHANSO sum = a[0];

    for (int i = 1; i < n; i++)
    {

        sum = tong(sum, a[i]);
    }

    toigian(sum);

    cout << sum.t << " " << sum.m << endl;

    PHANSO th = a[0];

    for (int i = 1; i < n; i++)
    {

        th = tich(th, a[i]);
    }

    toigian(th);

    cout << th.t << " " << th.m << endl;

    for (int i = 0; i < n; i++)
    {

        latNguoc(a[i]);

        cout << a[i].t << " " << a[i].m;

        if (i < n - 1)
            cout << " ";
    }

    return 0;
}