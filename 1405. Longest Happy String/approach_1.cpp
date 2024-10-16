class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Store characters we may use in max heap
        priority_queue < pair < int, char > > q;
        if (a)
            q.push({a, 'a'});
        if (b)
            q.push({b, 'b'});
        if (c)
            q.push({c, 'c'});

        // Keep track of the answer size, just for keeping the implementation simple
        int n = 0;

        // The greedy approach is to fill the answer with char that have max{a, b, c}
        // but don't break any condition
        string ans;
        while (!q.empty()) {
            int cur_max = q.top().first;
            char cur_char = q.top().second;
            q.pop();

            // If the current maximum doesn't break any condition, insert it to the answer
            if (n < 2 || !(cur_char == ans[n - 1] && cur_char == ans[n - 2])) {
                ans.push_back(cur_char);
                ++n;
                if (--cur_max)
                    q.push({cur_max, cur_char});
            }
            else {
                // If it breaks, try to insert the next maximum if possible
                if (q.empty())
                    break;
                int next_max = q.top().first;
                char next_char = q.top().second;
                q.pop();
                
                // Don't forget to push [cur_max, cur_char] again
                q.push({cur_max, cur_char});

                // Push next_char and keep iterating
                ans.push_back(next_char);
                ++n;
                if (--next_max)
                    q.push({next_max, next_char});
            }
        }

        return ans;
    }
};

/*
    Time: O(a + b + c)
    Space: O(1)
*/
