class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();
        
        if (n <= 3) {
            int ans = nums[0];
            for (auto &num : nums)
                ans = max(ans, num);
            return ans;
        }
        
        int robFirstHouse = solve(nums, 0, n - 1);
        int robLastHouse = solve(nums, 1, n);

        return max(robFirstHouse, robLastHouse);
    }

private:
    int solve(vector < int >& nums, int firstRob, int n) {
        vector < int > dp(n, 0);
        
        // Base Case:
        dp[firstRob] = nums[firstRob];

        // Build dp
        for (int i = 2; i < n; ++i) {
            dp[i - 1] = max(dp[i - 1], dp[i - 2]);
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
