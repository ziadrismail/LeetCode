class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagrams = new HashMap<>();
        for (String s : strs) {
            String mapKey = sortString(s);
            if (!anagrams.containsKey(mapKey)) {
                anagrams.put(mapKey, new ArrayList<>());
            }
            anagrams.get(mapKey).add(s);
        }
        return new ArrayList<>(anagrams.values());
    }
    
    private String sortString(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
}

/*
    Time Complexity: O(n * mlog(m))
    Space Complexity: O(n * m)
    
    where:
    n -> strs.length
    m -> strs[i].length
*/
