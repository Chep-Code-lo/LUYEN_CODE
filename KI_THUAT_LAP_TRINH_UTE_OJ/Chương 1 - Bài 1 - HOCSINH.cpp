#include <bits/stdc++.h>
using namespace std;

struct stu
{
    string ms;
    string name;
    string bday;
    string add;
    string gtinh;
    string point;
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<stu> a(n);
    for(int i=0; i<n; i++){
        getline(cin, a[i].ms);
        getline(cin, a[i].name);
        getline(cin, a[i].bday);
        getline(cin, a[i].add);
        getline(cin, a[i].gtinh);
        cin >> a[i].point;
        cin.ignore();
    }
    int count = 0;
    for(int i=0; i<n; i++){
        cout << a[i].ms << endl;
        cout << a[i].name << endl;
        cout << a[i].bday << endl;
        cout << a[i].add << endl;
        cout << a[i].gtinh << endl;
        cout << a[i].point << endl;
        if (a[i].point[0] >= '5')
            count++;
    }
    cout << count;
}