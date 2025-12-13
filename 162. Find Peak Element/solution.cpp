class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = (int) nums.size();

        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (m > 0 && nums[m] < nums[m - 1]) {
                r = m - 1;
            } else if ((m + 1 < n) && nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                return m;
            }
        }

        return -1;
    }
};

/*
    Time: O(log(n))
    Space: O(1)
*/
