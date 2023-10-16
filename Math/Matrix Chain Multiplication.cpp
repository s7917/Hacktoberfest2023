#include <iostream>
#include <vector>

using namespace std;

int matrixChainMultiplication(vector<int> dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> dimensions = {10, 30, 5, 60};
    int minCost = matrixChainMultiplication(dimensions);
    cout << "Minimum number of multiplications: " << minCost << endl;

    return 0;
}
