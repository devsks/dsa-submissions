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
    bool isValidBSTHelper(TreeNode* root, int low, int high)
    {
        if(root)
        {
            if(root->val <= low || root->val >= high)
                return false;
            else
            {
                return isValidBSTHelper(root->left,low,root->val) && isValidBSTHelper(root->right,root->val, high);
            }
        }
        else
            return true;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root,INT_MIN, INT_MAX);
        
    }
};
