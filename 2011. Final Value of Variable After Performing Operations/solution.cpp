class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (auto operation : operations) {
            if (operation[0] == '+' || operation.back() == '+') {
                ++X;
            } else {
                --X;
            }
        }
        return X;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
