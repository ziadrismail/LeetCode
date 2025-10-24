class Solution {
public:
    int nextBeautifulNumber(int n) {        
        for (int i = n + 1; i < MAX_N; ++i) {
            unordered_map<int, int> d_count = get_digit_count(i);

            if (is_beautiful(d_count)) {
                return i;
            }
        }

        return MAX_ANS;
    }

private:
    const int MAX_N = (int) 1e6;
    const int MAX_ANS = 1224444;

    unordered_map<int, int> get_digit_count(int x) {
        unordered_map<int, int> d_count;
        while (x) {
            d_count[x % 10]++;
            x /= 10;
        }
        return d_count;
    }

    bool is_beautiful(unordered_map<int, int>& d_count) {
        bool ok = true;
        for (auto &[key, val] : d_count) {
            ok &= (key == val);
        }
        return ok;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
