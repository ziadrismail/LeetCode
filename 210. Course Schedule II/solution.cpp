class Solution {
private:
    vector<int> ans;

    bool dfs(int u, vector<vector<int>>& g, vector<int>& color) {
        color[u] = 1;
        for (auto &v : g[u]) {
            if (color[v] == 0) {
                if (dfs(v, g, color)) {
                    return true;
                }
            } else if (color[v] == 1) {
                return true;
            }
        }
        ans.push_back(u);
        color[u] = 2;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (auto &p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].push_back(a);
        }

        vector<int> color(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            if (color[i] == 0) {
                if (dfs(i, g, color)) {
                    return {};
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
    Time: O(V + E)
    Space: O(V + E)
*/
