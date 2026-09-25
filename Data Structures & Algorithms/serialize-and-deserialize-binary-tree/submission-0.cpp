/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelper(TreeNode* node, string& output) {

        if (output.length() > 0)
            output += ",";
        if (node) {
            output.append(to_string(node->val));
            serializeHelper(node->left, output);
            serializeHelper(node->right, output);

        } else {
            output += "#";
        }
    }
    string serialize(TreeNode* root) {
        string output = "";
        serializeHelper(root, output);
        //cout<<output<<endl;
        return output;
    }
    
    void buildTree(stringstream &ss,TreeNode* &root)
    {
        string word;
        if(ss && getline(ss,word,','))
        {
            if(word!="#")
            {
                root = new TreeNode(stoi(word));
                buildTree(ss,root->left);
                buildTree(ss,root->right);
            }
            
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    { 
       stringstream ss(data);
       // cout<<ss.good()<<" "<<ss.gcount();
        TreeNode* root= nullptr;
        buildTree(ss,root);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));