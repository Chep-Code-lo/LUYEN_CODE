#include<iostream>
#include<math.h>
#define file(name)  freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool is_prime(long long unknown){
    if(unknown <= 1) return false;
    if(unknown <= 3) return true;
    if(unknown%2 == 0 || unknown%3 == 0) return false;
    for(long long i=5; i*i<=unknown; i+=6)
        if(unknown%i == 0 || unknown%(i+2) == 0) return false;
    return true;
}

long long count_divisors(long long unknown){
    long long count = 0;
    for(long long i=1; i*i<=unknown; ++i)
        if(unknown%i == 0){
            count++;
            if(i != unknown/i) count++;
        }
    return count;
}

long long sum_divisors(long long unknown){
    long long sum = 1;
    for(long long i=2; i*i<=unknown; ++i)
        if(unknown%i == 0){
            if(i*i != unknown) sum += i + unknown/i;
            else sum += i;
        }
    return sum + unknown;
}

long long bin_pow(long long x, long long y){
    long long res = 1;
    while(y > 0){
        if(y&1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

long long bin_pow_mod(long long x, long long y, long long mod){
    x %= mod;
    long long res = 1;
    while(y > 0){
        if(y&1) res = res*x % mod;
        x = x*x %mod;
        y >>= 1;
    }
    return res;
}
int main(){
}