class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for (auto &c : s) {
            ans.push_back(c);
            if (checkThreeConsecutive(ans))
                ans.pop_back();
        }

        return ans;
    }

private:
    bool checkThreeConsecutive(string& s) {
        int n = (int) s.size();
        if (n < 3)
            return false;
        return s[n - 1] == s[n - 2] && s[n - 1] == s[n - 3]; 
    }    
};
