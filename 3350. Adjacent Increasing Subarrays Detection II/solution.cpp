class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = (int) nums.size();

        vector<pair<int, int>> sub_borders;
        sub_borders.push_back({0, 0});

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                sub_borders.back().second = i;
            } else {
                sub_borders.push_back({i, i});
            }
        }

        int ans = 1;
        for (int i = 0; i < (int) sub_borders.size(); ++i) {
            int st = sub_borders[i].first, en = sub_borders[i].second;
            ans = max(ans, (en - st + 1) / 2);
            if (i + 1 < (int) sub_borders.size()) {
                int nxt_st = sub_borders[i + 1].first, nxt_en = sub_borders[i + 1].second;
                if (nxt_st == en + 1) {
                    ans = max(ans, min(en - st + 1, nxt_en - nxt_st + 1));
                }
            }
        }

        return ans;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
