class Solution {
public:
    int countBinarySubstrings(string s) {
        vector < pair < bool, int > > bit_cnt;
        for (auto &c : s) {
            bool bit = c == '0' ? 0 : 1;
            if (bit_cnt.empty() || bit != bit_cnt.back().first) {
                bit_cnt.push_back({bit, 1});
            } else {
                bit_cnt.back().second++;
            }
        }

        int ans = 0;
        for (int i = 0; i + 1 < (int) bit_cnt.size(); ++i) {
            ans += min(bit_cnt[i].second, bit_cnt[i + 1].second);
        }

        return ans;
    }
};
