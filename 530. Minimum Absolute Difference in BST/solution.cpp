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
private:
    int res = INT_MAX;
    TreeNode* prev = nullptr;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }

        dfs(root->left);

        if (prev != nullptr) {
            res = min(res, root->val - prev->val);
        }
        prev = root;

        dfs(root->right);

    }

public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return res;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
