
#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(int a[], int p, int r) {
    int pivot = a[p];
    int i = p + 1, j = r;

    while (true) {
        while (i <= r && a[i] < pivot) i++;  
        while (j > p && a[j] > pivot) j--;   
        if (i >= j) break;
        swap(a[i], a[j]); 
    }
    swap(a[p], a[j]); 
    return j;
}
void quickSort(int a[], int p, int r) {
    if (p < r) {
        int pivotIndex = partition(a, p, r);
        quickSort(a, p, pivotIndex - 1);  
        quickSort(a, pivotIndex + 1, r); 
    }
}
void printArray(int a[], int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main() {
    int a[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);
    cout << "Mảng sau khi sắp xếp: ";
    printArray(a, n);
    return 0;
}
