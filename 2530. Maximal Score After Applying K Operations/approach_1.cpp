class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // We need a Priority Queue (Max Heap) to return the maximum value
        priority_queue < int > max_heap(nums.begin(), nums.end()); // O(nlog(n))

        // Apply the operation on the current maximum value
        long long ans = 0;
        while (k--) { // O(klog(n))
            // Extract the maximum
            int cur_max = max_heap.top();
            max_heap.pop();

            // Add the maximum and update the heap
            ans += cur_max;
            max_heap.push((cur_max + 2) / 3);
        }

        return ans;
    }
};

/*
    Time: O(nlog(n) + klog(n))
    Space: O(n)
*/
