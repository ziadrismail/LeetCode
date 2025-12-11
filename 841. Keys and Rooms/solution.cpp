class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = (int) rooms.size();

        vector<bool> vis(n, false);

        return dfs(0, rooms, vis) == n;
    }

private:
    int dfs(int u, vector<vector<int>>& rooms, vector<bool>& vis) {
        vis[u] = true;

        int ret = 1;
        for (auto &v : rooms[u]) {
            if (!vis[v]) {
                ret += dfs(v, rooms, vis);
            }
        }

        return ret;
    }
};

/*
    Time: O(n + m)
    Space: O(n)
*/
