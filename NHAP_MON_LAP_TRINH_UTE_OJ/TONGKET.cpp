#include<iostream>
#include<math.h>
using namespace std;
int k;
double x, y;
int main(){
    cin >> k;
    cin >> x >> y;
    double res = (x+y)/2;
    res = round(res*10) / 10.0;
    if(k == 21){
        if(res >= 4)
            cout << "Pass";
        else    cout << "Fail";
    }
    if(k < 21){
        if(res >= 5)
            cout << "Pass";
        else    cout << "Fail";
    }
}