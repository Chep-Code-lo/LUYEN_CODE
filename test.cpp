#include<iostream>
using namespace std;
long long a, b;
int main(){
    cin >> a >> b;
    while(a!=0 && b!=0){
        if((a%10 + b%10) > 9 ){
            cout << "Hard";
            return 0;
        }        
        a/=10;
        b/=10;
    }
    cout << "Easy";
}