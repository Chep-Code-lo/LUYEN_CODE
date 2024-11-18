//MT1-Array1D-2022-11-24-Bai5
#include<iostream>
using namespace std;
int n, count, a[103];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n-1; ++i)
        if(a[i] == a[i+1]){
            count++;
            while(i < n-1 && a[i] == a[i+1]){
                i++;
            }
        }
    cout << count;
}
//MT1-Array1D-202211-24-Bai4
#include <iostream>
#include<algorithm>
using namespace std;
int n, a[103], count_1, count_2;
int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)   cin >> a[i];
    for(int i=0; i<n; ++i)
        if(a[i]!=0)
        {
            while (a[i]%2 == 0)
            {
                a[i]/=2;
                count_1++;
            }
            while (a[i]%5 == 0)
            {
                a[i]/=5;
                count_2++;
            }
        }
    cout << min(count_1, count_2);
    
}
//MT1-Array1D-2022-11-24-Bai3
#include<iostream>
#include<algorithm>
using namespace std;
int n, max_1, max_2, a[103];
int main(){
    cin >> n;
    for(int x, i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);
    for(int i=1; i<n; ++i)
        if(a[0] != a[i]){
            max_1 = a[0]*a[i];
            break;
        }
    for(int i=n-2; i>=0; --i)
        if(a[n-1] != a[i]){
            max_2 = a[n-1]*a[i];
            break;
        }
    cout << max(max_1, max_2);
}
//MT1-Array1D-2022-11-24-Bai2
#include<iostream>
using namespace std;
int n, a[103];
long long sum1, sum2;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], sum1 += a[i];
    for(int i=0; i<n-1; ++i){
        sum2 += a[i];
        if(sum2 == (sum1 - sum2)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
//MT1-Array1D-202211-24-Bai1
#include<iostream>
#include<algorithm>
using namespace std;
int n, a[103], Suffix[103];
int main(){
	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i]; 
	for(int i=0; i<n-1; ++i) Suffix[i] = abs(a[i+1] - a[i]);
	cout << *min_element(Suffix, Suffix + n -1);
}
//MT1-Array1D-2022-11-21-Bai5
#include<iostream>
using namespace std;
long long limit, current_sum, max_sum, arry[102];
int main(){
    cin >> limit;
    for(int i=0; i<limit; ++i)  cin >> arry[i];
    max_sum = current_sum =arry[0];
    for(int i=1; i<limit; ++i){
        current_sum = max(arry[i], current_sum + arry[i]);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
}
//MT1-Array1D-2022-11-21-Bai4
#include <iostream>
using namespace std;
int n, count, pos = -1, maxx, arr[103];
int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n; ++j){
            if(arr[i] == arr[j]) count++;
            if(count > maxx){
                maxx = count;
                pos = i;
            }
        }
    cout << pos;
}
// MT1-Array1D-2022-11-21-Bai3
#include<iostream>
using namespace std;
int n, x, pos, res, minn = INT_MAX, a[103];
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i)
        if (a[i] != x){
            res = abs(x - a[i]);
            if (res < minn){
                minn = res;
                pos = i;
            }
        }
    cout << pos;
}
//MT1-Array1D-2022-11-21-Bai2
#include <iostream>
#include<algorithm>
using namespace std;
int n, a[103];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n, greater<int>());
    for(int i=1; i<n; ++i)
        if(a[0] != a[i]){
            cout << a[i];
            return 0;
        }
    cout << -1;
}
//MT1-Array1D-2022-11-21-Bai1
#include<iostream>
using namespace std;
int n, maxx, pos_1, pos_2, a[103];
int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    maxx = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > maxx) {
            maxx = a[i];
            pos_1 = pos_2 = i; 
        } else if (a[i] == maxx)
            pos_2 = i; 
    cout << pos_2 - pos_1;
}
