class MedianFinder {
    private int n;
    private PriorityQueue<Integer> maxHeap; // Left half
    private PriorityQueue<Integer> minHeap;

    public MedianFinder() {
        n = 0;
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
    }
    
    public void addNum(int num) {
        ++n;

        if (!minHeap.isEmpty() && num >= minHeap.peek()) {
            minHeap.offer(num);
        } else {
            maxHeap.offer(num);
        }

        balanceHeaps();
    }
    
    public double findMedian() {
        if (n % 2 == 0) {
            return (double) (minHeap.peek() + maxHeap.peek()) / 2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.peek();
        }
        return minHeap.peek();
    }

    private void balanceHeaps() {
        if (maxHeap.size() - minHeap.size() > 1) {
            minHeap.offer(maxHeap.poll());
        } else if (minHeap.size() - maxHeap.size() > 1) {
            maxHeap.offer(minHeap.poll());
        }
    }
}

/**
 * Time Complexity: O(nlog(n) + mlog(n))
 * Space Complexity: O(n)
 * m -> number of findMedian calls
 * n -> number of addNum calls
 */
