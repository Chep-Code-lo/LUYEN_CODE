
#include <iostream>
#include <string>
using namespace std;

void PrintArray(int a[], int p, int r);
void SelectionSort(int a[], int p, int r);
void InsertionSort(int a[], int p, int r);
void MergeSort(int a[], int p, int r);
void Merge(int a[], int p, int q, int r);
void QuickSort(int a[], int p, int r);
int Partition(int a[], int p, int r);
void testSort(string name, int a[], int p, int r);

int main() {
    int p = 0, r = 7;
    int a[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int b[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int c[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int d[] = {2, 4, 5, 7, 1, 2, 3, 6};

    testSort("SelectionSort", a, p, r);
    testSort("InsertionSort", b, p, r);
    testSort("MergeSort", c, p, r);
    testSort("QuickSort", d, p, r);

    return 0;
}

void testSort(string name, int a[], int p, int r) {
    cout << "Mang truoc khi sap xep: ";
    PrintArray(a, p, r);

    cout << "Sorting with " << name << " ...\n";
    if (name == "SelectionSort") {
        SelectionSort(a, p, r);
    } else if (name == "InsertionSort") {
        InsertionSort(a, p, r);
    } else if (name == "MergeSort"){
        MergeSort(a, p, r);
    } else if (name == "QuickSort"){
        QuickSort(a, p, r);
    }
    
    cout << "Mang sau khi sap xep: ";
    PrintArray(a, p, r);
}

void PrintArray(int a[], int p, int r) {
    for(int i = p; i <= r; i++) {
        cout << a[i] << "\t";
    }
    cout << "\n";
}

void SelectionSort(int a[], int p, int r) {
    for (int i = p; i < r; i++) {
        int minIdx = i;
        for (int j = i + 1; j <= r; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        swap(a[i], a[minIdx]);
    }
}

void InsertionSort(int a[], int p, int r) {
    for (int i = p + 1; i <= r; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= p && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void Merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = a[p + i];
    for (int j = 0; j < n2; j++) R[j] = a[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void MergeSort(int a[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}

void QuickSort(int a[], int p, int r) {
    if (p < r) {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

int Partition(int a[], int p, int r) {
    int pivot = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j] <= pivot) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

