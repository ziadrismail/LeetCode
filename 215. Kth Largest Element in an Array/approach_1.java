class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
}

/*
    Time Complexity: O(nlog(n))
    Space Complexity: O(1)
*/
