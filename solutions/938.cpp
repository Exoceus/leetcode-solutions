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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        // simple tree traversal (depth first)
        return naive(root, low, high);
    }

    // blind
    int naive(TreeNode *root, int low, int high)
    {
        int left = 0;
        int right = 0;

        if (root->left)
        {
            left = naive(root->left, low, high);
        }

        if (root->right)
        {
            right = naive(root->right, low, high);
        }

        if (root->val >= low && root->val <= high)
        {
            return left + right + root->val;
        }
        else
        {
            return left + right;
        }
    }
};