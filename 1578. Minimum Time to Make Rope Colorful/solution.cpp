class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = (int) colors.size();

        int ans = 0;
        int l = 0, r = 1;
        while (r < n) {
            if (colors[l] == colors[r]) {
                if (neededTime[l] <= neededTime[r]) {
                    ans += neededTime[l];
                    l = r;
                    r++;
                } else {
                    ans += neededTime[r];
                    r++;
                }
            } else {
                l = r;
                r++;
            }
        }

        return ans;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
