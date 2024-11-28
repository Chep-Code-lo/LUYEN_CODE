#include<iostream>
#include<math.h>
using namespace std;
double x;
int y;
int main(){
    cin >> x;
    y = ceil(abs(int(x)));
    if(y%2 == 0)
        y += 1;
    cout << y;
}