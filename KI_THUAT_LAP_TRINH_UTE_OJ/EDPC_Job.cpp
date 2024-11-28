#include<bits/stdc++.h>
#define ll long long
#define N 5005
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FOD(i,r,l) for(int i = r ; i >= l ; i--)
#define faster cin.tie(0)->sync_with_stdio(0);
using namespace std;
struct Data{
    int st, end , p;
};
bool cmp(const Data& a , const Data& b)
{
    return a.end < b.end;
}
Data a[N];
int t , n , s[N];
ll f[N];
int main()
{
    faster
        cin >> n ;
        FOR(i,1,n) 
            cin >> a[i].st >> a[i].end >> a[i].p;
        sort(a + 1,a + n + 1,cmp);
        FOR(i,1,n) s[i] = a[i].end; // Lưu time kết thúc
        //FOR(i,1,n) cout << a[i].st << " "<< a[i].end << " "<< a[i].p << "\n";
        FOR(i,1,n)
        {
            int p = upper_bound(s , s + n , a[i].st) - s  - 1;
            //cout << p << "\n";
            f[i] = max(f[p] + a[i].p , f[i-1]);
            //cout << f[i] << "\n";
        }
        cout << f[n] << "\n";
}
 

/*3
3 5 5
4 9 9
5 8 5*/