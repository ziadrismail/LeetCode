class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = (int) s.size();
        while (n--) {
            if (s == goal)
                return true;
            rotate(s.begin(), s.begin() + 1, s.end());
        }
        return s == goal;
    }
};
