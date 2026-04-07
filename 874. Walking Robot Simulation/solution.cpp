class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> blocks;
        for (auto & obstacle : obstacles) {
            blocks.insert(make_pair(obstacle[0], obstacle[1]));
        }

        int x = 0, y = 0, ans = 0;
        for (auto &command : commands) {
            if (command < 0) {
                cur += (command == -2 ? -1 : 1);
                cur = (cur + 4) % 4;
            } else {
                for (int i = 1; i <= command; ++i) {
                    int new_x = x + dx[cur];
                    int new_y = y + dy[cur];
                    if (blocks.count(make_pair(new_x, new_y))) {
                        continue;
                    }
                    x = new_x;
                    y = new_y;
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }

private:
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {1, 0, -1, 0};
    int cur = 0;
};

/*
    Time: O(nlog(m))
    Space: O(m)
*/
