class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = (int) nums.size();

        unordered_map<int, int> rem_count;
        for (auto &num : nums) {
            num = ((num % value) + value) % value;
            rem_count[num]++;
        }

        unordered_set<int> included;
        for (auto &[key, val] : rem_count) {
            int cur = key;
            for (int i = 0; i < val; ++i) {
                included.insert(cur);
                cur += value;
            }
        }

        int mex;
        for (mex = 0; mex < n; ++mex) {
            if (included.count(mex) == 0) {
                return mex;
            }
        }

        return mex;
    }
};

/*
    Topics: Hashing, Math
    Time: O(n)
    Space: O(n)
*/
