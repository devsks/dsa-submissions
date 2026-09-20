class Solution {
   public:
    void DFS(vector<int>& nums, int i, int rem, vector<int>& seq, vector<vector<int>>& res) {
        
        if (rem < 0  || i >= nums.size()) return;
        if (rem == 0) {
            res.push_back(seq);
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            if (nums[j] <= rem) {
                    seq.push_back(nums[j]);
                    DFS(nums, j,rem - nums[j], seq, res);
                    seq.pop_back();
                 
            } 
            else
                break;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        vector<int> seq;

        sort(nums.begin(), nums.end());
        DFS(nums, 0, target, seq, answer);

        return answer;
    }
};
