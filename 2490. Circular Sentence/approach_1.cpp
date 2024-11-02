class Solution {
public:
    bool isCircularSentence(string sentence) {
        auto words = convertSentenceToArrayOfWords(sentence);
        int n = (int) words.size();
        bool ans = words[n - 1].back() == words[0][0];
        for (int i = 0; i + 1 < n; ++i)
            ans &= words[i].back() == words[i + 1][0];
        return ans;
    }

    vector < string > convertSentenceToArrayOfWords(string &sentence) {
        vector < string > ret;
        string s;
        for (auto &c : sentence) {
            if (c == ' ') {
                ret.push_back(s);
                s.clear();
                continue;
            }
            s.push_back(c);
        }
        if (!s.empty())
            ret.push_back(s);
        return ret;
    }    
};

/*
    Time: O(n)
    Space: O(n)
*/
