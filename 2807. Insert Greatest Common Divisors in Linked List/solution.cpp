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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto* cur = head;
        auto* nxt = head->next;

        while (nxt != nullptr) {
            auto* g = new ListNode(gcd(cur->val, nxt->val), nxt);
            cur->next = g;
            cur = nxt;
            nxt = nxt->next;
        }

        return head;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
