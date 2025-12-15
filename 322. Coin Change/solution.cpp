class Solution {
private:
    const int INF = INT_MAX;

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INF);

        dp[0] = 0;
        for (auto &coin : coins) {
            for (int i = 0; i + coin <= amount; ++i) {
                if (dp[i] != INF) {
                    dp[i + coin] = min(dp[i + coin], dp[i] + 1);
                }
            }
        }

        return dp.back() == INF ? -1 : dp.back();
    }
};

/*
    Time: O(amount)
    Space: O(amount)
*/
