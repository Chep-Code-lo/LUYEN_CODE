#include <iostream>
#include <algorithm>
using namespace std;
int x1, y1, x2, y2, a1, b1, a2, b2;
int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> a1 >> b1 >> a2 >> b2;
    int x_left = max(x1, a1);
    int y_top = min(y1, b1);
    int x_right = min(x2, a2);
    int y_bottom = max(y2, b2);
    int width = x_right - x_left;
    int height = y_top - y_bottom;
    int area = 0;

    if (width > 0 && height > 0) {
        area = width * height;
    }
    cout << area;

    return 0;
}