#include <iostream>
#include <vector>

using namespace std;
long long merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    long long inv_count = 0;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            inv_count += leftArr.size() - i;
            j++;
        }
        k++;
    }

    while (i < leftArr.size()) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightArr.size()) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    return inv_count;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << mergeSort(arr, 0, n - 1) << endl;
    return 0;
}