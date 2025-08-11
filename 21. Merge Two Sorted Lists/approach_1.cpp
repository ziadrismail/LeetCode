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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur = new ListNode(0);
        ListNode* ans = cur;

        while (list1 != nullptr || list2 != nullptr) {
            int mn_val;
            if (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    mn_val = list1->val;
                    list1 = list1->next;
                } else {
                    mn_val = list2->val;
                    list2 = list2->next;
                }
            } else if (list1 != nullptr) {
                mn_val = list1->val;
                list1 = list1->next;
            } else {
                mn_val = list2->val;
                list2 = list2->next;
            }
            cur->next = new ListNode(mn_val);
            cur = cur->next;
        }

        ans = ans->next;
        return ans;
    }
};
