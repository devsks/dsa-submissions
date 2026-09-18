class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (vector<int>& edge : edges) {
            if (edge[0] == edge[1]) return false;

            graph[edge[0]].push_back(edge[1]);

            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> path;
        vector<int> parent(n, -1);

        path.push(0);
        parent[0] = 0;
        int count = 0;
        while (!path.empty()) {
            int u = path.front();
            path.pop();
            ++count;
            for (int v : graph[u]) {
                if (parent[v] + 1 && parent[u] != v) {
                    return false;
                }
                if (parent[v] + 1 && parent[u] == v) continue;
                path.push(v);
                parent[v] = u;
            }
        }
        return count == n;
    }
};
