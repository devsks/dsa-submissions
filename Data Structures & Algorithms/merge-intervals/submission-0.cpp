class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](vector<int>&a, vector<int>&b)
        {
        return a[0]==b[0] ? a[1] > b[1] : a[0] < b[0];
        });   
        vector<vector<int>> res;
        int index=0, cur_end =0;
        res.push_back(intervals[0]);
        cur_end = intervals[0][1];
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i][0] > cur_end)
            {
                res.push_back(intervals[i]);
                cur_end = intervals[i][1];
                ++index;
            }
            else
            {
                cur_end = res[index][1] = max(intervals[i][1],cur_end);
            }
        }
        return res;
    }
};
