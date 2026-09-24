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
        queue<pair<TreeNode*,int>> path;
        if(root==nullptr)
            return data;
        path.push({root,1});
        while(!path.empty())
        {
            TreeNode* u = path.front().first;
            int level = path.front().second;
            path.pop();
            if(data.size() < level)
                data.push_back({});
            data[level-1].push_back(u->val);
            if(u->left)
            path.push({u->left,level+1});
            if(u->right)
            path.push({u->right,level+1});
        }


        return data;
        
    }
};
