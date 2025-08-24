class Solution {
    public int climbStairs(int n) {
        int prev = 1, secondPrev = 1;
        for (int i = 2; i <= n; ++i) {
            int current = prev + secondPrev;
            secondPrev = prev;
            prev = current;
        }
        return prev;
    }
}

/*
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
