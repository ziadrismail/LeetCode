class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map < int, int > longestSquareStreak;
        for (auto &num : nums)
            longestSquareStreak[num] = 1;

        for (auto &num : nums)
            if (1LL * num * num <= MAX_VALUE && longestSquareStreak.count(num * num))
                longestSquareStreak[num * num] = max(longestSquareStreak[num * num], longestSquareStreak[num] + 1);
    
        int ans = -1;
        for (auto &[key, val] : longestSquareStreak) 
            if (val > 1)
                ans = max(ans, val);

        return ans;
    }

private:
    const static int MAX_VALUE = (int) 1e5;    
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
