class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();

        // Corner case to avoid out-of-bound errors
        if (n == 1)
            return nums[0];
        
        vector < int > dp(n);

        // Base Cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Build dp
        for (int i = 2; i < n; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        
        return dp.back();
    }
};

/* 
    Time: O(n)
    Space: O(n)
*/
