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
    long n=180,i;
    freopen("MONEY.INP","w",stdout);
    cout<<n<<" "<<8000<<"\n";
    for(i=1;i<=n;i++) cout<<500+rand()%200<<" ";
}
int main()
{
  GenTest();
  return 0;
}
