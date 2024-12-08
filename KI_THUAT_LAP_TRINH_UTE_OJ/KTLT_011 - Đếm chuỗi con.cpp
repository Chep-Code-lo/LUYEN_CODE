#include <bits/stdc++.h>
using namespace std;
int n;

int cnt;

int s;

void printSubset(vector<int> &arr, vector<int> &subset, int sum, int start) {
    if (sum == 0)
    {
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }
    if (start == arr.size() || sum < 0)
    {
        return;
    }
    subset.push_back(arr[start]);
    printSubset(arr, subset, sum - arr[start], start + 1);
    subset.pop_back();
    printSubset(arr, subset, sum, start + 1);
}
void f(vector<int> &arr, int i, int currSum)
{
    if (currSum == s)
    {
        cnt++;
        return;
    }
    if (currSum < s && i < n)
    {
        f(arr, i + 1, currSum + arr[i]);

        f(arr, i + 1, currSum);
    }
}
int main()
{
    cin>>n>>s;
    cnt = 0;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> subset;
    f(arr,0,0);
    if( cnt == 1 )
    {
         printSubset(arr, subset, s, 0);
    }
    else
        cout<<cnt;

    return 0;
}
