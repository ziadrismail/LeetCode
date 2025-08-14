class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            add(nums[i]);
        }

        vector < int > ans = {get_max()};
        for (int i = 0; i + k < (int) nums.size(); ++i) {
            remove(nums[i]);
            add(nums[i + k]);
            ans.push_back(get_max());
        }

        return ans;
    }

private:
    deque < int > q;

    void add(int x) {
        while (!q.empty() && q.back() < x) {
            q.pop_back();
        }
        q.push_back(x);
    }

    void remove(int x) {
        if (!q.empty() && q.front() == x) {
            q.pop_front();
        }
    }

    int get_max() {
        return q.front();
    }
};
