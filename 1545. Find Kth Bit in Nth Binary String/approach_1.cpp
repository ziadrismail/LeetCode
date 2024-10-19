class Solution {
public:
    char findKthBit(int n, int k) {
        vector < bool > dp((1 << n) + 1);

        dp[1] = 0;
        for (int i = 1; i < n; ++i) {
            dp[1 << i] = 1;
            for (int r = (1 << i) + 1, l = (1 << i) - 1; r < (1 << (i + 1)); ++r, --l)
                dp[r] = !dp[l];
        }

        return dp[k] ? '1' : '0';
    }
};

/*
    Time: O(2^n)
    Space: O(2^n)
*/
