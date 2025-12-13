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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* left = head;
        ListNode* prev = dummy;

        while (left != nullptr) {
            int freq = 0;
            ListNode* right = left;
            while (right != nullptr && right->val == left->val) {
                freq++;
                right = right->next;
            }

            if (freq == 1) {
                prev = left;
            } else {
                prev->next = right;
            }
            left = right;
        } 

        return dummy->next;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
