class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Set of unique elements
        set < int > st(arr.begin(), arr.end());

        // Hashmap to save the rank of each element
        unordered_map < int, int > rank;

        // Loop over the set ascending while mintaining the current rank
        int cur_rank = 1;
        for (auto &i : st)
            rank[i] = cur_rank++;

        // Replace each element with its rank
        for (auto &i : arr)
            i = rank[i];
        
        return arr;
    }
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
