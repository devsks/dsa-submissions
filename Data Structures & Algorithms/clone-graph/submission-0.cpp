/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void cloneHelper(Node* clone, Node * org,unordered_set<int> &visited,
    unordered_map<int,Node*> &hMap)
    {
        if(visited.count(org->val) > 0)
            return;
        //cout<<org->val<<" ";
        visited.insert(org->val);
        clone->val = org->val;
        hMap[clone->val] = clone;


        for(Node* v : org->neighbors)
        {
            Node* found = hMap[v->val];
            if(found == nullptr)
            {
                found = new Node(v->val);
                //cout<<v->val<<"dsds";
                hMap[v->val] = found;
            }

            clone->neighbors.push_back(found);
            
            cloneHelper(found,v, visited,hMap);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        unordered_set<int> visited;
        unordered_map<int,Node*> hMap;
        Node* cloned = new Node();
        cloneHelper(cloned,node, visited,hMap);
        return cloned;
        
    }
};
