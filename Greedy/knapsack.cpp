#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit;
    int weight;
    double ratio;
};

// So sánh theo ratio giảm dần, nếu bằng nhau thì theo profit giảm dần
bool compare(Item a, Item b) {
    if (a.ratio == b.ratio)
        return a.profit > b.profit;
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    // Tính ratio cho từng vật
    for (int i = 0; i < items.size(); i++) {
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    // In ra danh sách vật thể sau khi tính tỉ lệ
    cout << "Danh sách vật thể (trước khi sắp xếp):\n";
    for (int i = 0; i < items.size(); i++) {
        cout << "Vật thể " << i + 1 << ": "
             << "Lợi nhuận = " << items[i].profit
             << ", Trọng lượng = " << items[i].weight
             << ", Tỉ lệ = " << fixed << setprecision(2) << items[i].ratio
             << endl;
    }

    // Sắp xếp theo ratio
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < items.size(); i++) {
        if (remainingCapacity >= items[i].weight) {
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        } else {
            double fraction = (double)remainingCapacity / items[i].weight;
            totalProfit += fraction * items[i].profit;
            break;
        }
    }

    return totalProfit;
}

int main() {
    // Khai báo sẵn dữ liệu
    vector<Item> items = {
        {10, 2},  // Vật thể 1
        {5, 3},   // Vật thể 2
        {15, 5},  // Vật thể 3
        {7, 7},   // Vật thể 4
        {6, 1},   // Vật thể 5
        {18, 4},  // Vật thể 6
        {3, 1}    // Vật thể 7
    };

    int capacity = 15;

    double maxProfit = fractionalKnapsack(items, capacity);
    cout << "\nTổng lợi nhuận tối đa có thể đạt được: " << maxProfit << endl;

    return 0;
}
