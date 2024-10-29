class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();

        vector dp(n, vector < bool > (m, 0));
        for (int i = 0; i < n; ++i)
            dp[i][0] = 1;

        int ans = 0;

        for (int col = 1; col < m; ++col)
            for (int row = 0; row < n; ++row)
                for (auto &dr : {-1, 0, 1})
                    if (row + dr >= 0 && row + dr < n && dp[row + dr][col - 1] && grid[row][col] > grid[row + dr][col - 1])
                        dp[row][col] = 1, ans = col;

        return ans;
    }    
};

/*
    Time: O(n * m)
    Space: O(n * m)
*/
