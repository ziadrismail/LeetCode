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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector < vector < int > > ans;

        if (root == nullptr) {
            return ans;
        }

        queue < TreeNode* > q;
        q.push(root);

        while (!q.empty()) {
            int n = (int) q.size();
            vector < int > lvl;
            while (n--) {
                auto node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(lvl);
        }

        return ans;
    }
};
