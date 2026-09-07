class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = (int) nums.size();

        vector<int> mn(n);
        mn.back() = nums.back();
        for (int i = n - 2; i >= 0; --i) {
            mn[i] = min(mn[i + 1], nums[i]);
        }

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);

            if (mx - mn[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
