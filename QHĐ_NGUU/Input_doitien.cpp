// Chuong trinh Tao cac file Input cua Ban giam khao
//Hàm srand(time(0) sinh số ngẫu nhiên theo thời gian.
//Hàm rand() sinh số ngãu nhiên trong [0,Nmax]
//Hàm rand()%N sinh số ngẫu nhiên trong phạm vi [0,N-1]
//Hàm a + rand() % (b – a + 1) sinh số ngẫu nhiên trong [a,b]
#include<bits/stdc++.h>
using namespace std;
void GenTest()
{
    srand(time(0));
    long n=100,i,M=10000;
    freopen("DOITIEN.INP","w",stdout);
    cout<<n<<" "<<M<<'\n';
    for (i=1;i<=n;i++) cout<<i+10<<" ";
}
int main()
{
  GenTest();
  return 0;
}
