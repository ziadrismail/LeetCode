class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int) cost.size();

        // Need to pay 0 coins to step on floor n + 1
        cost.push_back(0);

        int oneStepBack = cost[0], twoStepsBack = 0;
        for (int i = 1; i <= n; ++i) {
            int curFloor = min(oneStepBack, twoStepsBack) + cost[i];
            twoStepsBack = oneStepBack;
            oneStepBack = curFloor;
        }

        return oneStepBack;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
