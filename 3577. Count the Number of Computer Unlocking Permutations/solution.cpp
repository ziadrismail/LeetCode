class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = (int) complexity.size();

        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        int ans = 1;
        for (int i = 2; i < n; ++i) {
            ans = (int) (1LL * i * ans % MOD);
        }

        return ans;
    }

private:
    const int MOD = (int) 1e9 + 7;
};

/*
    Time: O(n)
    Space: O(1)
*/
