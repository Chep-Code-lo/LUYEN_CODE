#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long count_good_segments(int n, int k, const vector<int>& a) {
    unordered_map<int, int> freq; // Đếm số lượng xuất hiện của mỗi giá trị
    int distinct_count = 0; // Số lượng giá trị riêng biệt
    long long count = 0; // Tổng số lượng phân đoạn tốt
    int l = 0; // Con trỏ trái

    for (int r = 0; r < n; ++r) {
        // Thêm a[r] vào phân đoạn
        if (freq[a[r]] == 0) {
            distinct_count++;
        }
        freq[a[r]]++;

        // Nếu số lượng giá trị riêng biệt vượt quá k, thu hẹp từ bên trái
        while (distinct_count > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) {
                distinct_count--;
            }
            l++;
        }

        // Tính số lượng phân đoạn tốt từ l đến r
        count += (r - l + 1);
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long result = count_good_segments(n, k, a);
    cout << result << endl;

    return 0;
}