class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = (int) coins.size(), m = coins[0].size(), l = 3;

        vector dp(n, vector (m, vector (l, -INF)));
        dp[0][0][2] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool up = i > 0, left = j > 0;

                for (int k = 0; k < l; ++k) {
                    if (left) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                    }
                    if (up) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                    }

                    if (coins[i][j] < 0 && k > 0) {
                        if (left) {
                            dp[i][j][k - 1] = max(dp[i][j][k - 1], dp[i][j - 1][k]);
                        }
                        if (up) {
                            dp[i][j][k - 1] = max(dp[i][j][k - 1], dp[i - 1][j][k]);
                        }
                    }
                }
            }
        }

        int ans = -INF;
        for (int k = 0; k < l; ++k) {
            ans = max(ans, dp[n - 1][m - 1][k]);
        }
        return ans;
    }

private:
    const int INF = (int) 3e8;
};
