class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = (int) nums.size();

        int max_current = nums[0];
        int max_global = nums[0];

        for (int i = 1; i < n; ++i) {
            max_current = max(max_current + nums[i], nums[i]);
            max_global = max(max_global, max_current);
        }

        return max_global;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
