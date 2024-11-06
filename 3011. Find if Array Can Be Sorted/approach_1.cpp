class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = (int) nums.size();
        
        vector < int > numSetBits(n);
        for (int i = 0; i < n; ++i)
            numSetBits[i] = countNumSetBits(nums[i]);
        
        for (int l = 0; l < n;) {
            int r = l;
            while (r < n && numSetBits[r] == numSetBits[l])
                r++;
            sort(nums.begin() + l, nums.begin() + r);
            l = r;
        }

        return is_sorted(nums.begin(), nums.end());
    }

private:
    int countNumSetBits(int num) {
        return __builtin_popcount(num);
    }
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
