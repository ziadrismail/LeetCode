class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Using partial sum technique, the problem can be solved in O(MAX) time
        for (auto interval : intervals) {
            int left = interval[0], right = interval[1];
            partial_sum[left]++;
            partial_sum[right + 1]--;
        }

        // Calculate the prefix sum on partial_sum array
        for (int i = 1; i < MAX; ++i)
            partial_sum[i] += partial_sum[i - 1];
        
        // Our answer will be the maximum value(number of intersections) in partial_sum
        int ans = INT_MIN;
        for (auto &x : partial_sum)
            ans = max(ans, x);

        return ans;
    }
private:
    const static int MAX = (int) 1e6 + 20;
    int partial_sum[MAX];    
};

/*
    Time: O(MAX)
    Space: O(MAX)
*/
