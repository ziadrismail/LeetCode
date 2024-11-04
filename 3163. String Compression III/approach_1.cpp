class Solution {
public:
    string compressedString(string word) {
        vector < pair < int, char > > freqChars;
        for (auto &ch : word) {
            if (freqChars.empty() || ch != freqChars.back().second)
                freqChars.emplace_back(1, ch);
            else if (freqChars.back().second == ch) {
                if (freqChars.back().first == 9)
                    freqChars.emplace_back(1, ch);
                else
                    freqChars.back().first++;
            }
        }

        string comp;
        for (auto &[c, ch] : freqChars)
            comp += to_string(c) + ch;
        
        return comp;
    }
};

/* 
    Time: O(n)
    Space: O(n)
*/
