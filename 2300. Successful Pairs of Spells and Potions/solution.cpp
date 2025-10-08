class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = (int) potions.size();

        sort(potions.begin(), potions.end());

        vector<int> ans;
        for (auto &spell : spells) {
            int successful_pairs = m - find_first_successful_pair(potions, m, spell, success);
            ans.push_back(successful_pairs);
        }

        return ans;
    }

private:
    int find_first_successful_pair(vector<int>& potions, int m, int spell, long long success) {
        int lo = -1, hi = m;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;
            if (1LL * spell * potions[mid] >= success) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};

/*
    Topics: Sorting, and Binary Search
    Time: O(mlog(m) + nlog(m))
    Space: O(1) if we ignore answer array space
*/
