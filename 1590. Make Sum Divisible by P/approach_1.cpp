class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = (int) nums.size();

        // Store indices of each suffix sum modulo p from 0 to p - 1, use a hashmap
        unordered_map < int, vector < int > > suf_mods; 
        
        // No need to store suffix sum in an array, just use a variable
        int suf_sum = 0;

        // The answer originally is to delete the whole array, but this is not allowed if it remains n return -1
        int ans = n;

        // While storing indices, consider the case when it's possible to delete a prefix
        for (int i = n - 1; i >= 0; --i) {
            suf_sum = (suf_sum + nums[i]) % p;
            
            if (suf_sum)
                suf_mods[suf_sum].push_back(i);
            else
                ans = min(ans, i);
        }

        // Reverse each vector in suf_mods hashmap to easily apply binary search
        for (auto &[_, v] : suf_mods)
            reverse(v.begin(), v.end());

        // Hold prefix sum in a variable
        int pref_sum = 0;

        // For each possible pref_sum, if it's x, find the closest index from the right in suf_mods[p - x]
        for (int l = 0; l < n; ++l) {
            pref_sum = (pref_sum + nums[l]) % p;

            // Don't forget the case when it's possible to delete a suffix
            if (pref_sum == 0) {
                ans = min(ans, n - l - 1);
                continue;
            }

            // Using binary search, Find the closest suffix to the right with suf_sum = p - pref_sum
            suf_sum = p - pref_sum;
            auto it = upper_bound(suf_mods[suf_sum].begin(), suf_mods[suf_sum].end(), l);
            if (it == suf_mods[suf_sum].end())
                continue;
            auto r = *it;
            ans = min(ans, r - l - 1);
        }

        return (ans == n ? -1 : ans);
    }
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
