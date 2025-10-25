class Solution {
public:
    int totalMoney(int n) {
        int week = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 7 == 0) {
                week++;
            }
            ans += week + (i % 7);
        }
        return ans;
    }
};
