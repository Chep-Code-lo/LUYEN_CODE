#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;

/* Ý tưởng: 
   - j[i] < f[i]: Ưu tiên công việc có j[i] nhỏ hơn f[i] để giảm thời gian chờ của PC.
   - j[i] >= f[i]: Đưa công việc này về sau để tránh trì hoãn các công việc có f[i] lớn hơn.
   - Vì tất cả PC làm việc song song nên thời gian hoàn thành cuối cùng chính là thời gian kết thúc công việc trễ nhất
*/
int n;
void timeElapsed(){
    cerr << "Time elapsed: " << TIME << "s.\n";
}
class Job{
public:
    int j, f;
    Job(int x, int y) : j(x), f(y) {}
    static bool cmp(const Job &a, const Job &b){
        if((a.j < a.f) != (b.j < b.f)) return a.j < a.f;
        return (a.j < a.f) ? (a.j < b.j) : (a.f > b.f);
    }
};
vector<Job> jobs;
void input(){
    cin >> n;
    jobs.reserve(n);
    for(int i = 0; i < n; ++i){
        int j, f;
        cin >> j >> f;
        jobs.emplace_back(j, f);
    }
    sort(jobs.begin(), jobs.end(), Job::cmp);
}
void solve(){
    faster;
    input();
    int current_time = 0, max_time = 0;
    for(const auto &job : jobs){
        current_time += job.j;
        max_time = max(max_time, current_time + job.f);
    }
    cout << max_time << "\n";
}
signed main(){
    solve();
    timeElapsed();
    return 0;
}