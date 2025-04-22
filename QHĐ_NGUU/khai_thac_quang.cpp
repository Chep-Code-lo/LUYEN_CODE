// Program ORE

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

#define MAXN 505

using namespace std;

int m,n,a[MAXN][MAXN],b[MAXN][MAXN],f[MAXN][MAXN][2];

void doc() {
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) scanf("%d",&b[i][j]);
}

void solve() {
    for(int j=1;j<=n;j++)
        for(int i=1;i<=m;i++) a[i][j]+=a[i][j-1];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) b[i][j]+=b[i-1][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) {
            f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1])+a[i][j];
            f[i][j][1]=max(f[i][j-1][0],f[i][j-1][1])+b[i][j];
        }
    int ds=max(f[m][n][0],f[m][n][1]);
    printf("%d\n",ds);
}

int main() {
    freopen("ore.inp","r",stdin);
    freopen("ore.out","w",stdout);
    scanf("%d%d",&m,&n);
    if (m && n) {
        doc();
        solve();
    }
}
