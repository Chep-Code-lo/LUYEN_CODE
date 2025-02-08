#include <bits/stdc++.h>
#define int long long
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
using namespace std;

struct PhanSo {
    int tu, mau;

    // Hàm rút gọn phân số
    void rut_gon() {
        int gcd = __gcd(abs(tu), abs(mau));
        tu /= gcd;
        mau /= gcd;
        if (mau < 0) {
            tu *= -1;
            mau *= -1;
        }
    }

    // Hàm so sánh phân số (giống sosanh)
    int sosanh(const PhanSo &other) const {
        PhanSo a = *this, b = other;
        a.rut_gon();
        b.rut_gon();

        if (a.tu * b.mau > a.mau * b.tu) return 1;
        else if (a.tu * b.mau < a.mau * b.tu) return -1;
        else return 0;
    }

    // Hàm cộng phân số
    PhanSo operator+(const PhanSo &other) const {
        PhanSo sum = {tu * other.mau + other.tu * mau, mau * other.mau};
        sum.rut_gon();
        return sum;
    }

    // Hàm nhân phân số
    PhanSo operator*(const PhanSo &other) const {
        PhanSo product = {tu * other.tu, mau * other.mau};
        product.rut_gon();
        return product;
    }

    // Hàm đảo ngược phân số
    PhanSo rev() const {
        PhanSo rev = {mau, tu};
        rev.rut_gon();
        return rev;
    }

    // Kiểm tra phân số có phải số nguyên không
    bool isInteger() const {
        return (tu % mau == 0);
    }

    // Hàm in ra phân số
    void print() const {
        cout << tu << " " << mau << "\n";
    }
};

// Nhập danh sách phân số
void input(vector<PhanSo> &ds, int n) {
    for (int i = 0; i < n; ++i) {
        PhanSo ps;
        cin >> ps.tu >> ps.mau;
        ps.rut_gon();
        ds.push_back(ps);
    }
}

// Tìm phân số lớn nhất
PhanSo find_max(const vector<PhanSo> &ds) {
    PhanSo max_ps = ds[0]; // Giả sử phần tử đầu tiên là lớn nhất
    for (const auto &ps : ds) {
        if (ps.sosanh(max_ps) == 1) { // Nếu ps > max_ps thì cập nhật max_ps
            max_ps = ps;
        }
    }
    max_ps.rut_gon();
    return max_ps;
}

// Tính tổng danh sách phân số
PhanSo sum(const vector<PhanSo> &ds) {
    PhanSo sum = {0, 1};
    for (const auto &ps : ds) {
        sum = sum + ps;
    }
    sum.rut_gon();
    return sum;
}

// Tính tích danh sách phân số
PhanSo product(const vector<PhanSo> &ds) {
    PhanSo product = {1, 1};
    for (const auto &ps : ds) {
        product = product * ps;
    }
    product.rut_gon();
    return product;
}

// In ra các phân số đảo ngược
void print_rev(const vector<PhanSo> &ds) {
    for (size_t i = 0; i < ds.size(); i++) {
        PhanSo rev = ds[i].rev();
        cout << rev.tu << " " << rev.mau;
        if (i < ds.size() - 1) cout << " ";
    }
}


signed main() {
    file_chuan("TASK");
    int n;
    cin >> n;
    vector<PhanSo> ds;
    input(ds, n);

    find_max(ds).print();
    sum(ds).print();
    product(ds).print();
    print_rev(ds);

    return 0;
}
