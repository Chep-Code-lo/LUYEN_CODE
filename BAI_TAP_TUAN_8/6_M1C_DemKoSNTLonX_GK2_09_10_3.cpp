#include<iostream>
using namespace std;
bool is_prime(int unknown){
    if(unknown <= 1) return false;
    if(unknown <= 3) return true;
    if(unknown%2 == 0 || unknown%3 == 0) return false;
    for(int i=5; i*i<=unknown; i+=6)
        if(unknown%i == 0 || unknown%(i+2) == 0)    return false;
    return true;
}
int limit, unknown, count, arry[102];
int main(){
    cin >> limit >> unknown;
    for(int i=0; i<limit; ++i) cin >> arry[i], count = (is_prime(arry[i]) && arry[i] > unknown) ? ++count : count;
    cout << count;
    

}