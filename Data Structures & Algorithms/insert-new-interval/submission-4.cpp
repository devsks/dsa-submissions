class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0)
            return {newInterval};

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int cur_end = intervals[0][1], ind = 0;
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i][0] <= cur_end)
            {
                cur_end = res[ind][1] = max(cur_end,intervals[i][1]);
            }
            else
            {
                cur_end = intervals[i][1];
                res.push_back(intervals[i]);
                ++ind;
            }
        }
        return res;
    }
};
