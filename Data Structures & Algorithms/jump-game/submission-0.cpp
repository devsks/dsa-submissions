class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n);
        queue<int> path;
        path.push(0);
        vis[0] = true;
        while(!path.empty())
        {

            int u = path.front();
            path.pop();

            for(int v=1; v <= nums[u] && v+u < n; ++v)
            {
                if(!vis[u+v])
                {
                    vis[u+v] = true;   
                    path.push(u+v);
                }
            }
        }
        return vis[n-1];
    }
};
