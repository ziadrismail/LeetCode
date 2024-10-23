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
    TreeNode* replaceValueInTree(TreeNode* root) {
        preComputeDepthSum(root);
        updateTree(root, depthValSum[0]);
        return root;
    }

private:
    const static int MAX_DEPTH = (int) 1e5;
    int depthValSum[MAX_DEPTH];

    void preComputeDepthSum(TreeNode* node, int depth = 0) {
        // Add the current node's value
        depthValSum[depth] += node->val;

        // Recursively do the same to both right and left children
        if (node->left != nullptr)
            preComputeDepthSum(node->left, depth + 1);
        if (node->right != nullptr)
            preComputeDepthSum(node->right, depth + 1);
    }

    void updateTree(TreeNode *node, int siblingValSum, int depth = 0) {
        // Update the current node
        int newVal = depthValSum[depth] - siblingValSum;
        node->val = newVal;

        // Calculate siblings' sum
        int childrenValSum = computeSiblingSum(node);

        // Recursively update other nodes
        if (node->left != nullptr)
            updateTree(node->left, childrenValSum, depth + 1);
        if (node->right != nullptr)
            updateTree(node->right, childrenValSum, depth + 1);
    }

    int computeSiblingSum(TreeNode* node) {
        int childrenValSum = 0;
        childrenValSum += node->left == nullptr ? 0 : node->left->val;
        childrenValSum += node->right == nullptr ? 0 : node->right->val;
        return childrenValSum;
    }
};

/*
    Time: O(n)
    Space: O(MAX_DEPTH)
*/
