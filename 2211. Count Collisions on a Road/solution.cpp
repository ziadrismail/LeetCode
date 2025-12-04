class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;

        int flag = -1;
        for (auto &d : directions) {
            if (d == 'L') {
                if (flag >= 0) {
                    res += flag + 1;
                    flag = 0;
                }
            } else if (d == 'S') {
                if (flag > 0) {
                    res += flag;
                }
                flag = 0;
            } else {
                if (flag == -1) {
                    flag = 1;
                } else {
                    flag++;
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
