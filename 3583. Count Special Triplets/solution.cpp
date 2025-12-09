class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = (int) nums.size();

        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < n; ++i) {
            idx[nums[i]].push_back(i);
        }

        int ans = 0;
        for (int j = 1; j + 1 < n; ++j) {
            int target = nums[j] * 2;
            if (idx.count(target) == 0) {
                continue;
            }

            auto& v = idx[target];
            if (v.size() < 2 || v[0] >= j) {
                continue;
            }
            
            auto split = upper_bound(v.begin(), v.end(), j);

            int l = split - v.begin();
            int r = (int) v.size() - l;

            if (nums[j] == 0) {
                l--;
            }

            ans = (ans % MOD + l * 1LL * r % MOD) % MOD;
        }

        return ans;
    }

private:
    const int MOD = (int) 1e9 + 7;
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
