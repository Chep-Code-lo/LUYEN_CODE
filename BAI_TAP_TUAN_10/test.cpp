//MT1-Array1D-2022-11-21-Bai4
#include <iostream>
using namespace std;
int main()
{
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int vt = -1, count = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
            if (count > max)
            {
                max = count;
                vt = i;
            }
        }
    }
    cout << vt;
    return 0;
}
//MT1-Array1D-2022-11-21-Bai3
#include<iostream>
#include<math.h>
#include <climits>
using namespace std;
int main()
{
    int a[100], n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int vt, xet, min = INT_MAX;
    
    cout << vt;
    return 0;
}
//MT1-Array1D-2022-11-21-Bai2
#include <iostream>
using namespace std;
int main()
{
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = a[0], premax = -101;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    bool kt = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > premax && a[i] < max)
        {
            premax = a[i];
            kt = true;
        }
    }
    if (kt)
    {
        cout << premax;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
//MT1-Array1D-2022-11-21-Bai1
#include<iostream>
using namespace std;
int main()
{
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = a[0], vt1, vt2;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            vt1 = i;
            vt2 = i;
        }
        else if (a[i] == max)
        {
            vt2 = i;
        }
    }
    cout << vt2 - vt1 << endl;
    return 0;
}