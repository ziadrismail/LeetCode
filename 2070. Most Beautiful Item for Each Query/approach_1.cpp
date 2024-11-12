class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        preprocessItems(items);

        vector < int > ans;
        for (auto &query : queries)
            ans.push_back(getMaxBeauty(items, query));

        return ans;
    }

private:
    void preprocessItems(vector < vector < int > >& items) {
        sort(items.begin(), items.end());

        for (int i = 1; i < (int) items.size(); ++i)
            items[i][1] = max(items[i][1], items[i - 1][1]);
    }

    int getMaxBeauty(vector < vector < int > >& items, int query) {
        auto it = upper_bound(
            items.begin(),
            items.end(),
            vector < int >{query, INT_MAX}
        );

        if (it == items.begin())
            return 0;
        
        it--;
        int ret = (*it)[1];
        
        return ret;
    }
};

/*
    Time: O(nlog(n))
    Space: O(1)
*/
