#include<iostream>
using namespace std;
int dir[8][2] = {{1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}};
int x1, y, x2, y2;
void input(){
    cin >> x1 >> y >> x2 >> y2;
}
void solve_find(){
    for(int i=0; i<8; ++i){
        int nx = x1 + dir[i][1];
        int ny = y + dir[i][0];
        if(nx >= 0 && nx < 8 && ny >= 0 & ny < 8 && nx == x2 && ny == y2){
            cout << i+1;
            return;
        }
    }
    cout << 0;
}
int main(){
    input();
    solve_find();
}