class Solution {
    class Point {
        int squaredDistance;
        int[] point = new int[2];

        Point(int x, int y) {
            point[0] = x;
            point[1] = y;
            squaredDistance = x * x + y * y;
        }
    }

    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> maxHeap = new PriorityQueue<>(
            (a, b) -> Integer.compare(b.squaredDistance, a.squaredDistance)
        );

        for (int[] point : points) {
            Point curPoint = new Point(point[0], point[1]);
            maxHeap.offer(curPoint);
            if (maxHeap.size() > k) {
                maxHeap.poll();
            }
        }

        int[][] result = new int[k][2];
        for (int i = 0; i < k; ++i) {
            result[i] = maxHeap.poll().point;
        }

        return result;
    }
}

/*
    Time Complexity: O(nlog(k))
    Space Complexity: O(k)
*/
