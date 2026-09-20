class Solution {
public:
    void BFS(vector<vector<char>>& grid, int i, int j)
    {
        queue<vector<int>> path;
        vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        path.push({i,j});
        grid[i][j] = 'I';
        int n = grid.size(), m = grid[0].size();
        while(!path.empty())
        {

            int i = path.front()[0], j = path.front()[1];
            path.pop();
            for(auto &dir: dirs)
            {
                int ni = i+dir[0], nj = j+dir[1];
                if(ni < 0 || nj < 0 || ni >=n || nj >=m || grid[ni][nj]!='1')
                    continue;
                path.push({ni,nj});
                grid[ni][nj] = 'I';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    BFS(grid,i,j);
                }
            }
        }
        return count;
    }
};
