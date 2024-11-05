class Solution {
public:
    int minChanges(string s) {
        int n = (int) s.size();

        int ans = 0, lastCnt = 1;
        char last = s[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == last) {
                lastCnt++;
                continue;
            }
            if (s[i] != last) {
                if (lastCnt % 2)
                    lastCnt++, ans++;
                else {
                    lastCnt = 1;
                    last = s[i];
                }
            }
        }

        return ans;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
