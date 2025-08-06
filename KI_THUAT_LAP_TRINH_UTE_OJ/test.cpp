#include <bits/stdc++.h>
using namespace std;
vector<int>s, in(9, 0);
int cnt, total;
int main() {
    for(int i = 21; i <= 29; ++i) s.push_back(i);
    fill(in.begin(), in.begin() + 6, 1);
    do{
        vector<int> comb;
        for(int i = 0; i < 9; ++i)
            if (in[i]) comb.push_back(s[i]);
        sort(comb.begin(), comb.end());
        do{
            int A = comb[0], B = comb[1], 
            C = comb[2], M = comb[3], 
            N = comb[4],P = comb[5];
            bool ok1 = (M - A == B - M);
            bool ok2 = (N - B == C - N);
            bool ok3 = (P - C == A - P);
            if(ok1 && ok2 && ok3)
                cnt++;
            total++;
        }while(next_permutation(comb.begin(), comb.end()));
    }while(prev_permutation(in.begin(), in.end()));
    cout << "2 / a = " << 2 * total / cnt;
}