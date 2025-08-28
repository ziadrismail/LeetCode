class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;

        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        List<List<Integer>> bucket = new ArrayList<>();
        initializeArrayList(bucket, n + 1);

        for (Map.Entry<Integer, Integer> entry: freq.entrySet()) {
            bucket.get(entry.getValue()).add(entry.getKey());
        }

        int[] res = new int[k];
        int res_pos = 0;
        for (int i = n; i >= 1 && k > 0; --i) {
            for (int j = 0; j < bucket.get(i).size() && k-- > 0; ++j) {
                res[res_pos++] = bucket.get(i).get(j);
            }
        }

        return res;
    }

    private void initializeArrayList(List<List<Integer>> list, int n) {
        for (int i = 0; i < n; ++i) {
            list.add(new ArrayList<>());
        }
    }
}

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
