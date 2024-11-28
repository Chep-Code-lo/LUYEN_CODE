#include <iostream>
#include <set>

using namespace std;

// Hàm tính giá trị nhóm máu của con
int getChildBloodTypeValue(int father, int mother) {
    // Giá trị tương ứng với các nhóm máu
    int bloodTypeValues[5] = {0, 1, 2, 4, 8}; // 0: không sử dụng, 1: A, 2: B, 4: AB, 8: O
    set<int> possibleChildTypes;

    // Quy tắc di truyền nhóm máu
    if (mother == 1) { // Mẹ A
        if (father == 1 || father == 0) { // Cha A hoặc O
            possibleChildTypes.insert(1); // A
        } else if (father == 2 || father == 4) { // Cha B hoặc AB
            possibleChildTypes.insert(1); // A
            possibleChildTypes.insert(2); // B
            possibleChildTypes.insert(4); // AB
        }
    } else if (mother == 2) { // Mẹ B
        if (father == 2 || father == 0) { // Cha B hoặc O
            possibleChildTypes.insert(2); // B
        } else if (father == 1 || father == 4) { // Cha A hoặc AB
            possibleChildTypes.insert(2); // B
            possibleChildTypes.insert(1); // A
            possibleChildTypes.insert(4); // AB
        }
    } else if (mother == 4) { // Mẹ AB
        possibleChildTypes.insert(1); // A
        possibleChildTypes.insert(2); // B
        possibleChildTypes.insert(4); // AB
    } else if (mother == 8) { // Mẹ O
        if (father == 1 || father == 2) { // Cha A hoặc B
            possibleChildTypes.insert(1); // A
            possibleChildTypes.insert(2); // B
        }
    }

    // Tính tổng giá trị của các nhóm máu có thể của con
    int totalValue = 0;
    for (int bloodType : possibleChildTypes) {
        totalValue += bloodTypeValues[bloodType];
    }

    return totalValue;
}

int main() {
    int fatherBloodType, motherBloodType;


    cin >> fatherBloodType;

    
    cin >> motherBloodType;

    // Tính và in ra giá trị khả năng nhóm máu của con
    int result = getChildBloodTypeValue(fatherBloodType, motherBloodType);
    cout << result << endl;

    return 0;
}