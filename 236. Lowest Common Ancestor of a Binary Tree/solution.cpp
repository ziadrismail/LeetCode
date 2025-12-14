/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* res = nullptr;
    
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return 0;
        }

        int ret = root->val == p->val || root->val == q->val;
        
        ret += dfs(root->left, p, q);
        ret += dfs(root->right, p, q);

        if (ret == 2) {
            if (!res) {
                res = root;
            }
            
        }

        return ret;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
