class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = (int) s.size();

        map<string, string> mp;
        for (auto &v : knowledge) {
            mp[v[0]] = v[1];
        }

        string ans;
        for (int i = 0; i < n; ) {
            if (s[i] == '(') {
                string key;
                
                int j = i + 1;
                while (j < n && s[j] != ')') {
                    key += s[j++];
                }

                if (mp.count(key) == 0) {
                    ans += '?';
                } else {
                    for (auto &c : mp[key]) {
                        ans += c;
                    }
                }

                i = j + 1;
            } else {
                ans += s[i++];
            }
        }

        return ans;
    }
};
