class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int c = 1; c <= n; ++c) {
            int RHS = c * c;
            int a = 1, b = c - 1;
            while (a <= b) {
                int LHS = a * a + b * b;
                if (LHS == RHS) {
                    res += 2;
                    a++, --b;
                } else if (LHS < RHS) {
                    ++a;
                } else {
                    --b;
                }
            }
        }
        return res;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
