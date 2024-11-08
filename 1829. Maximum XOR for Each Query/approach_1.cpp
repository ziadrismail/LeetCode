class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int totalXOR = 0;
        for (auto &num : nums)
            totalXOR ^= num;
        
        vector < int > ans;
        while (!nums.empty()) {
            int k = 0;
            for (int bit = 0; bit < maximumBit; ++bit)
                if (((1 << bit) & totalXOR) == 0)
                    k += 1 << bit;
            ans.push_back(k);

            totalXOR ^= nums.back();
            nums.pop_back();
        }

        return ans;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
