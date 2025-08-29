class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int[] prefix = new int[n];
        buildPrefix(n, nums, prefix);

        int[] suffix = new int[n];
        buildSuffix(n, nums, suffix);

        int[] res = new int[n];
        for (int i = 0; i < n; ++i) {
            int prefix_product = i == 0 ? 1 : prefix[i - 1];
            int suffix_product = i == n - 1 ? 1 : suffix[i + 1];
            res[i] = prefix_product * suffix_product;
        }

        return res;
    }

    private void buildPrefix(int n, int[] nums, int[] prefix) {
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                prefix[i] = nums[i];
            } else {
                prefix[i] = prefix[i - 1] * nums[i];
            }
        }
    }

    private void buildSuffix(int n, int[] nums, int[] suffix) {
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                suffix[i] = nums[i];
            } else {
                suffix[i] = suffix[i + 1] * nums[i];
            }
        }
    }
}

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
