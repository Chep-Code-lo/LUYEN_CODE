// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include<bits/stdc++.h>
using namespace std;
const int base = 1e9;
const int base_digits = 9;
struct bigint{
    vector<int>a;
    int sign;
    bigint(): sign(1){ }
    bigint(long long v) { *this = v; }
    bigint(const string &s) { read(s); }
    void operator=(const bigint &v) { sign = v.sign; a = v.a; }
    bigint operator/(const bigint &v) const{return divmod(*this, v).first;}
    bigint operator%(const bigint &v) const{return divmod(*this, v).second;}
    bigint operator/(int v) const{bigint res = *this; res /=v; return res;}
    void operator*=(const bigint &v) {*this = *this*v;}
    void operator+=(const bigint &v) {*this = *this+v;}
    void operator-=(const bigint &v) {*this = *this-v;}
    void operator/=(const bigint &v) {*this = *this/v;}
    bool operator>(const bigint &v) const{return v<*this;}
    bool operator<=(const bigint &v) const{return !(v<*this);}
    bool operator>=(const bigint &v) const{return !(*this<v);}
    bool operator==(const bigint &v) const{return !(*this<v) && !(v<*this);}
    bool operator!=(const bigint &v) const{return *this<v || v<*this;}
    bool operator<(const bigint &v) const{
        if(sign != v.sign)  return sign<v.sign;
        if(a.size() != v.a.size())  return a.size()*sign < v.a.size()*v.sign;
        for(int i=a.size()-1; i>+0; --i)
            if(a[i] != v.a[i])  return a[i]*sign < v.a[i]*sign;
        return false;
    }
    bool isZero() const{return a.empty() || (a.size() == 1 && !a[0]);}
    void trim(){
        while(!a.empty() && !a.back())  a.pop_back();
        if(a.empty())   sign=1;
    }
    bigint abs() const{
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }
    void operator=(long long v){
        sign = 1;
        if(v < 0)   sign = -1, v = -v;
        for(; v>0; v=v/base)    a.push_back(v%base);
    }
    bigint operator+(const bigint &v) const{
        if(sign == v.sign){
            bigint res = v;
            for(int i=0, carry=0; i<(int)max(a.size(), v.a.size()) || carry; ++i){
                if(i == (int) res.a.size()) res.a.push_back(0);
                res.a[i] += carry + (i<(int)a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if(carry)   res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }
    bigint operator-(const bigint &v) const{
        if(sign == v.sign){
            if(abs() >= v.abs()){
                bigint res = *this;
                for(int i=0, carry=0; i<(int)v.a.size() || carry; ++i){
                    res.a[i] -= carry + (i<(int)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if(carry)   res.a[i] += base;   
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
    bigint operator-() const{
        bigint res = *this;
        res.sign = -sign;
        return res;
    }
     int operator%(int v) const{
        if(v<0) v = -v;
        int m=0;
        for(int i=a.size()-1; i>=0; --i)    m = (a[i] + m*(long long)base)%v;
        return m*sign;
    }
    void operator/=(int v){
        if(v<0) sign=-sign, v=-v;
        for(int i=(int)a.size()-1, rem=0; i>=0; --i){
            long long cur = a[i] + rem*(long long)base;
            a[i] = (int)(cur/v), rem = (int)(cur%v);
        }
        trim();
    }
    bigint operator*(const bigint &v) const{
        bigint res;
        res.sign = sign * v.sign;
        res.a.resize(a.size() + v.a.size());
        for(int i=0; i<(int)a.size(); ++i){
            long long carry = 0;
            for(int j=0; j<(int)v.a.size() || carry; ++j){
                long long cur = res.a[i + j] + (long long)a[i] * (j<(int)v.a.size() ? v.a[j] : 0) + carry;
                res.a[i + j] = cur % base;
                carry = cur / base;
            }
        }
        res.trim();
        return res;
    }
    friend pair<bigint, bigint>divmod(const bigint &a1, const bigint &b1){
        int norm = base/(b1.a.back() + 1);
        bigint q, r, a=a1.abs()*norm, b=b1.abs()*norm;
        q.a.resize(a.a.size());
        for(int i=a.a.size()-1; i>=0; i--){
            r *= base, r+= a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long)base*s1+s2) / b.a.back();
            r -= b*d;
            while(r < 0)    r+=b, --d;
            q.a[i] = d;
        }
        q.sign = a1.sign*b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r/norm);
    }
    //Chuyển bigint sang long long
    long long longValue() const{
        long long res=0;
        for(int i=a.size()-1; i>=0; i--)    res = res*base + a[i];
        return res*sign;
    }
    friend bigint gcd(const bigint &a, const bigint &b){return b.isZero() ? a : gcd(b, a%b);}
    friend bigint lcm(const bigint &a, const bigint &b){return a/gcd(a, b)*b;}
    void read(const string &s){
        sign=1;
        a.clear();
        int pos=0;
        while(pos<(int)s.size() && (s[pos] == '-' || s[pos] == '+')){
            if(s[pos] == '-')   sign = -sign;
            ++pos;
        }
        for(int i=s.size()-1; i>=pos; i-=base_digits){
            int x=0;
            for(int j=max(pos, i-base_digits+1); j<=i; j++) x=x*10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
    friend istream& operator>>(istream &stream, bigint &v){
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
    friend ostream& operator<<(ostream &stream, const bigint &v){
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for(int i=(int)v.a.size()-2; i>=0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }
};
bigint n;
int main(){
    cin >> n;
    cout << (n*(n+1)*(n+1)*(n+2))/12;
}