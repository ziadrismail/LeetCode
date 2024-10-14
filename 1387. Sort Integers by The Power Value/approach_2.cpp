class Solution {
public:
    int getKth(int lo, int hi, int k) {
        // initialize the hash map with the base case: power of 1 is 0
        steps[1] = 0;

        // we need a Priority Queue (Min Heap) to store [power, x] pairs
        priority_queue < pair < int, int > > min_heap;
        for (int x = lo; x <= hi; ++x)
            min_heap.push(make_pair(-get_power(x), -x));

        // extract the first k - 1 elements from the heap, then the top element will be the answer
        for (int i = 0; i + 1 < k; ++i)
            min_heap.pop();
        return -min_heap.top().second;    
    }

private:
    // A hash map works as memoization to avoid double calculations
    unordered_map < int, int > steps;

    // This function is basically simulating the process of getting power value.
    // It's a recursive with memoization function to save intermediate calculations and use them later if needed.
    int get_power(int x) {
        // Check if the current value of x calculated before
        if (steps.count(x))
            return steps[x];
        
        // Recursively calculate power of x and save the returned result in the hash
        if (x % 2 == 0)
            steps[x] = 1 + get_power(x / 2);
        else
            steps[x] = 1 + get_power(x * 3 + 1);
        
        // Return the value stored in the hash, this ensures we won't double calculate
        return steps[x];
    }    
};
