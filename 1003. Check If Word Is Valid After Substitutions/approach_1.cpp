class Solution {
public:
    bool isValid(string s) {
        unordered_map < char, int > letterFrequency;
        set < int > indices;
        
        for (int i = 0; i < (int) s.size(); ++i) {
            letterFrequency[s[i]]++;
            indices.insert(i);
        }

        if (!(letterFrequency['a'] == letterFrequency['b'] && letterFrequency['a'] == letterFrequency['c']))
            return false;
        
        // start from the last occurence of letter a
        for (int i = (int) s.size() - 1; i >= 0 ; --i) {
            if (s[i] == 'a')
                if (!canConstructABC(s, i, indices))
                    return false;
        }
            
        return true;
    }

private:
    const string ABC = "abc";

    bool canConstructABC(
        string& s,
        int indexOfLetterA,
        set < int >& indices
    ) {
        string sub = "a";

        auto iterator = indices.find(indexOfLetterA);
        
        iterator++;
        if (iterator == indices.end())
            return false;
        sub.push_back(s[*iterator]);
        
        iterator++;
        if (iterator == indices.end())
            return false;
        sub.push_back(s[*iterator]);

        if (sub == ABC) { // Delete the substring from the set to get the next substring
            for (int i = 0; i < (int) ABC.size(); ++i)
                indices.erase(iterator--);
            return true;
        }

        return false;
    }
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
