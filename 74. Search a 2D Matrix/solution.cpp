class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();

        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (matrix[m][0] <= target) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l == -1) {
            return false;
        }

        int l2 = -1, r2 = m;
        while (r2 - l2 > 1) {
            int m2 = (l2 + r2) / 2;
            if (matrix[l][m2] <= target) {
                l2 = m2;
            } else {
                r2 = m2;
            }
        }

        return matrix[l][l2] == target;
    }
};

/*
    Time: O(log(n * m))
    Space: O(1)
*/
