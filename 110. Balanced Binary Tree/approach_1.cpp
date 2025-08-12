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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        dfs(root);
        return ans;
    }

private:
    bool ans = true;

    int dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }

        int left_dep = root->left == nullptr ? 0 : (1 + dfs(root->left));
        int right_dep = root->right == nullptr ? 0 : (1 + dfs(root->right));

        ans &= abs(left_dep - right_dep) <= 1;

        return max(left_dep, right_dep);
    }
};
