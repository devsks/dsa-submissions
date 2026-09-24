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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> data;
        queue<TreeNode*> path;
        if(root==nullptr)
            return data;
        path.push(root);

        while(!path.empty())
        {

            int count = path.size();
            vector<int> levelNodes;
            levelNodes.reserve(count);
            while(count--)
            {
                TreeNode* u = path.front();
                path.pop();
                levelNodes.push_back(u->val);
                if(u->left)
                    path.push(u->left);
                if(u->right)
                    path.push(u->right);
            }
            data.push_back(levelNodes);
        }


        return data;
        
    }
};
