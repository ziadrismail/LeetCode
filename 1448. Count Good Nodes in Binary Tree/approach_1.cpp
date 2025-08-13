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
    int goodNodes(TreeNode* root) {
        return dfs(root);   
    }

private:
    int dfs(TreeNode* root, int max_val = INT_MIN) {
        if (!root) {
            return 0;
        }
        
        bool good = root->val >= max_val;
        int new_max = max(max_val, root->val);

        return dfs(root->left, new_max) + dfs(root->right, new_max) + good;
    }
};
