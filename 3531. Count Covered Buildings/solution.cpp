class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> mx_r(n + 1), mn_r(n + 1, n + 1);
        vector<int> mx_c(n + 1), mn_c(n + 1, n + 1);

        for (auto &building : buildings) {
            auto x = building[0], y = building[1];

            mx_r[y] = max(mx_r[y], x);
            mn_r[y] = min(mn_r[y], x);

            mx_c[x] = max(mx_c[x], y);
            mn_c[x] = min(mn_c[x], y);
        }

        int res = 0;
        for (auto &building : buildings) {
            auto x = building[0], y = building[1];

            res += (mn_r[y] < x && x < mx_r[y]) && (mn_c[x] < y && y < mx_c[x]);
        }

        return res;
    }
};

/*
    Time: O(m)
    Space: O(n)
*/
