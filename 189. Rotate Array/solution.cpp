class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int) nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
