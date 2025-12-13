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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* r = head;
        for (int i = 0; i < n - 1; ++i) {
            r = r->next;
        }

        ListNode* l = head;
        ListNode* prev = nullptr;
        while (r->next != nullptr) {
            r = r->next;
            prev = l;
            l = l->next;
        }

        if (!prev) { // remove head
            head = head->next;
        } else {
            prev->next = l->next;
        }

        return head;
    }
};

/*
    Time: O(sz)
    Space: O(1)
*/
