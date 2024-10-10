class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = (int) nums.size();
        
        // We need an ordered map to save the maximum index for each unique num.
        map < int, int > mx_idx;
        for (int i = 0; i < n; ++i) {
            // try to maximize i
            if (mx_idx.count(nums[i]))
                mx_idx[nums[i]] = max(mx_idx[nums[i]], i);
            else
                mx_idx[nums[i]] = i;
        }

        // We need array of pairs to store each element and its maximum index as a pair
        vector < pair < int, int > > num_idx;
        for (auto &[num, idx] : mx_idx)
            num_idx.emplace_back(num, idx);
        
        // Now we have unique elements sorted so we can do binary search to find the lower bound
        // of each num in nums array, assume we have x as the lower bound of some num in nums array,
        // all y such that y >= x makes a valid ramp, so the greedy choice is to take y with maximum index
        // to do that we can apply suffix maximum to the indices in num_idx array and try to maximize the answer.
        for (int i = (int) num_idx.size() - 2; i >= 0; --i) 
            num_idx[i].second = max(num_idx[i].second, num_idx[i + 1].second);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // using std::lower_bound we can find the minimum valid y.
            auto it = lower_bound(num_idx.begin(), num_idx.end(), make_pair(nums[i], -1));
            
            // we will update our answer if j > i 
            int j = (*it).second;
            if (j > i)
                ans = max(ans, j - i);
        }

        return ans;
    }
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
