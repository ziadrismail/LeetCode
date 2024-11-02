class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();

        // dp[i] = -1: the i-th state not solved yet
        vector < int > dp(n, -1);

        return solve(0, n, nums, dp);
    }

private:
    int solve(int i, int &n, vector < int >& nums, vector < int >& dp) {
        if (i >= n)
            return 0;
        
        auto &ret = dp[i];
        if (~ret)
            return ret;
        
        return ret = max(solve(i + 1, n, nums, dp), solve(i + 2, n, nums, dp) + nums[i]);
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
