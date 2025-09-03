class MedianFinder {
    private int n;
    private List<Integer> nums;

    public MedianFinder() {
        n = 0;
        nums = new ArrayList<>();
    }
    
    public void addNum(int num) {
        ++n;
        nums.add(num);
    }
    
    public double findMedian() {
        Collections.sort(nums);
        if (n % 2 == 0) {
            return (double) (nums.get(n / 2) + nums.get(n / 2 - 1)) / 2.0;
        }
        return nums.get(n / 2);
    }
}

/**
 * Time Complexity: O(m * nlog(n))
 * Space Complexity: O(n)
 * m -> number of findMedian calls
 * n -> number of addNum calls
 */
