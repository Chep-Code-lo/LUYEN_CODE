// Cre: ChatGPT
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int R, C, ZR, ZC;
    cin >> R >> C >> ZR >> ZC;
    vector<string> paper(R);
    for (int i = 0; i < R; ++i) cin >> paper[i];
    vector<string> enlarged(R * ZR);
    for (int i = 0; i < R; ++i) 
        for (int j = 0; j < C; ++j) {
            char c = paper[i][j];
            for (int k = 0; k < ZR; ++k)
                enlarged[i * ZR + k] += string(ZC, c);
        }
    for (int i = 0; i < R * ZR; ++i)
        cout << enlarged[i] << "\n";
}