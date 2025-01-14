//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool isPossible(int a, int b, int c){
    return (a + b == c || a - b == c || b - a == c || a * b == c || 
            (b != 0 && a / b == c && a % b == 0) || 
            (a != 0 && b / a == c && b % a == 0));
}
int q;
int main(){
    faster
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(isPossible(a, b, c)) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}
/*6
1 2 3
2 24 12
5 3 1
9 16 7
7 2 14
12 4 2
*/