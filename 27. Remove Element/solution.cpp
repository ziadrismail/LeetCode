class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int) nums.size();

        int k = n;
        for (auto &num : nums) {
            if (num == val) {
                --k;
            }
        }
        
        int l = 0, r = n - 1;
        while (l < r) {
            while (r > l && nums[r] == val) {
                --r;
            }
            while (l < r && nums[l] != val) {
                ++l;
            }
            swap(nums[l++], nums[r--]);
        }

        return k;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
