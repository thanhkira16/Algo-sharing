#include <iostream>
#include <vector>
#include <algorithm> // for std::max

void knapsack(int n, int M, std::vector<int>& profits, std::vector<int>& weights) {
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

    std::cout << dp[n][M] << std::endl;
}

int main() {
    int n = 4;
    int M = 8;
    std::vector<int> profits = {1, 2, 5, 6};
    std::vector<int> weights = {2, 3, 4, 5};

    knapsack(n, M, profits, weights);

    return 0;
}
