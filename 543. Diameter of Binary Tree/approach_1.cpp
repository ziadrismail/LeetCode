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
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return global_ans;
    }

private:
    int global_ans = 0;

    int dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }

        int left_dep = root->left != nullptr ? (1 + dfs(root->left)) : 0;
        int right_dep = root->right != nullptr ? (1 + dfs(root->right)) : 0;

        global_ans = max(global_ans, left_dep + right_dep);

        return max(left_dep, right_dep);
    }
};
