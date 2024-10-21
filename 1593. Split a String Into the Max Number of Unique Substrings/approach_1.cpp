class Solution {
public:
    int maxUniqueSplit(string s) {
        backtrack(0, s, "");
        return ans;
    }

private:
    set < string > uniqueSubStrings;
    int ans = 0;
    
    void backtrack(int i, string &s, string subString) {
        if (i >= (int) s.size()) {
            ans = max(ans, (int) uniqueSubStrings.size());
            return;
        }

        subString.push_back(s[i]);

        // Try not to split
        backtrack(i + 1, s, subString);

        // Try to split
        if (uniqueSubStrings.count(subString) == 0) {
            uniqueSubStrings.insert(subString);
            backtrack(i + 1, s, "");
            uniqueSubStrings.erase(subString);
        }

        subString.pop_back();
    }
};
