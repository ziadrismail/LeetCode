class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length(), m = t.length();

        if (n != m) {
            return false;
        }

        int[] freq = new int[26];
        for (int i = 0; i < n; ++i) {
            char si = s.charAt(i), ti = t.charAt(i);
            freq[si - 'a']++;
            freq[ti - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
}

/*
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
