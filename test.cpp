#include<bits/stdc++.h>
#define ll long long
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;
const ll N=5e5+5,M=1e9+7,O=1e6;
ll n,m,a[N],res,f[N],b[N],p[O+10];
void sang()
{
    p[0]=1;
    p[1]=1;
    for (int i=2;i<=sqrt(O);i++)
    {
        if (p[i]==0)
        {
            for (int j=i*i;j<=O;j+=i)
            p[j]=1;
        }
    }
}
ll chat(int l,int r,int x)
{
    int h=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (a[b[mid]]<=x) h=mid,l=mid+1;
        else
            r=mid-1;
    }
    return b[h];
}
void nhap()
{
    cin>>n;
    sang();
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (p[x]==0) a[++m]=x;
    }
    f[1]=1; b[1]=1; int r=1;
    for (int i=2;i<=m;i++)
    {
        ll t=chat(1,f[r],a[i]);
        f[i]=f[t]+1;
        b[f[i]]=i;
        if (f[i]>f[r]) r=i;
    }
    cout<<f[r];
}
int main(){
  nhap();

}