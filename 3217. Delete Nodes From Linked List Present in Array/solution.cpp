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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* new_head = new ListNode();

        ListNode* dummy = new ListNode();
        dummy = new_head;

        unordered_set<int> num_set(nums.begin(), nums.end());
        while(head != nullptr) {
            if (num_set.count(head->val) == 0) {
                ListNode* new_node = new ListNode(head->val);
                new_head->next = new_node;
                new_head = new_head->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};

/*
    Time: O(n + m)
    Space: O(n)
*/
