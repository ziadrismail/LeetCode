class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        List<Map.Entry<Integer, Integer>> numFreq = new ArrayList<>(freq.entrySet());

        numFreq.sort((a, b) -> Integer.compare(b.getValue(), a.getValue()));

        int[] res = new int[k];
        for (int i = 0; i < k; ++i) {
            res[i] = numFreq.get(i).getKey();
        }

        return res;
    }
}

/*
    Time Complexity: O(nlog(n))
    Space Complexity: O(nlog(n))
*/
