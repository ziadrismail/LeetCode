class Solution {
private:
    const int INF = (int) 1e7;

    int dp[1005][2][105];

    int solve(int i, vector<int>& prices, bool have, int left) {
        if (i >= (int) prices.size()) {
            return (have ? -INF : 0);
        }

        auto &ret = dp[i][have][left];
        if (~ret) {
            return ret;
        }

        ret = solve(i + 1, prices, have, left);
        if (left > 0 && have) {
            ret = max(ret, solve(i + 1, prices, 0, left - 1) + prices[i]);
        } else if (left > 0){
            ret = max(ret, solve(i + 1, prices, 1, left) - prices[i]);
        }

        return ret;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return max(0, solve(0, prices, 0, k));
    }
};

/*
    Time: O(n * k)
    Space: O(n * k)
*/
