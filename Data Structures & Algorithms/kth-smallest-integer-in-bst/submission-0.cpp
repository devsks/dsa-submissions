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
    int kthSmallestHelper(TreeNode* root, int &ind, int k)
    {
        if(root)
        {
            int answer = kthSmallestHelper(root->left,ind,k);
            if(answer !=-1)
                return answer;
            if(++ind == k)
            {
                return root->val;
            }
            answer = kthSmallestHelper(root->right, ind, k);
            return answer;

        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ind = 0;
        return kthSmallestHelper(root,ind,k);
    }
};
