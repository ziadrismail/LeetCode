class Solution {
public:
    int maxDiff(int num) {
        string numString = to_string(num);
        int a = num, b = num;
        for (char x = '0'; x <= '9'; ++x) {
            for (char y = '0'; y <= '9'; ++y) {
                string newString = replace(numString, x, y);
                int newNum = stoi(newString);
                if (hasLeadingZero(newString))
                    continue;
                a = max(a , newNum), b = min(b, newNum);
            }
        }
        return a - b;
    }

private:
    string replace(string s, char x, char y) {
        for (auto &c : s)
            if (c == x)
                c = y;
        return s;
    }

    bool hasLeadingZero(string s) {
        return s[0] == '0';
    }
};
