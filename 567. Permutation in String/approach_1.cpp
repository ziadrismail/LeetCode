class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Frequency array for s1
        vector < int > cnt1(26, 0);
        for (auto &c : s1)
            cnt1[c - 'a']++;

        // Frequency array for s2, we will use it while applying sliding window
        vector < int > cnt2(26, 0);

        // Left pointer to indicate the start of substring
        int l = 0;

        // Apply Sliding-Window technique 
        for (int r = 0; r < (int) s2.size(); ++r) {
            cnt2[s2[r] - 'a']++;
            
            // While the current substring has some unneeded character, move the left pointer
            while (move_left(cnt1, cnt2)) {
                cnt2[s2[l] - 'a']--;
                ++l;
            }

            // If the current substring is one of s1's permutations, return true
            if (good(cnt1, cnt2))
                return true;
        }

        // If we reach here, it's impossible to find one of s1's permutations, return false
        return false;
    }

private:
    bool move_left(vector < int > &cnt1, vector < int > &cnt2) {
        // We will move the left pointer iff we hold a character that we don't need to form one of s1's permutations
        for (int i = 0; i < 26; ++i)
            if (cnt2[i] > cnt1[i])
                return true;
        return false;
    }

    bool good(vector < int > &cnt1, vector < int > &cnt2) {
        // We will consider a substring good iff each character in s1 occurs if that subarray and nothing more
        for (int i = 0; i < 26; ++i)
            if (cnt1[i] != cnt2[i])
                return false;
        return true;
    }    
};

/* 
    Time: O(n + m), where n: size of s1, m: size of s2
    Space: O(1), because the size of frequency arrays fixed for all possible n's and m's
*/
