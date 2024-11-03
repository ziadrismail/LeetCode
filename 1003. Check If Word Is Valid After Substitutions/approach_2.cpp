class Solution {
public:
    bool isValid(string s) {
        stack < char > AB;
        for (auto &c : s) {
            if (c == 'c') {
                if (AB.empty() || AB.top() != 'b') return false;
                AB.pop();
                if (AB.empty() || AB.top() != 'a') return false;
                AB.pop();
            }
            else
                AB.push(c);
        }
        return AB.empty();
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
