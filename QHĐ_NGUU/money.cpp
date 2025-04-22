#include<bits/stdc++.h>
#define nmax 205
#define Smax 10005
using namespace std;
long long N,S,A[nmax],F[Smax];
void nhap()
{
    long i;
    cin>>N>>S;
    for(i=1;i<=N;i++) cin>>A[i];
}
void QHD()
{
    int i,j;
    for(i=1;i<=N;i++)
        for(j=S;j>=A[i];j--)
    {
        F[j]+=F[j-A[i]];
        if(j==A[i]) F[j]+=1;
    }
}
int main()
{
    long i;
    freopen("Money.INP","r",stdin);
    freopen("Money.OUT","w",stdout);
    for(i=0;i<=S;i++) F[i]=0;
    nhap();
    QHD();
    cout<<F[S];
}
