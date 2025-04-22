#include <iostream>
#include <vector>
#include <algorithm>

void knapsack(int n, int M, std::vector<int>& profits, std::vector<int>& weights) {
    // In ra danh sách vật thể
    std::cout << "Danh sách vật thể:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Vật thể " << i + 1 
                  << ": Lợi nhuận = " << profits[i] 
                  << ", Trọng lượng = " << weights[i] 
                  << std::endl;
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(M + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= M; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + profits[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    std::cout << "\nTổng lợi nhuận tối đa có thể đạt được: " << dp[n][M] << std::endl;
}

int main() {
    int n = 4;
    int M = 8;
    std::vector<int> profits = {1, 2, 5, 6};
    std::vector<int> weights = {2, 3, 4, 5};

    knapsack(n, M, profits, weights);

    return 0;
}
