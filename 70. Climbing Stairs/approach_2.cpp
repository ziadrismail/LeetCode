class Solution {
public:
    int climbStairs(int n) {
        int oneStepBack = 1, twoStepsBack = 1;
        for (int i = 2; i <= n; ++i) {
            int curStair = oneStepBack + twoStepsBack;
            twoStepsBack = oneStepBack;
            oneStepBack = curStair;
        }
        return oneStepBack;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
