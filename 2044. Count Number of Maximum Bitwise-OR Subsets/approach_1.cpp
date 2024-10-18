class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int numSize = (int) nums.size();

        // The maximum bitwise OR is the OR of the whole array
        int maxBitwiseOR = 0;
        for (auto &num : nums)
            maxBitwiseOR |= num;

        int answer = 0;

        // Try all possible subsets
        for (int subset = 1; subset < (1 << numSize); ++subset) {
            // Calculate the bitwise OR of the subset
            int subBitwiseOR = 0;
            for (int i = 0; i < numSize; ++i) {
                if ((1 << i) & subset)
                    subBitwiseOR |= nums[i];
            }

            // If the the bitwise OR equals the max bitwise OR, consider this in the answer
            if (subBitwiseOR == maxBitwiseOR)
                ++answer;
        }

        return answer;
    }
};

/*
    Time: O(2^n * n)
    Space: O(1)
*/
