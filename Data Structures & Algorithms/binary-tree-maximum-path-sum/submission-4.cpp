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
    int maxPathSumHelper(int& ans, TreeNode* root) {
        if (root) {
            int leftMax = maxPathSumHelper(ans, root->left);
            int rightMax = maxPathSumHelper(ans, root->right);

            int curMax = max({root->val,leftMax + root->val, rightMax + root->val});
            ans = max(ans,curMax);
            ans = max({ans, leftMax + root->val,leftMax + root->val + rightMax,root->val + rightMax});
            return curMax;
        } else
            return 0;
    }
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        maxPathSumHelper(ans, root);
        return ans;
    }
};
