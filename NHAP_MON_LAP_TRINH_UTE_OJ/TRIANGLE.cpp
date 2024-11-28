#include<iostream>
#include<algorithm>
using namespace std;
int a, b, c, cnt;
int main(){
    cin >> a >> b >> c;
    int arr[3] = {a, b, c};
    sort(arr, arr+3);
    cout << ((arr[0]+arr[1] > arr[2]) ? 0 : (arr[2] - (arr[0]+arr[1]) + 1));
}