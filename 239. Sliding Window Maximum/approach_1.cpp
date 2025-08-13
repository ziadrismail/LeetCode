class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset < int > unique_nums;
        for (int i = 0; i < k; ++i) {
            unique_nums.insert(nums[i]);
        }

        vector < int > ans;
        ans.push_back(*unique_nums.rbegin());
        for (int i = 1; i + k - 1 < (int) nums.size(); ++i) {
            unique_nums.erase(unique_nums.find(nums[i - 1]));
            unique_nums.insert(nums[i + k - 1]);
            ans.push_back(*unique_nums.rbegin());
        }

        return ans;
    }
};
