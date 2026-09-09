class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) {
            return 0;
        }

        long long ans = 0;
        long long lo = 1LL * 1000, hi = 1LL * 1000000;
        int commas = 1;
        while (hi <= MAX) {
            if (lo <= n && n < hi) {
                ans += 1LL * (n - lo + 1) * commas;
                break;
            }
            ans += 1LL * (hi - lo) * commas;
            lo = hi;
            hi = 1LL * 1000 * hi;
            ++commas;
        }
        return ans;
    }

private:
    const long long MAX = 1LL * (long long)1e18;
};
