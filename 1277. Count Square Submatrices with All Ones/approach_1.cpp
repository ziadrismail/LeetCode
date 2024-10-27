class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (matrix[i][j] && i + 1 < n && j + 1 < m)
                    matrix[i][j] += min({matrix[i + 1][j], matrix[i][j + 1], matrix[i + 1][j + 1]});
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};

/*
    Time: O(n * m)
    Space: O(1)
*/
