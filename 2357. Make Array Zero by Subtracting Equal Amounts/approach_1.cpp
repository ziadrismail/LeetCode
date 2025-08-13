class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set < int > unique_non_zero;
        for (auto &num : nums) {
            if (num > 0) {
                unique_non_zero.insert(num);
            }
        }

        return (int) unique_non_zero.size();
    }
};
