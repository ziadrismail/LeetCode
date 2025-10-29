class Solution {
public:
    int smallestNumber(int n) {
        for (int i = 1; i < 10; ++i) {
            int candidate = (1 << i) - 1;
            if (candidate >= n) {
                return candidate;
            }
        }
        return 1023;
    }
};

/*
    Time: O(1)
    Space: O(1)
*/
