class Solution {
public:
    void DFS(int node, int parent, vector<vector<int>> &adjList, vector<bool> & visited)
    {
        visited[node] = true;
        for(int child : adjList[node])
        {
            if(child!=parent && !visited[child])
            {
                DFS(child,node,adjList,visited);
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        int components =0;
        vector<vector<int>> adjList(n);
        vector<bool> visited(n);
        for(auto &edge : edges)
        {
            int u = edge[0],v = edge[1];
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }

        for(int u =0;u<n;++u)
        {
            if(!visited[u])
            {
                ++components;
                DFS(u,-1,adjList,visited);
            }
        }
        return components;
    }
};
