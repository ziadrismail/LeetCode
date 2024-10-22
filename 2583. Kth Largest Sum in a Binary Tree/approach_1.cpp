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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Call dfs function to fill up levelSum hashmap
        dfs(root, 1);

        if ((int) levelSum.size() < k)
            return -1;

        // Sort values in levelSum then return kth largest
        vector < long long > sortedLevelSum;
        for (auto &[key, val] : levelSum)
            sortedLevelSum.push_back(val);

        // Sort the vector descendingly
        sort(sortedLevelSum.rbegin(), sortedLevelSum.rend());

        // return (k - 1)-th because of 0-based indexing
        return sortedLevelSum[k - 1];
    }

private:
    unordered_map < int, long long > levelSum;

    void dfs(TreeNode* node, int level) {
        // Update the level sum
        levelSum[level] += node->val;

        // Go left if possible, depth will be incremented
        if (node->left != nullptr)
            dfs(node->left, level + 1);
        
        // Go right if possible, depth will also be incremented
        if (node->right != nullptr)
            dfs(node->right, level + 1);
    }
};

/*
    Time: O(n + nlog(n))
    Space: O(n)
*/
