
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int N = 50000;        // Max array size
const int M = 1000000000;   // Max array value

vector<int> createArray(int n, int max_value);
void SelectionSort(vector<int> &a, int &numAssignments, int &numComparisons, int &numMilliseconds);
void InsertionSort(vector<int> &a, int &numAssignments, int &numComparisons, int &numMilliseconds);
void MergeSort(vector<int> &a, int p, int r, int &numAssignments, int &numComparisons, int &numMilliseconds);
void Merge(vector<int> &a, int p, int q, int r, int &numAssignments, int &numComparisons);
void QuickSort(vector<int> &a, int p, int r, int &numAssignments, int &numComparisons, int &numMilliseconds);
int Partition(vector<int> &a, int p, int r, int &numAssignments, int &numComparisons);
void testSort(string name, vector<int> &a, int &numAssignments, int &numComparisons, int &numMilliseconds, ofstream &file);

int main() {
    string path = "./sort.tsv";
    ofstream file(path, ios::app);
    if (!file) {
        cerr << "File failed to open." << endl;
        return 1;
    }
    file << "No\tName\t#Assignments\t#Comparisons\tMilliseconds\n";

    for (int i = 0; i < 10; i++) {
        vector<int> a = createArray(N, M);
        vector<int> b(a);
        vector<int> c(a);
        vector<int> d(a);

        int numAssignments = 0, numComparisons = 0, numMilliseconds = 0;
        testSort("SelectionSort", a, numAssignments, numComparisons, numMilliseconds, file);
        testSort("InsertionSort", b, numAssignments, numComparisons, numMilliseconds, file);
        testSort("MergeSort", c, numAssignments, numComparisons, numMilliseconds, file);
        testSort("QuickSort", d, numAssignments, numComparisons, numMilliseconds, file);
    }
    file.close();
    return 0;
}

vector<int> createArray(int n, int max_value) {
    vector<int> a(n);
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % max_value + 1;
    }
    return a;
}

void SelectionSort(vector<int> &a, int &numAssignments, int &numComparisons, int &numMilliseconds) {
    auto start = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < a.size() - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < a.size(); j++) {
            numComparisons++;
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
        numAssignments += 3;
    }
    auto end = chrono::high_resolution_clock::now();
    numMilliseconds = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void InsertionSort(vector<int> &a, int &numAssignments, int &numComparisons, int &numMilliseconds) {
    auto start = chrono::high_resolution_clock::now();
    for (size_t i = 1; i < a.size(); i++) {
        int key = a[i];
        numAssignments++;
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            numComparisons++;
            a[j + 1] = a[j];
            numAssignments++;
            j--;
        }
        a[j + 1] = key;
        numAssignments++;
    }
    auto end = chrono::high_resolution_clock::now();
    numMilliseconds = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void MergeSort(vector<int> &a, int p, int r, int &numAssignments, int &numComparisons, int &numMilliseconds) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(a, p, q, numAssignments, numComparisons, numMilliseconds);
        MergeSort(a, q + 1, r, numAssignments, numComparisons, numMilliseconds);
        Merge(a, p, q, r, numAssignments, numComparisons);
    }
}

void Merge(vector<int> &a, int p, int q, int r, int &numAssignments, int &numComparisons) {
    int n1 = q - p + 1, n2 = r - q;
    vector<int> L(a.begin() + p, a.begin() + q + 1);
    vector<int> R(a.begin() + q + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        numComparisons++;
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
        numAssignments++;
    }
    while (i < n1) a[k++] = L[i++], numAssignments++;
    while (j < n2) a[k++] = R[j++], numAssignments++;
}

int Partition(vector<int> &a, int p, int r, int &numAssignments, int &numComparisons) {
    int pivot = a[r], i = p - 1;
    numAssignments++;
    for (int j = p; j < r; j++) {
        numComparisons++;
        if (a[j] <= pivot) {
            swap(a[++i], a[j]);
            numAssignments += 3;
        }
    }
    swap(a[i + 1], a[r]);
    numAssignments += 3;
    return i + 1;
}

void QuickSort(vector<int> &a, int p, int r, int &numAssignments, int &numComparisons, int &numMilliseconds) {
    if (p < r) {
        int q = Partition(a, p, r, numAssignments, numComparisons);
        QuickSort(a, p, q - 1, numAssignments, numComparisons, numMilliseconds);
        QuickSort(a, q + 1, r, numAssignments, numComparisons, numMilliseconds);
    }
}

void testSort(string name, vector<int> &a, int &numAssignments, int &numComparisons, int &numMilliseconds, ofstream &file) {
    numAssignments = numComparisons = numMilliseconds = 0;
    if (name == "SelectionSort") SelectionSort(a, numAssignments, numComparisons, numMilliseconds);
    else if (name == "InsertionSort") InsertionSort(a, numAssignments, numComparisons, numMilliseconds);
    else if (name == "MergeSort") MergeSort(a, 0, a.size() - 1, numAssignments, numComparisons, numMilliseconds);
    else if (name == "QuickSort") QuickSort(a, 0, a.size() - 1, numAssignments, numComparisons, numMilliseconds);
    file << name << "\t" << numAssignments << "\t" << numComparisons << "\t" << numMilliseconds << "\n";
}
