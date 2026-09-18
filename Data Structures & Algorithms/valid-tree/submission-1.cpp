class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for(vector<int> &edge : edges)
        {
            if(edge[0]==edge[1])
                return false;

            graph[edge[0]].push_back(edge[1]);

            graph[edge[1]].push_back(edge[0]);
            indegree[edge[1]]++;
        }

        queue<int> path;
        vector<bool> seen(n,false);
        vector<int> parent(n,-1);

        path.push(0);
        parent[0]=0;
        seen[0] = true;
        while(!path.empty())
        {
            int u = path.front();
            path.pop();
            //cout<<"sasa"<<u<<endl;
            for(int v : graph[u])
            {
                if(seen[v] && parent[u]!=v)
                {
                    return false;
                }
                if(seen[v] && parent[u]==v)
                    continue;
                seen[v] = true;
                path.push(v);
                parent[v] = u;
            }

        }
        for(int i=0;i<n;++i)
            if(seen[i]==false)
                return false;
        return true;
    }
};
