/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = (int) lists.size();

        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > minHeap;

        for (int i = 0; i < k; ++i) {
            if (!lists[i]) {
                continue;
            }
            
            pair<int, int> val_idx = make_pair(lists[i]->val, i);
            minHeap.push(val_idx);
        }

        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while (!minHeap.empty()) {
            int idx = minHeap.top().second;
            minHeap.pop();

            current->next = lists[idx];

            lists[idx] = lists[idx]->next;
            if (lists[idx]) {
                pair<int, int> val_idx = make_pair(lists[idx]->val, idx);
                minHeap.push(val_idx);
            }

            current = current->next;
        }

        ListNode* res = dummy->next;
        return res;
    }
};

/*
    N -> The sum of lists[i].length
    Time: O(Nlog(k))
    Space: O(k)
*/
