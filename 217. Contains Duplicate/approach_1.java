class Solution {
    public boolean containsDuplicate(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
}

/*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/
