// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include <bits/stdc++.h>
#define big_int vector<int>
using namespace std;
const int BASE = 1000;
const int LENGTH = 3;
big_int& fix(big_int &a){
  a.push_back(0);
  for (int i = 0; i + 1 < a.size(); ++i){
    a[i + 1] += a[i] / BASE; a[i] %= BASE;
    if (a[i] < 0) a[i] += BASE, --a[i + 1];
  }
  while (a.size() > 1 && a.back() == 0) a.pop_back();
  return a;
}
big_int big(int x){
  big_int result;
  while (x > 0) {
    result.push_back(x % BASE);
    x /= BASE;
  }
  return result;
}
big_int big(string s){
  big_int result(s.size() / LENGTH + 1);
  for (int i = 0; i < s.size(); ++i) {
    int pos = (s.size() - i - 1) / LENGTH;
    result[pos] = result[pos] * 10 + s[i] - '0';
  }
  return fix(result), result;
}
int compare(big_int &a, big_int &b){
  if (a.size() != b.size()) return (int)a.size() - (int)b.size();
  for (int i = 0; i < a.size(); ++i)
    if (a[i] != b[i]) return a[i] - b[i];
  return 0;
}
#define DEFINE_OPERATOR(x) bool operator x (big_int &a, big_int &b) { return compare(a, b) x 0; }
DEFINE_OPERATOR(==)
DEFINE_OPERATOR(!=)
DEFINE_OPERATOR(>)
DEFINE_OPERATOR(<)
DEFINE_OPERATOR(>=)
DEFINE_OPERATOR(<=)
#undef DEFINE_OPERATOR
void operator += (big_int &a, big_int b){
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < b.size(); ++i)
    a[i] += b[i];
  fix(a);
}
void operator -= (big_int &a, big_int b){
  for (int i = 0; i < b.size(); ++i)
    a[i] -= b[i];
  fix(a);
}
void operator *= (big_int &a, int b){
  for (int i = 0; i < a.size(); ++i)
    a[i] *= b;
  fix(a);
}
void divide(big_int a, int b, big_int &q, int &r){
  for (int i = int(a.size()) - 1; i >= 0; --i) {
    r = r * BASE + a[i];
    q.push_back(r / b); r %= b;
  }
  reverse(q.begin(), q.end());
  fix(q);
}
big_int operator + (big_int a, big_int b) { a += b; return a; }
big_int operator - (big_int a, big_int b) { a -= b; return a; }
big_int operator * (big_int a, int b) { a *= b; return a; }
big_int operator / (big_int a, int b){
  big_int q; int r = 0;
  divide(a, b, q, r);
  return q;
}
int operator % (big_int a, long b){
  big_int q; int r = 0;
  divide(a, b, q, r);
  return r;
}
big_int operator * (big_int a, big_int b){
  big_int result (a.size() + b.size());
  for (int i = 0; i < a.size(); ++i)
    for (int j = 0; j < b.size(); ++j)
      result[i + j] += a[i] * b[j];
  return fix(result);
}
istream& operator >> (istream& cin, big_int &a){
  string s; cin >> s;
  a = big(s);
  return cin;
}
ostream& operator << (ostream& cout, const big_int &a){
  cout << a.back();
  for (int i = (int)a.size() - 2; i >= 0; --i)
    cout << setw(LENGTH) << setfill('0') << a[i];
  return cout;
}
big_int factorial(int n, int k){
    big_int ans = big("1");
    //big_int res = big("1");
    for(int i=0; i<k; ++i){
        ans = ans * (n-i);
        ans = ans / (i+1);
    }
    return ans;

}
int n, k;
int main(){
    //file_chuan("TASK")
    cin >> n >> k;
    cout<<factorial(n, k);
    return 0;
    
}