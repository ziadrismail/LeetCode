class Solution {
    public int minCostClimbingStairs(int[] cost) {
        return solve(cost.length, cost);
    }

    private int solve(int i, int[] cost) {
        if (i <= 1) {
            return 0;
        }

        return Math.min(solve(i - 1, cost) + cost[i - 1], solve(i - 2, cost) + cost[i - 2]);
    }
}

/*
    Time Complexity: O(2^n)
    Space Complexity: O(n)
*/
