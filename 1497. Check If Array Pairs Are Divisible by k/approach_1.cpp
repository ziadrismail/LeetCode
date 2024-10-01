class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        /*
            arr[i] and arr[j] match iff: arr[i] % k == x and arr[j] % k == k - x
            so we just need to store frequencies of arr[i] % k for all i (0 <= i < n), then check freq[x] == freq[k - x] for all x (0 < x < k / 2)
            - Time: O(n)
            - Space: O(n)
        */

        // Store frequency of remainders in a hashmap
        unordered_map < int, int > mod_freq;

        // Don't forget to fix negative mods
        for (auto &i : arr)
            mod_freq[(i % k + k) % k]++;

        // Check the possibility of making pairs 
        for (int x = 1; x * 2 < k; ++x)
            if (mod_freq[x] != mod_freq[k - x])
                return false;

        // One corner case: if k is even mod_freq[k / 2] must be even too
        if (k % 2 == 0 && mod_freq[k / 2] % 2)
            return false;        

        // Note that the case where freq[0] % 2 == 1 is covered implicitly
        // but why? because n must be even, ignoring the numbers with 0 remainders, our array
        // will end up with odd number of integers which is impossible to put them in pairs
        return true;    
    }
};
