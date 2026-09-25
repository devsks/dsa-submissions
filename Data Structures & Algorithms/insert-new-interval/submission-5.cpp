class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0)
            return {newInterval};
        vector<vector<int>> res;
        int i=0, n = intervals.size();
        for(;i<n;++i)
        {
            if(intervals[i][1] < newInterval[0])
                res.push_back(intervals[i]);
            else
            break;
        }
        if(i<n)
        {
            if(intervals[i][0] <= newInterval[1])
            {
                intervals[i][0] = min(intervals[i][0], newInterval[0]);
                intervals[i][1] = max(intervals[i][1], newInterval[1]);
                res.push_back(intervals[i++]);
            }
            else
                res.push_back(newInterval);
            int ind = res.size();
            for(;i<n;++i)
            {
                int cur_end = res[ind-1][1];
                if(intervals[i][0]<= cur_end)
                {
                    cur_end = res[ind-1][1] = max(cur_end, intervals[i][1]);
                }
                else
                {
                    cur_end = intervals[i][1];
                    res.push_back(intervals[i]);
                    ++ind;
                }

            }
            
        }
        else
            res.push_back(newInterval);

        return res;
    }
};
