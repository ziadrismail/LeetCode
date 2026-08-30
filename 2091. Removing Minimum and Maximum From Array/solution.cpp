class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = (int) nums.size();

        if (n <= 2) {
            return n;
        }

        int mn_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx_idx = max_element(nums.begin(), nums.end()) - nums.begin();

        if (mn_idx > mx_idx) {
            swap(mn_idx, mx_idx);
        }

        int between = mx_idx - mn_idx - 1;
        int frnt = mn_idx;
        int back = n - mx_idx - 1;

        int sum = frnt + back + between;
        int largest = max({frnt, back, between});

        return sum - largest + 2;
    }
};
