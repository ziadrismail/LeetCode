class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int) nums.size();

        if (n <= 2) {
            return n;
        }

        int ans = 2, l = 2;
        for (int r = 2; r < n; ++r) {
            if (nums[r] != nums[l - 1] || nums[l - 1] != nums[l - 2]) {
                ++ans;
                nums[l++] = nums[r];
            }
        }

        return ans;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
