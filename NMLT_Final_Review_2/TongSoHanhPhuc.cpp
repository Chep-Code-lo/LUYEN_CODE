//Cre: Chat GPT
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int sumOfSquares(int num){
    int sum = 0;
    while(num > 0){
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}
bool isHappyNumber(int num){
    unordered_set<int> seenNumbers;
    while(num != 1 && seenNumbers.find(num) == seenNumbers.end()) {
        seenNumbers.insert(num);
        num = sumOfSquares(num);
    }
    return num == 1;
}
int n, sum;
int main(){
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for(int i=0; i<n; ++i) 
        if(isHappyNumber(a[i])) 
            sum += a[i];
    cout << sum;
}
