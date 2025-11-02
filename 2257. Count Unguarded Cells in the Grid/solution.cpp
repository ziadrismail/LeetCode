class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> status(n, vector<int>(m, 0));

        for (auto &cell : guards) {
            status[cell[0]][cell[1]] = 1;
        }

        for (auto &cell : walls) {
            status[cell[0]][cell[1]] = 2;
        }

        for (auto &cell : guards) {
            scan_grid(cell[0], cell[1], n, m, status);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += (status[i][j] == 0);
            }
        }

        return ans;
    }

private:
    void scan_grid(int r, int c, int n, int m, vector<vector<int>>& status) {
        scan_row(r, c, n, m, status);
        scan_column(r, c, n, m, status);
    }

    void scan_row(int r, int c, int n, int m, vector<vector<int>>& status) {
        for (int i = c - 1; i >= 0; --i) {
            if (status[r][i] == 1 || status[r][i] == 2) {
                break;
            }
            status[r][i] = 3;
        }

        for (int i = c + 1; i < m; ++i) {
            if (status[r][i] == 1 || status[r][i] == 2) {
                break;
            }
            status[r][i] = 3;
        }
    }

    void scan_column(int r, int c, int n, int m, vector<vector<int>>& status) {
        for (int i = r - 1; i >= 0; --i) {
            if (status[i][c] == 1 || status[i][c] == 2) {
                break;
            }
            status[i][c] = 3;
        }

        for (int i = r + 1; i < n; ++i) {
            if (status[i][c] == 1 || status[i][c] == 2) {
                break;
            }
            status[i][c] = 3;
        }
    }
};

/*
    Time: O(n * m)
    Space: O(n * m)
*/
