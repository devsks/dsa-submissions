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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q)
        {
            if(p->val == q->val)
            {
                bool leftMatch = isSameTree(p->left,q->left);
                if(leftMatch)
                    return isSameTree(p->right,q->right);
            }
            return false;
        }
        return (p == nullptr && q == nullptr);
    }
};
