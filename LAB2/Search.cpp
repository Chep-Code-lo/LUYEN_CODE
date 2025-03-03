#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
using namespace chrono;
const int N = 5e4;
const int M = 1e9;
const int TESTS = 10;
vector<int> createArray(int n, int max_value){
    vector<int> a(n);
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % max_value + 1;
    }
    return a;
}
bool LinearSearch(const vector<int>& a, int x, int &comparisons){
    for (size_t i = 0; i < a.size(); ++i) {
        comparisons++;
        if (a[i] == x) return true;
    }
    return false;
}
bool BinarySearch(const vector<int>& a, int x, int &comparisons){
    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (a[mid] == x) return true;
        if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
void testSearch(int testNo, const string& name, const vector<int>& a, int x, ofstream &file) {
    int comparisons = 0;
    auto start = high_resolution_clock::now();
    bool found = (name == "LinearSearch") ? LinearSearch(a, x, comparisons) : BinarySearch(a, x, comparisons);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    int milliseconds = duration.count() / 1000;  // Chuyển từ microseconds sang milliseconds
    file << testNo << "\t" << name << "\t" << comparisons << "\t" << milliseconds << "\n";
}
int main() {
    string path = "./search.tsv";
    ofstream file(path, ios::out);
    if (!file) {
        cerr << "File failed to open." << endl;
        return 1;
    }
    file << "No\tAlgorithm\t#Comparisons\tMilliseconds\n";
    file.close();
    for(int i=1; i<=TESTS; i++){
        vector<int> a = createArray(N, M);
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());
        int x = a[rand() % N];
        ofstream file_append(path, ios::app);
        if (!file_append) {
            cerr << "File failed to open." << endl;
            return 1;
        }
        testSearch(i, "LinearSearch", a, x, file_append);
        testSearch(i, "BinarySearch", sorted_a, x, file_append);
        file_append.close();
    }
    return 0;
}

