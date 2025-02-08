#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
struct PhanSo{
    int tu, mau;
    void rut_gon(){
        int gcd = __gcd(tu, mau);
        tu /= gcd;
        mau /= gcd;
        if(mau < 0){
            tu = -tu;
            mau = -mau;
        }
    }
    PhanSo rev() const{
        int mau_temp = tu;
        int tu_temp = mau;
        if(mau_temp < 0){
            mau_temp = -mau_temp;
            tu_temp = -tu_temp;
        }
        return {tu_temp, mau_temp};
    }
    bool operator>(const PhanSo &other) const{
        return tu * other.mau > mau * other.tu;
    }
    PhanSo operator+(const PhanSo &other) const{
        int newTu = tu * other.mau + other.tu * mau;
        int newMau = mau * other.mau;
        PhanSo result = {newTu, newMau};
        result.rut_gon();
        return result;
    }
    PhanSo operator*(const PhanSo &other) const{
        int newTu = tu * other.tu;
        int newMau = mau * other.mau;
        PhanSo result = {newTu, newMau};
        result.rut_gon();
        return result;
    }
    void print() const{
        cout << tu << " " << mau << "\n";
    }
};
void in(PhanSo &ps){
    cin >> ps.tu >> ps.mau;
    ps.rut_gon();
}
void input(vector<PhanSo> &ds, int n){
    for(int i = 0; i < n; ++i){
        PhanSo ps;
        in(ps);
        ds.push_back(ps);
    }
}
PhanSo find_max(const vector<PhanSo> &ds){
    return *max_element(ds.begin(), ds.end(), 
        [](const PhanSo &a, const PhanSo &b)
            {return !(a > b);} 
    );
}
PhanSo sum(const vector<PhanSo> &ds){
    PhanSo sum = {0, 1};
    for(const auto &ps : ds)
        sum = sum + ps;
    return sum;
}
PhanSo product(const vector<PhanSo> &ds){
    PhanSo product = {1, 1};
    for(const auto &ps : ds)
        product = product * ps;
    return product;
}
void print_rev(const vector<PhanSo> &ds){
    for(int i = 0; i < ds.size(); ++i){
        PhanSo rev = ds[i].rev();  
        cout << rev.tu << " " << rev.mau;
        if (i < ds.size() - 1) cout << " ";
    }
}
signed main(){
    int n;  cin >> n;
    vector<PhanSo> ds;
    input(ds, n);
    find_max(ds).print();
    sum(ds).print();
    product(ds).print();
    print_rev(ds);
}

/*18 
-4 -7 
6 6 
-3 5 
4 -10 
-7 -9 
4 7 
-6 -5 
6 -1 
-6 10 
1 -6 
-8 -2
1 -7 
3 1 
-4 5 
2 6 
-4 9 
10 -3 
-6 7*/