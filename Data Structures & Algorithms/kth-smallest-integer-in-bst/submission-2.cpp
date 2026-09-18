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
  
    int kthSmallest(TreeNode* root, int &k) {
        if(root)
        {
            int answer = kthSmallest(root->left, k);
            if(answer + 1)
                return answer;
            if(0 == --k)
                return root->val;
            return kthSmallest(root->right, k);
        }
        return -1;
    }
};
