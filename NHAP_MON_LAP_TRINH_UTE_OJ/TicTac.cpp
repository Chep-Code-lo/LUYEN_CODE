// Author : Chép Code Lỏ
// Codeforces : @phamanh24042006
// Github : @Chep-Code-lo

#include <iostream>
#include <vector>
#include <string>
using namespace std;
char check_winner(const vector<string>& board, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            char c = board[i][j];
            if (c == '.') continue;
            if (j + 2 < n && c == board[i][j + 1] && c == board[i][j + 2]) return c;
            if (i + 2 < n && c == board[i + 1][j] && c == board[i + 2][j]) return c;
            if (i + 2 < n && j + 2 < n && c == board[i + 1][j + 1] && c == board[i + 2][j + 2]) return c;
            if (i + 2 < n && j - 2 >= 0 && c == board[i + 1][j - 1] && c == board[i + 2][j - 2]) return c;
        }
    }
    return '.';
}
int n;
int main(){
    cin >> n;
    vector<string> board(n);
    for(int i=0; i<n; ++i) cin >> board[i];
    char winner = check_winner(board, n);
    if(winner != '.') cout << winner;
    else cout << "ongoing";
}
/*3 
XOC
XOC
X*/