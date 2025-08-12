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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        return dfs(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool dfs(TreeNode* root, TreeNode* sub) {
        if (root == nullptr && sub == nullptr) {
            return true;
        }

        if (root != nullptr && sub != nullptr && root->val == sub->val) {
            return dfs(root->left, sub->left) && dfs(root->right, sub->right);
        }

        return false;
    }
};
