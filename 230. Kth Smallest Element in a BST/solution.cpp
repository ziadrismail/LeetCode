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
    int current = 0, res;

    void dfs(TreeNode* root, int k) {
        if (!root) {
            return;
        }

        dfs(root->left, k);

        current++;
        if (current == k) {
            res = root->val;
        }

        dfs(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
