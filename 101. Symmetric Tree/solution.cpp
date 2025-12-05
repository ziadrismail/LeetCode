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
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }

private:
    bool dfs(TreeNode* p1, TreeNode* p2) {
        if (dead_end(p1, p2)) {
            return true;
        }

        if (!same(p1, p2)) {
            return false;
        }

        return dfs(p1->left, p2->right) && dfs(p1->right, p2->left);
    }

    bool dead_end(TreeNode* p1, TreeNode* p2) {
        return !p1 && !p2;
    }

    bool same(TreeNode* p1, TreeNode* p2) {
        if (!p1 || !p2) {
            return false;
        }
        return p1->val == p2->val;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
