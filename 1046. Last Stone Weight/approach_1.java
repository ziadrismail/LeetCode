class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int stone : stones) {
            maxHeap.add(stone);
        }

        while (maxHeap.size() >= 2) {
            int y = maxHeap.poll();
            int x = maxHeap.poll();
            if (x == y) {
                continue;
            }
            maxHeap.add(y - x);
        }

        return maxHeap.isEmpty() ? 0 : maxHeap.peek();
    }
}

/**
 * Time Complexity: O(nlog(n))
 * Space Complexity O(n)
 */
