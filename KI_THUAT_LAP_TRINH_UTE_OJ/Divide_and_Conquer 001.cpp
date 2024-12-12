#include <iostream>
#include <vector>
using namespace std;
long long merge(int arr[], int left, int mid, int right){
    vector<int> left_arr(arr+ left, arr + mid + 1);
    vector<int> right_arr(arr + mid + 1, arr + right + 1);
    int i = 0, j = 0;
    long long inv_count = 0;
    while(i < left_arr.size() && j < right_arr.size()){
        if(left_arr[i] <= right_arr[j]){
            arr[left] = left_arr[i];
            i++;
        }else{
            arr[left] = right_arr[j];
            inv_count += left_arr.size() - i;
            j++;
        }
        left++;
    }
    while(i < left_arr.size()){
        arr[left] = left_arr[i];
        i++;
        left++;
    }
    while(j < right_arr.size()){
        arr[left] = right_arr[j];
        j++;
        left++;
    }
    return inv_count;
}
long long mergeSort(int arr[], int left, int right){
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}
int n, arr[200005];
int main() {
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> arr[i];
    cout << mergeSort(arr, 0, n - 1);
}