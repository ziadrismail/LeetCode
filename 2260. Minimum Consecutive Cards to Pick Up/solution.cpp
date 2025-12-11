class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = (int) cards.size();

        unordered_map<int, int> lst_seen;

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (lst_seen.count(cards[i]) == 0) {
                lst_seen[cards[i]] = i;
                continue;
            }
            ans = min(ans, i - lst_seen[cards[i]] + 1);
            lst_seen[cards[i]] = i;
        }   

        return ans == INT_MAX ? -1 : ans;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
