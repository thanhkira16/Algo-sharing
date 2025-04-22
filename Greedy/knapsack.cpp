#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit;
    int weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    for (int i = 0; i < items.size(); i++) {
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

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
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
    }

    int capacity;
    cin >> capacity;

    double maxProfit = fractionalKnapsack(items, capacity);
    cout << maxProfit << endl;

    return 0;
}
