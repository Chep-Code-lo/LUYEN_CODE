#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define file(name) freopen(name".inp","r",stdin); freopen(name".txt","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e6;
int n, ans = 1, prime[M+1];
vector<int>dp(M, 1e6);
vector<int>add;
void Eratosthenes_Sieve(){
    for(int i=1; i<=M; ++i) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i=2; i<=sqrt(M); ++i)
        if(prime[i])
            for(int j=i*i; j<=M; j+=i)
                prime[j] = 0;
}
void input(){
    Eratosthenes_Sieve();
    cin >> n;
    for(int x, i=0; i<n; ++i){
        cin >> x;
        if(prime[x]) add.push_back(x);
    }
    for(auto x : add)   cout << x << " ";
}
int main(){
    file("TASK");
    input();
    
}