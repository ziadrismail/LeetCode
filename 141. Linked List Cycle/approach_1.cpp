/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        while (true) {
            if (head->next == nullptr) {
                return false;
            }

            if (head->next->val == MAX) {
                return true;
            }

            head->val = MAX;
            head = head->next;
        }

        return false;
    }

private:
    const int MAX = (int) 1e9;
};
