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
    TreeNode * buildTreeHelper(int low, int high, int &index, vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode* node = nullptr;
        if(low < high)
        {
            node = new TreeNode(preorder[index++]);
            int ind = find(inorder.begin()+low, inorder.begin()+high, node->val) - inorder.begin();

            if(ind > low)
            {
                node->left = buildTreeHelper(low,ind,index,preorder,inorder);
            }
            if(ind < high-1)
                node->right = buildTreeHelper(ind+1,high,index,preorder, inorder);
        }

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * root = nullptr;
        if(preorder.size())
        {
            int temp = 0;
            root = buildTreeHelper(0,inorder.size(),temp,preorder, inorder);
        }
        return root;
    }
};
