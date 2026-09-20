class Solution {
   public:
    void DFS(vector<int>& nums, int i, int rem, vector<int>& seq, set<vector<int>>& res) {
        
        if (rem == 0) {
            vector<int> temp = seq;
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        if (rem < 0  || i >= nums.size()) return;

        for (int j = i; j < nums.size(); ++j) {
            if (nums[j] <= rem) {
                
                    seq.push_back(nums[j]);
                    DFS(nums, j,rem - nums[j], seq, res);
                    seq.pop_back();
                 
            } else
                break;
        }

        DFS(nums, i+1,rem, seq, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        vector<int> seq;
        DFS(nums, 0,target, seq, res);

        for (auto it : res) {
            answer.push_back(it);
        }
        return answer;
    }
};
