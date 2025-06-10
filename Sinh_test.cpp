#include <bits/stdc++.h>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;

const string NAME = "TASK";
const int MAX_WA = 50;     // Số lượng test WA cần thu thập
const int TEST_LIMIT = 10000; // Giới hạn tối đa số test chạy
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

bool check_file(const string& p1, const string& p2) {
    ifstream f1(p1, ifstream::binary | ifstream::ate);
    ifstream f2(p2, ifstream::binary | ifstream::ate);
    if (f1.fail() || f2.fail()) return false;
    if (f1.tellg() != f2.tellg()) return false;
    f1.seekg(0, ifstream::beg);
    f2.seekg(0, ifstream::beg);
    return equal(istreambuf_iterator<char>(f1.rdbuf()),
                 istreambuf_iterator<char>(),
                 istreambuf_iterator<char>(f2.rdbuf()));
}

int main() {
    srand(time(NULL));
    int wa_count = 25;

    for (int test = 1; test <= TEST_LIMIT; ++test) {
        ofstream inp((NAME + ".inp").c_str());

        // === SINH TEST ===
        int n = Rand(1, 1000);
        inp << n << "\n";
        for (int i = 0; i < n; ++i) {
            long long x = Rand(1, 100000);
            inp << x << " ";
        }
        inp << "\n";
        inp.close();

        // === CHẠY CHƯƠNG TRÌNH ===
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        // === SO SÁNH OUTPUT ===
        if (!check_file("TASK.out", "TASK.ans")) {
            cout << "Test " << test << ": ❌ WA\n";

            // Lưu input test bị sai
            stringstream ss;
            ss << "test" << setw(3) << setfill('0') << (++wa_count) << ".inp";
            ifstream source("TASK.inp");
            ofstream fail(ss.str());
            fail << source.rdbuf();
            source.close();
            fail.close();

            // Nếu đủ 10 test WA → dừng lại
            if (wa_count == MAX_WA) {
                cout << "\n==> Đã thu được đủ " << MAX_WA << " test WA. Kết thúc.\n";
                break;
            }
        } else {
            cout << "Test " << test << ": ✅ AC\n";
        }
    }

    cout << "\n==> Tổng số test WA thu được: " << wa_count << "\n";
    return 0;
}
