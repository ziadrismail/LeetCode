class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = (int) days.size();

        // We need memo(dp) table to save solved states, dp[i] = -1 means onsolved state
        vector < int > dp(n + 1, -1);

        // Use Dynamic Programming(Top-Down) approach
        return solve(0, n, days, costs, dp);
    }

private:
    vector < int > ways = {1, 7, 30};

    int solve(int i, int n, vector < int >& days, vector < int >& costs, vector < int >& dp) {
        // Base Case
        if (i >= n)
            return 0;
        
        // Check whether the state has been solved or not (memo step)
        auto &ret = dp[i];
        if (~ret)
            return ret;

        // Make ret(dp[i]) infinity then try to minimize it
        ret = INT_MAX;
        
        // Try each possible cost(pass ticket)
        for (int idx = 0; idx < 3; ++idx) {            
            // the number of days you will pay costs[idx] for.
            int pass = ways[idx];

            // Using binary search, find the index j of lower bound in days array where days[j] >= days[i] + pass
            int j = lower_bound(days.begin() + i + 1, days.end(), days[i] + pass) - days.begin();

            // Try to solve the subproblem where you pay costs[idx] to pass ways[idx] days if you currently in days[i]
            ret = min(ret, solve(j, n, days, costs, dp) + costs[idx]);
        }

        return ret;
    }    
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
