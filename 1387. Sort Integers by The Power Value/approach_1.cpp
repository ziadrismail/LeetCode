class Solution {
public:
    int getKth(int lo, int hi, int k) {
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
    int get_power(int x) {
        // This function is basically simulating the process of getting power value
        int steps = 0;
        while (x != 1) {
            if (x % 2 == 0)
                x >>= 1;
            else
                x = x * 3 + 1;
            ++steps;    
        }
        return steps;
    }    
};
