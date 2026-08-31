class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        auto* prev = head;
        auto* cur = head->next;

        int prev_local = -1;
        int i = 1;

        int mn = INT_MAX;
        int mx = 0;

        while (cur->next) {
            auto* nxt = cur->next;

            if (is_local(cur, prev, nxt)) {
                if (prev_local != -1) {
                    int cur_dis = i - prev_local;
                    mn = min(mn, cur_dis);
                    mx += cur_dis;
                }
                prev_local = i;
            }

            prev = cur;
            cur = nxt;
            ++i;
        }

        return {mn == INT_MAX ? -1 : mn, mx == 0 ? -1 : mx};
    }

private:
    bool is_local(ListNode* cur, ListNode* prev, ListNode* nxt) {
        if (cur->val > prev->val) {
            return cur->val > nxt->val;
        } else if (cur->val < prev->val) {
            return cur->val < nxt->val;
        }
        return false;
    }
};
