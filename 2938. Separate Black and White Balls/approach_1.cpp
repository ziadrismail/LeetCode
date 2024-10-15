class Solution {
public:
    long long minimumSteps(string s) {
        int n = (int) s.size();

        // Take care of integer overflow
        long long ans = 0;

        // Initially, current target = n - 1, if s[i] == '1', we need (cur_target - i) swaps
        // then we move the current target to the left (decrement cur_target)
        int cur_target = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                ans += cur_target - i;
                cur_target--;
            }
        }

        return ans;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
