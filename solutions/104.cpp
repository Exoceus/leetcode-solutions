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
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return localDepth(root);
    }

    // blind
    int localDepth(TreeNode *curr)
    {
        if (curr)
        {
            return 1 + max(localDepth(curr->left), localDepth(curr->right));
        }
        return 0;
    }
};