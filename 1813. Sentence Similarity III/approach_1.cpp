class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // To make the problem simpler, covert strings into arrays of words
        auto words1 = convert_sentence(sentence1);
        auto words2 = convert_sentence(sentence2);

        int n = words1.size(), m = words2.size();

        // Let sentence1 be the sentence with smallest size, just for simplicity
        if (n > m) {
            swap(words1, words2);
            swap(n, m);
        }

        // The only 3 options is to add the missing subsentence in sentence1(the smaller one) at:
        //  1. The beginning
        //  2. The end
        //  3. Between two words
        // So all we need is to check prefixes and suffixes of both sentences
        
        for (int pref_size = 0; pref_size <= n; ++pref_size) {
            // Hold both prefix size and suffix size
            int suf_size = n - pref_size;

            // If the boolean is true at the end of this iterating, return true
            bool ok = true;

            // Check that the prefix matches in both sentences
            for (int i = 0; i < pref_size; ++i) {
                if (i >= words2.size()) { // Make sure we don't access out of bounds
                    ok = false;
                    break;
                }
                ok &= words1[i] == words2[i];
            }

            // Check that the suffix matches
            for (int i = 0; i < suf_size; ++i) {
                if ((n - i - 1) >= words1.size() || (m - i - 1) >= words2.size()) { // Bounds check for suffix
                    ok = false;
                    break;
                }
                ok &= words1[n - i - 1] == words2[m - i - 1];
            }
            
            if (ok)
                return true;
        }

        // We didn't return true inside the loop, it means it's impossible to make both sentences equal
        return false;
    }

private:
    vector < string > convert_sentence(string &sentence) {
        // This function converts a given sentence into array of strings(words)
        
        vector < string > ret;

        // Hold the current word, if you find a space push s into ret array then clear s and continue
        string s;
        for (auto &c : sentence) {
            if (c == ' ') {
                ret.push_back(s);
                s.clear();
                continue;
            }
            s.push_back(c);
        }

        // don't forget to add the string into the array
        if (s.size())
            ret.push_back(s);

        return ret;
    }   
};
