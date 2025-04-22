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
    cout << "Nhap so luong do vat: ";
    cin >> n;
    w.resize(n);
    v.resize(n);
    
    cout << "Nhap trong luong va gia tri cua tung do vat:\n";
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    cout << "Nhap suc chua cua balo: ";
    cin >> W;

    knapsack(0, 0, 0);
    cout << "Gia tri lon nhat co the dat duoc: " << maxValue << endl;

    return 0;
}
