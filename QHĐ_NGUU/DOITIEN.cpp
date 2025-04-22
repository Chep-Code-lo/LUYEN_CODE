#include<bits/stdc++.h>;
using namespace std;
const int nmax=201,mmax=100001;
int n,a[nmax],d[mmax],c[mmax];
long long m;
int kt[nmax];
int dem[1000001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("doitien.inp","r",stdin);
    freopen("doitien.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    d[0]=0;
    for (int i=1;i<=m;i++) {d[i]=INT_MAX;c[i]=0;}
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        if (i>=a[j]&&d[i]>d[i-a[j]]+1&&d[i-a[j]]!=INT_MAX)
        {
            d[i]=d[i-a[j]]+1;
            c[i]=a[j];
        }
    if (d[m]==INT_MAX) cout<<0;
    else
    {
        cout<<d[m]<<endl;
        long long k=m;
        while (k>0)
        {
            dem[c[k]]++;
            k=k-c[k];
        }
        for (int i=1;i<=n;i++) kt[a[i]]=1;
        for (int i=1;i<=n;i++) if (dem[a[i]]!=0&&kt[a[i]]==1)
        {
            cout<<a[i]<<" "<<dem[a[i]]<<'\n';
            kt[a[i]]=0;
        }
    }
    return 0;
}

