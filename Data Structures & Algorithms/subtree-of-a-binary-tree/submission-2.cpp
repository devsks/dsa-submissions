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
   bool isMatch(TreeNode *ptr1, TreeNode * ptr2)
   {
        if(ptr1 && ptr2)
        {
            if(ptr1->val ==ptr2->val)
                return isMatch(ptr1->left,ptr2->left) && isMatch(ptr1->right, ptr2->right);
            else
                return false;
        }
        else if(ptr1 || ptr2)
            return false;

        return true;
   }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool res = false;

        if (root && subRoot) {
            if (root->val == subRoot->val) {
                res = isMatch(root, subRoot);
            }
            if (!res) res = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            
        } else if (subRoot == nullptr && root == nullptr)
            res = true;

        return res;
    }
};
