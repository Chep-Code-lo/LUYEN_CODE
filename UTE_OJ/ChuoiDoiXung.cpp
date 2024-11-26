#include <iostream>
#include <string>

using namespace std;
int oddLength[1000005], evenLength[1000005];
string solve(string& s, int n)
{
    for (int i = 0, left = 0, right = -1; i < n; i++) {
        int length = (i > right) ? 1 : min(oddLength[left + right - i],right - i + 1);
        while (0 <= i - length && i + length < n && s[i - length] == s[i + length]) {
            length++;
        }
        oddLength[i] = length--;
            left = i - length;
            right = i + length;
        }
    for(int i = 0, left = 0, right = -1; i < n; i++) {
        int length = (i > right) ? 0: min(evenLength[left + right - i + 1], right - i + 1);
        while (0 <= i - length - 1 && i + length < n
               && s[i - length - 1] == s[i + length]) {
            length++;
        }
        evenLength[i] = length--;
        if (i + length > right) {
            left = i - length - 1;
            right = i + length;
        }
    }
    int maxLength = 0, center = -1;
    for (int i = 0; i < n; i++){
        if (oddLength[i] * 2 - 1 > maxLength) {
            maxLength = oddLength[i] * 2 - 1;
            center = i;
        }
        if (evenLength[i] * 2 > maxLength) {
            maxLength = evenLength[i] * 2;
            center = i;
        }
    }
    if (maxLength % 2 == 1)
        return s.substr(center - maxLength / 2, maxLength);
    return s.substr(center - maxLength / 2, maxLength);
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    string res =  solve(s, n);
    cout << res.size();
    return 0;
}