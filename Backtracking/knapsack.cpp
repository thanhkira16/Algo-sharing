#include <iostream>
#include <vector>
using namespace std;

int n, W;
vector<int> w, v;
int maxValue = 0;

void knapsack(int i, int currWeight, int currValue) {
    // Nếu đã xét hết các món
    if (i == n) {
        if (currValue > maxValue) {
            maxValue = currValue;
        }
        return;
    }

    // Nhánh chọn món i (nếu đủ trọng lượng)
    if (currWeight + w[i] <= W) {
        knapsack(i + 1, currWeight + w[i], currValue + v[i]);
    }

    // Nhánh không chọn món i
    knapsack(i + 1, currWeight, currValue);
}

int main() {
    // Khai báo sẵn input
    v = {3, 5, 6, 10}; // Giá trị (profit)
    w = {2, 3, 4, 5};  // Trọng lượng (weight)
    W = 8;             // Sức chứa balo
    n = v.size();

    // In ra dữ liệu đầu vào
    cout << "Danh sách vật thể:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vật " << i + 1 << ": giá trị = " << v[i] << ", trọng lượng = " << w[i] << endl;
    }
    cout << "Sức chứa balo: " << W << endl;

    // Gọi hàm giải
    knapsack(0, 0, 0);
    cout << "\nGiá trị lớn nhất có thể đạt được: " << maxValue << endl;

    return 0;
}
