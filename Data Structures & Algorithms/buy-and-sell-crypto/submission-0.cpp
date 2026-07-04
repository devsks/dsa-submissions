class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int cur_min = INT_MAX, prof =0;
        for(int p : prices)
        {
            prof = max(prof, p-cur_min);
            if(p < cur_min)
            {
                cur_min=p;
            }
        }
     return prof;   
    }
};
