#include <iostream>
using namespace std;
int x, y;
int main(){
    cin >> x >> y;
    if (x == 0 && y == 0)
        cout << 0;  // Gốc tọa độ
    else if (y == 0) 
        cout << 5;  // Trên trục hoành
    else if (x == 0) 
        cout << 6;  // Trên trục tung
    else if (x > 0 && y > 0) 
        cout << 1;  // Góc phần tư thứ nhất
    else if (x < 0 && y > 0) 
        cout << 2;  // Góc phần tư thứ hai
    else if (x < 0 && y < 0) 
        cout << 3;  // Góc phần tư thứ ba
    else if (x > 0 && y < 0)
        cout << 4;  // Góc phần tư thứ tư
}
