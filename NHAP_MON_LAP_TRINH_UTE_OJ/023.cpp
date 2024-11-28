    #include<iostream>
    using namespace std;
    int n, a[1000006];
    double sum;
    int main(){
        cin >> n;
        for(int i=0; i<n; ++i) cin >> a[i], sum += a[i];
        printf("%.3f", double(sum/n));
    }