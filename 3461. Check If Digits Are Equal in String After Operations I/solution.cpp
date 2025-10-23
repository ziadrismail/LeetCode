class Solution {
public:
    bool hasSameDigits(string s) {
        int n = (int) s.size();

        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j + 1 < n - i; ++j) {
                int sum = ((s[j] - '0') + (s[j + 1] - '0')) % 10;
                s[j] = '0' + sum;
            }
        }
        return s[0] == s[1];
    }
};

/*
    Time: O(n^2)
    Space: O(1)
*/
