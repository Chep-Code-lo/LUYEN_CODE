//037_Mảng giống nhau
#include<iostream>
#include<algorithm>
using namespace std;
int n, countt, a[1003], b[1003];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for(int i=0; i<n; ++i)
        if(a[i] != b[i]){
            countt++;
            break;
        }
    cout << (countt == 0 ? "YES" : "NO");
}
//038_Độc nhất
#include<iostream>
#include<set>
using namespace std;
int n, a[1003];
set<int>se;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], se.insert(a[i]);
    for(int x : se) cout << x << " ";
}
//039_Giá trị thường xuyên
#include<iostream>
#include<map>
using namespace std;
int n, count, a[1003];
map<int, int>mp;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], mp[a[i]]++;
    for(auto it : mp)
        if(it.second > 2)   count++;
    cout << count;
    
}
//040_Giá trị xuất hiện nhiều nhất
#include<iostream>
#include<map>
using namespace std;
int n, maxx, pos, a[1003];
map<int, int>mp;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], mp[a[i]]++;
    for(auto it : mp)
        if(it.second > maxx)
            maxx = it.second;
    for(auto it : mp)
        if(it.second == maxx)
            pos = it.first;
    cout << pos;
}
//043_Tổng cột
#include<iostream>
using namespace std;
int n, m, a[102][102];
long long sum;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)  cin >> a[i][j];
    for(int j = 0; j < m; j++) {
        sum = 0;
        for(int i = 0; i < n; i++)
            sum += a[i][j];
        cout << sum << " ";
    }
    return 0;
}
//044_Hiện diện
#include<iostream>
using namespace std;
int n, m, x, y, a[15][15], b[15][15];
bool check = false;
int main(){
    cin >> n >> m >> x >> y;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j) cin >> a[i][j];
    for(int i=0; i<x; ++i)
        for(int j=0; j<y; ++j) cin >> b[i][j];
    for(int i=0; i<=n-x; ++i){
        for(int j=0; j<=m-y; ++j){
            bool YES = true;
            for(int l=0; l<x; ++l){
                for(int r=0; r<y; ++r)
                    if(a[i+l][j+r] != b[l][r]){
                        YES = false;
                        break;
                    }
                if(!YES) break;
            }
            if(YES){
                check = true;
                break;
            }
        }
        if(check) break;
    }
    cout << (check ? "YES" : "NO");
}
//045_Tổng đường chéo
#include<iostream>
using namespace std;
int n, m, x, y, a[102][102];
long long sum;
int main(){
    cin >> n >> m >> x >> y;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j) cin >> a[i][j];
    x--, y--;
    for(int i=0; i<n; ++i){
        int j1 = y - (x-i);
        int j2 = y + (x-i);
        if(j1>=0 &&  j1<m)
            sum += a[i][j1];
        if(j2>=0 && j2<m)
            sum += a[i][j2];
    }
    cout << sum - a[x][y];

}
//048_Xoay ma trận
#include<iostream>
using namespace std;
int n, a[102][102], b[102][102];
int main(){
    cin >> n ;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) cin >> a[i][j];
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            b[j][n-1-i] = a[i][j];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cout << b[i][j] << " ";
        cout << "\n";
    }
}
//049_Tìm kiếm trong mảng
#include<iostream>
using namespace std;
int n, k, a[1003];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i)
        if(a[i] == k){
            cout << "YES";
            return 0;
        }
    cout << "NO";
}
//050_Học đếm trong mảng
#include<iostream>
using namespace std;
int n, k, count, a[1003];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i)
       if(a[i] == k)
        count++;
    cout << count;

}
