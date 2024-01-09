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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        return creatingSeqList(root1, root2);
    }

    // blind
    bool creatingSeqList(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr1;
        getLeafSequence(arr1, root1);

        vector<int> arr2;
        getLeafSequence(arr2, root2);

        if (arr1.size() != arr2.size())
        {
            return false;
        }

        for (int i = 0; i < arr1.size(); ++i)
        {
            if (arr1[i] != arr2[i])
            {
                return false;
            }
        }

        return true;
    }

    void getLeafSequence(vector<int> &arr, TreeNode *root)
    {
        // doesn't create new vector, just adds items to the given vector
        // more space efficient
        if (!root->left && !root->right)
        {
            // if leaf
            arr.push_back(root->val);
        }
        else
        {
            if (root->left)
            {
                getLeafSequence(arr, root->left);
            }
            if (root->right)
            {
                getLeafSequence(arr, root->right);
            }
        }
    }
};