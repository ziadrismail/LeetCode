class Solution {
public:
    int reverseDegree(string s) {
        int n = (int) s.size();

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            auto c = s[i - 1];
            ans += ('z' - c + 1) * i;
        }

        return ans;
    }
};
