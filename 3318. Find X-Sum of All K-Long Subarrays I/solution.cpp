class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        for (int i = 0; i + k - 1 < (int) nums.size(); ++i) {
            ans.push_back(find_sub_sum(nums, i, i + k, x));
        }
        return ans;
    }

private:
    int find_sub_sum(vector<int>&nums, int lo, int hi, int x) {
        unordered_map<int, int> freq;
        for (int i = lo; i < hi; ++i) {
            ++freq[nums[i]];
        }

        vector<pair<int, int>> freq_val;
        for (auto &[key, val] : freq) {
            freq_val.emplace_back(val, key);
        }
        sort(freq_val.begin(), freq_val.end());

        int ret = 0, cnt = 0;
        while (!freq_val.empty() && cnt < x) {
            int val = freq_val.back().second, freq = freq_val.back().first;
            ret += val * freq;
            freq_val.pop_back();   
            ++cnt;
        }

        return ret;
    }
};

/*
    Time: O(n + klog(k))
    Space: O(k)
*/
