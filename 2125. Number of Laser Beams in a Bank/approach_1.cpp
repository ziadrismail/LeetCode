class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev_devices = 0;
        for (auto &s : bank) {
            int devices = count(s.begin(), s.end(), '1');
            ans += prev_devices * devices;
            if (devices) {
                prev_devices = devices;
            }
        }

        return ans;
    }
};
