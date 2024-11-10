class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = (int) nums.size(), ans = n + 1;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            add(nums[r]);
            while (l <= r && calculateOR() >= k) {
                ans = min(ans, r - l + 1);
                remove(nums[l++]);
            }
        }

        return ans == (n + 1) ? -1 : ans;
    }

private:
    int bitsCount[30];

    void add(int x) {
        for (int bit = 0; bit < 30; ++bit)
            if ((1 << bit) & x)
                ++bitsCount[bit];
    }

    void remove(int x) {
        for (int bit = 0; bit < 30; ++bit)
            if ((1 << bit) & x)
                --bitsCount[bit];
    }

    int calculateOR() {
        int ret = 0;
        for (int bit = 0; bit < 30; ++bit)
            if (bitsCount[bit])
                ret |= 1 << bit;
        return ret;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
