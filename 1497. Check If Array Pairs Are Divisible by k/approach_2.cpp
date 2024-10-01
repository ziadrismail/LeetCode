class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        /*
            arr[i] and arr[j] match iff: arr[i] % k == x and arr[j] % k == k - x
            so we can sort the array based on mod(arr[i] % k) then using two pointers approach,
            try to match left most element with the right most then update pointers
            - Time: O(nlog(n))
            - Space: O(1)
        */

        int n = (int) arr.size();

        // Replace each element with (i % k + k) % k, this formula is important to avoid negative mods 
        for (auto &i : arr)
            i = (i % k + k) % k;

        // Sort the array ascendingly
        sort(arr.begin(), arr.end());

        // We need two pointers, left and right
        int l = 0, r = n - 1;

        // Get rid of 0 elements first, but in pairs becuse 0 element must match with another 0 element
        while (l < n && !arr[l]) {
            // It's impossible to make a pair, return false
            if (l + 1 < n && arr[l + 1] != 0)
                return false;
            l += 2;
        }

        // Try to make pairs with positive mods
        while (l < r) {
            // Return false if they're not matching pair
            if ((arr[l] + arr[r]) % k)
                return false;
            
            // Update pointers
            ++l, --r;
        }
        
        return true;
    }
};
