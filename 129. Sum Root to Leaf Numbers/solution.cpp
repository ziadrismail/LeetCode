/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

private:
    int ans = 0;

    void dfs(TreeNode* root, int num) {
        if (!root) {
            return;
        }

        int new_num = num * 10 + root->val;
        
        if (is_leaf(root)) {
            ans += new_num;
            return;
        }

        dfs(root->left, new_num);
        dfs(root->right, new_num);
    }

    bool is_leaf(TreeNode* node) {
        return !node->left && !node->right;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
