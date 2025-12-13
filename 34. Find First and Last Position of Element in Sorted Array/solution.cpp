class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        auto up = upper_bound(nums.begin(), nums.end(), target) - nums.begin();  

        if (lo == up) {
            return {-1, -1};
        }
        return {(int) lo, (int) up - 1};
    }
};

/*
    Time: O(log(n))
    Space: O(1)
*/
