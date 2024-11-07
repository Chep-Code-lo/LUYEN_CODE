//Thánh chép code lỏ
#include<bits/stdc++.h>
#define ll long long
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define N int(1e7)
#define M int(3e6+3)
#define X int(1e6)
#define MAX int(1e12)
using namespace std;
long long n, a[M], prime[N], Euler[X+1];

//  Sàng tổng các ước suy ra từ sàng snt độ phức tạp O(nlogn)
void Divisors_Sieve(){
    for(int i=1; i<=M; ++i) a[i] = 1;
    for(int i=2; i<=M/2; ++i)
        for(int j=2; j<=M/i; ++j)
            a[i*j] += i;
}

// Sàng snt độ phức tạp O(nlog logn)
void Eratosthenes_Sieve(){
    for(int i=1; i<=N; ++i) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i=2; i<=sqrt(N); ++i)
        if(prime[i])
            for(int j=i*i; j<=N; j+=i)
                prime[j] = 0;
}

// Sàng snt trên đoạn độ phức tạp O(nloglogn)
void Eratosthenes_Segment_Sieve(ll L, ll  R){
	int prime[R - L + 1];
	for(ll i = L; i <= R; i++){
		prime[i - L] = 1;
	}
	for(ll i = 2; i <= sqrt(R); i++){
		for(ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i){
			prime[j - L] = 0;
		}
	}
	for(ll i = max(2ll, L); i <= R; i++){
		if(prime[i - L]){
			cout << i << ' ';
		}
	}
}
// Phi hàm Euler dùng sàng độ phức tạp O(nlogn)
void Euler_Sieve(){
    for(int i=1; i<=X; i++) Euler[i] = i;
    for(int i=2; i<=X; i++)
        if(Euler[i] == i)
            for(int j = i; j <= X; j += i)
                Euler[j] -= Euler[j] / i;
}

// Kiểm tra snt dạng 6k -1 độ phức tạp O(√n/6)
bool Is_Prime(ll x){
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x%2 == 0 || x%3 == 0) return false;
    for(int i=5; i*i<=x; i+=6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}

// Kiểm tra snt dạng thường độ phức tạp O(√n)
bool is_prime(ll x){
    for(int i=2; i<=sqrt(x); i++)
        if(x%i == 0) return false;
    return x > 1;
}

// Phi hàm Euler tìm số lượng số nguyên tố cùng nhau vs n và nhỏ hơn n
// Độ phức tạp O(√n)
ll Eulerr(ll n){
    ll res = n;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0){
            res = res - res / i; // res = res * (1 - 1 / i)
            while(n % i == 0){
                n /= i;
            }
        }
    if(n > 1)   res -= res / n;
    return res;
}

// Đếm số ước độ phức tạp O(√n)
ll Count_Divisors(ll x){
    ll cnt = 0;
    for(int i=1; i*i<=x; i++)
        if(x%i == 0){
            cnt++;
            if(i != n/i) cnt++; // Tránh đếm trùng khi i*i = x
        }
    return cnt;
}

// Tổng ước ko cộng chính nó độ phức tạp O(√n)
ll Sum_Divisors(ll x){
    ll sum = 1;
    for(ll i=2; i*i<=x; i++)
        if(x%i == 0){
            if(i*i != x) sum += i + x/i;
            else sum += i;// Tránh cộng 2 lần khi i*i = x
        }
    return sum;
}

// Kiểm tra số chính phương độ phức tạp O(1)
bool Square_Number(ll x){
    int res = sqrt(x);
    return(1ll*res*res == x);
}

//Kiểm tra số đối xứng độ phức tạp O(1)
bool Symmetry_Number(ll x){
    ll reverse = 0, temp = x;
    while(x){
        reverse = reverse*10 + x%10;
        x /= 10;
    }
    return reverse == temp;
}

// Lũy thừa nhị phân độ phức tạp O(logb)
// Dùng tính chất lũy thừa chia nhỏ phép nhân 
// b chẵn thì a^b = (a^(b/2))^2
// b lẻ thì a^b = a * a^(b-1)
ll Bin_Pow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1)// kiểm tra bit cuối bằng 1 không (tức b lẻ)
            res *= a;
        a*=a;
        b >>= 1;// Dịch b một bit sang phải (tức chia b cho 2)
    }
    return res;
}

// Lũy thừa nhị phân chia dư cho số theo yêu cầu đề độ phức tạp O(logb)
ll Bin_Pow_Mod(ll a, ll b, ll mod){
    a %= mod;
    ll res = 1;
    while(b > 0){
        if(b & 1)
            res = res*a % mod;
         a = a*a % mod;
         b >>= 1;
    }
    return res;
}

// Phân tích thừa số nguyên tố độ phức tạp O(√n)
vector<int> Analysis_Prime(ll x){
    ll cnt = 0;
    vector<int>v;
    while(x%2 == 0){
        cnt++;
        x /= 2;
    }
    if(cnt != 0){
        v.push_back(cnt);
        cnt = 0;
    }
    for(int i=3; i<=sqrt(x); i++){
        while(x%i == 0){
            cnt++;
            x /= i;
        }
        if(cnt != 0){
            v.push_back(cnt);
            cnt = 0;
        }
    }
    if(x > 1) v.push_back(1);
    return v;
}

int main(){
}
