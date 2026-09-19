class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);

        vector<vector<int>> graph(numCourses);
        for(auto p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]+=1;
        }
        queue<int> path;
        for(int i=0;i<numCourses;++i)
            if(indegree[i]==0)
            {
                path.push(i);
                indegree[i] =-1;
            }
        int count =0 ;
        while(!path.empty())
        {   
            int u = path.front();
            path.pop();
            ++count;
            for(int v : graph[u])
            {
                if(--indegree[v]== 0)
                {
                    path.push(v);
                    indegree[v] = -1;
                }
            }
        }
        return count == numCourses;

    }
};
