class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool ans = sentence.back() == sentence[0];
        for (int i = 0; i < (int)sentence.size(); ++i)
            if (sentence[i] == ' ')
                ans &= sentence[i - 1] == sentence[i + 1];
        return ans;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
