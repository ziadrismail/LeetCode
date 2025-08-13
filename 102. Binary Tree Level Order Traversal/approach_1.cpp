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
        if (root == nullptr) {
            return {};
        }

        map < int, vector < int > > lvl_nodes;

        queue < pair < TreeNode*, int > > q;
        q.push({root, 0});

        while (!q.empty()) {
            auto node = q.front().first;
            auto lvl = q.front().second;
            q.pop();
            
            lvl_nodes[lvl].push_back(node->val);
            
            if (node->left != nullptr) {
                q.emplace(node->left, lvl + 1);
            }

            if (node->right != nullptr) {
                q.emplace(node->right, lvl + 1);
            }
        }

        vector < vector < int > > ans;
        for (auto &[lvl, nodes] : lvl_nodes) {
            ans.push_back(nodes);
        }

        return ans;
    }
};
