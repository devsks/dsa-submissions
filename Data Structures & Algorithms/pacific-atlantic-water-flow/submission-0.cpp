class Solution {
public:
    void BFS(queue<vector<int>> &path,vector<vector<int>>& heights, vector<vector<bool>> &ocean)
    {   
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!path.empty())    
        {
            vector<int> u = path.front();
            path.pop();
            for(auto &dir : dirs)
            {
                int ni = u[0] + dir[0], nj = u[1]+dir[1];
                if(ni < 0 
                || nj < 0 
                || ni >=n 
                || nj >=m 
                || ocean[ni][nj]
                || heights[ni][nj] < heights[u[0]][u[1]])
                    continue;
                path.push({ni,nj});
                ocean[ni][nj] = true;

            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m)),atlantic(n, vector<bool>(m));
        
        queue<vector<int>> path;
        vector<vector<int>> res;
        
        // focus on pacific first
        for(int i=0;i<n;++i)
        {
            path.push({i,0});
            pacific[i][0] = true;
        }
        for(int j=0;j<m;++j)
        {
            path.push({0,j});
            pacific[0][j] = true;
        }

        
        BFS(path, heights, pacific);

        // focus on atlantic
        for(int i=0;i<n;++i)
        {
            path.push({i, m-1});
            atlantic[i][m-1] = true;
        }
        
        for(int j=0;j<m;++j)
        {
            path.push({n-1, j});
            atlantic[n-1][j] = true;
        }
        
        BFS(path, heights,atlantic);
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
            }
        }

        return res;

    }
};
