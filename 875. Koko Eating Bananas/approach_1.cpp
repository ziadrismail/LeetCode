class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 0, hi = (int) 1e9;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;
            if (good(piles, h, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }

private:
    bool good(vector<int> &piles, int h, int k) {
        long long tot_hours = 0;
        for (auto &pile : piles) {
            tot_hours += 1LL * (pile + k - 1) / k; 
        }

        return tot_hours <= h;
    }
};
