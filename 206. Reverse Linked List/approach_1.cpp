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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev_node = nullptr;
        ListNode* cur_node = head;

        while (cur_node != nullptr) {
            ListNode* nxt_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = nxt_node;
        }

        head = prev_node;
        return head;
    }
};
