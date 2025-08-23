class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> idx = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int diff = target - nums[i];
            if (idx.containsKey(diff)) {
                return new int[] {idx.get(diff), i};
            }
            idx.put(nums[i], i);
        }

        return new int[] {-1, -1};
    }
}

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
