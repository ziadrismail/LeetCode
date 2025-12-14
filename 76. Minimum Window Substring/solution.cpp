class Solution {
private:
    void add(char c, unordered_map<char, int>& cnt) {
        cnt[c]++;
    }

    void remove(char c, unordered_map<char, int>& cnt) {
        cnt[c]--;
    } 

    bool good(unordered_map<char, int>& cnt) {
        for (auto &[_, val] : cnt) {
            if (val < 0) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int n = (int) s.size();

        unordered_map<char, int> cnt;
        for (auto &c : t) {
            cnt[c]--;
        }

        int ans_len = n + 1, ans_st = -1;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            add(s[r], cnt);
            while (good(cnt)) {
                remove(s[l], cnt);
                if (!good(cnt)) {
                    add(s[l], cnt);
                    break;
                }
                l++;
            }

            if (good(cnt)) {
                if (ans_len > (r - l + 1)) {
                    ans_len = r - l + 1;
                    ans_st = l;
                }
            }
        }

        if (ans_len == n + 1) {
            return "";
        } 
        return s.substr(ans_st, ans_len);
    }
};

/*
    Time: O(n + m)
    Space: O(1)
*/
