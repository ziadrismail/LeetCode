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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }

        auto* l = head;
        auto* r = head->next;

        while (r != nullptr) {
            if (l->val == r->val) {
                r = r->next;
                continue;
            }

            l->next = r;
            l = r;
            r = r->next;
        }

        l->next = r;

        return head;
    }
};
