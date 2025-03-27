#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int w;
    int t;
    double ratio;
};

bool compareJobs(const Job &a, const Job &b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].w >> jobs[i].t;
        jobs[i].ratio = (double)jobs[i].w / jobs[i].t;
    }
    sort(jobs.begin(), jobs.end(), compareJobs);
    int total_weighted_time = 0;
    int current_time = 0;
    for (const auto &job : jobs) {
        current_time += job.t;
        total_weighted_time += job.w * current_time;
    }
    cout << total_weighted_time << endl;
    return 0;
}