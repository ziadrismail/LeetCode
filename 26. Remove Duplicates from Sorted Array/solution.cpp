class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 1; i < (int) nums.size(); ++i) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
