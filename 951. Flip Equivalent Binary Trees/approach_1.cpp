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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }   
private:
    bool dfs(TreeNode* node1, TreeNode* node2) {
        // Two null subtrees are equivalent
        if (node1 == nullptr && node2 == nullptr)
            return true;
        
        // If one of them null, it's impossible to make them equivalent 
        if (node1 == nullptr || node2 == nullptr)
            return false;
        
        // Two values must be equal
        if (node1->val != node2->val)
            return false;

        // Try both options
        return dfs(node1->left, node2->left) && dfs(node1->right, node2->right) ||
               dfs(node1->left, node2->right) && dfs(node1->right, node2->left);
    }    
};

/*
    Time: O(n)
    Space: O(1)
*/
