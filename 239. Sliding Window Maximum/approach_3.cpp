class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            add(nums[i]);
        }

        vector < int > ans = {get_max()};
        for (int i = k; i < (int) nums.size(); ++i) {
            add(nums[i]);
            remove();
            ans.push_back(get_max());
        }

        return ans;
    }

private:
    stack < pair < int, int > > s1, s2;

    void add(int x) {
        int mx = s1.empty() ? x : max(s1.top().second, x);
        s1.push({x, mx});
    }

    void remove() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.top().first;
                s1.pop();
                int mx = s2.empty() ? x : max(s2.top().second, x);
                s2.push({x, mx});
            }
        }
        s2.pop();
    }

    int get_max() {
        if (s1.empty() || s2.empty()) {
            return s1.empty() ? s2.top().second : s1.top().second;
        } else {
            return max(s1.top().second, s2.top().second);
        }
    }
};
