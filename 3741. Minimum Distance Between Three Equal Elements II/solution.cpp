class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = (int) nums.size();

        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            if ((int) pos[i].size() < 3) {
                continue;
            }

            for (int j = 1; j + 1 < (int) pos[i].size(); ++j) {
                ans = min(ans, abs(pos[i][j] - pos[i][j - 1]) + abs(pos[i][j] - pos[i][j + 1]) + abs(pos[i][j - 1] - pos[i][j + 1]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
