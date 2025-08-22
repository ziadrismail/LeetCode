class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length(), m = t.length();

        if (n != m) {
            return false;
        }

        boolean[] matched = new boolean[m];
        for (char c : s.toCharArray()) {
            boolean foundMatch = false;

            for (int i = 0; i < m; ++i) {
                if (matched[i]) {
                    continue;
                }

                if (c == t.charAt(i)) {
                    matched[i] = true;
                    foundMatch = true;
                    break;
                }
            }

            if (!foundMatch) {
                return false;
            }
        }

        return true;
    }
}

/*
    Time Complexity: O(n * m)
    Space Complexity: O(m)
*/
