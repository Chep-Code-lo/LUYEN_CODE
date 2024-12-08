#include<iostream>
using namespace std;
int n;
double sum;
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i)
        sum += 1/double((i*(i+1))/2);
    printf("%.6f", sum);
}