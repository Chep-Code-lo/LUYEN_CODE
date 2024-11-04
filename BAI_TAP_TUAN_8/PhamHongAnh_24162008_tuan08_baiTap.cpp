// 041_Dãy nón
#include<iostream>
using namespace std;
int limit, pos, maxx, arry[1003];
bool check_1 = true, check_2 = true;
int main(){
    cin >> limit;
    for(int i=0; i<limit; ++i) cin >> arry[i], maxx = max(maxx, arry[i]);
    for(int i=limit-1; i>=0; --i)
        if(maxx == arry[i]){
            pos = i;
            break;
        }
    for(int i=0; i<pos; ++i)
        if(arry[i] >= arry[i+1]){
            check_1 = false;
            break;
        }
    for(int i=pos; i<limit-1; ++i)
        if(arry[i] <= arry[i+1]){
            check_2 = false;
            break;
        }
    cout << (check_1 && check_2 ? "YES" : "NO");
}
// 047_Ma trận xoắn ốc
#include<iostream>
using namespace std;
int limit_1, limit_2, num=1, matrix[102][102];
int main(){
    cin >> limit_1 >> limit_2;
    int top=0, left=0, bottom=limit_1 - 1, right=limit_2 - 1;
    while(left <= right && top <= bottom){
        for(int i=left; i<=right; ++i)
            matrix[top][i] = num++;
        ++top;
        for(int i=top; i<=bottom; ++i)
            matrix[i][right] = num++;
        --right;
        if(top <= bottom){
            for(int i=right; i>=left; --i)
                matrix[bottom][i] = num++;
            --bottom;
        }
        if(left <= right){
            for(int i=bottom; i>=top; --i)
                matrix[i][left] = num++;
            ++left; 
        }
    }
    for(int i=0; i<limit_1; ++i){
        for(int j=0; j<limit_2; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
//026_Chênh lệch liên tiếp
#include<iostream>
using namespace std;
int limit, maxx, a[1003];
int main(){
    cin >> limit;
    for(int i=0; i<limit; ++i) cin >> a[i];
    for(int i=0; i<limit-1; ++i)  maxx = max(maxx, abs(a[i+1] - a[i]));
    cout << maxx << "\n";
}
//035_Mảng con dương
#include<iostream>
using namespace std;
int limit, result, arry_1[1003], arry_1_2[1003];
int main(){
    cin >> limit;
    for(int i=1; i<=limit; ++i) cin >> arry_1[i];
    arry_1_2[0] = 0;
    for(int i=1; i<=limit; ++i){
        if(arry_1[i] > 0)
            arry_1_2[i] = max(arry_1_2[i-1], arry_1_2[i-1]+1);
        else arry_1_2[i] = 0;
    }
    for(int i=1; i<=limit; ++i)
        result = max(result, arry_1_2[i]);
    cout << result << "\n";
}
// 030_Lớn thứ hai
#include<iostream>
#include<algorithm>
using namespace std;
int limit, arry[1003];
int main(){
    cin >> limit;
    for(int i=0; i<limit; ++i) cin >> arry[i];
    sort(arry, arry+limit);
    for(int i=limit-2; i>=0; --i)
        if(arry[limit-1] != arry[i]){
            cout << arry[i];
            break;
        }
}
// 033_Mảng Palindrome
#include<iostream>
using namespace std;
int limit, count, index = 1, arry_1[1003], arry_2[1003];
int main(){
    cin >> limit;
    for(int i=1; i<=limit; ++i) cin >> arry_1[i];
    for(int i=limit; i>=1; --i)
        arry_2[index++] = arry_1[i]; 
    for(int i=1; i<=limit; ++i)
        if(arry_1[i] != arry_2[i]){
            count++;
            break;
        } 
    cout << (count == 0 ? "YES" : "NO");
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
// 6_M1C_DemKoSNTLonX_GK2_09_10_3
#include<iostream>
using namespace std;
bool is_prime(int unknown){
    if(unknown <= 1) return false;
    if(unknown <= 3) return true;
    if(unknown%2 == 0 || unknown%3 == 0) return false;
    for(int i=5; i*i<=unknown; i+=6)
        if(unknown%i == 0 || unknown%(i+2) == 0)    return false;
    return true;
}
int limit, unknown, count, arry[102];
int main(){
    cin >> limit >> unknown;
    for(int i=0; i<limit; ++i) cin >> arry[i], count = (is_prime(arry[i]) && arry[i] > unknown) ? ++count : count;
    cout << count;
    

}
// 7_MT_MaxDongGiua_CK1_13_14
#include <iostream>
#include<algorithm>
using namespace std;
int limit_1, limit_2, matrix[102][102];
int main() 
{
    cin >> limit_1 >> limit_2;
    for(int i=0; i<limit_1; ++i)
        for(int j=0; j<limit_2; ++j) cin >> matrix[i][j];
    int mid = limit_1/2;
    cout << *max_element(matrix[mid], matrix[mid] + limit_2);
}
// 8_M1C_ChuTrinh_CK1_14_15
#include<iostream>
using namespace std;
int limit, unknown, arry[102];
int main(){
    cin >> limit >> unknown;
    for(int i=0; i<limit; ++i) cin >> arry[i];
    if(arry[0] != arry[limit-1]){
        cout << "-1";
        return 0;
    }
    else{
        unknown =unknown%limit;
        for(int i=unknown; i<limit; ++i)
            cout << arry[i] << " ";
        for(int i=1; i<=unknown; ++i)
            cout << arry[i] << " ";
    }
}

