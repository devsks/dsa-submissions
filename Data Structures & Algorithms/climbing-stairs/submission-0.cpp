class Solution {
public:
    int climbStairs(int n) {
        int n_1=1,n_2=0;
        
        for(int i=1;i<n;++i)
        {
            int temp =  n_1+n_2;
            n_2 = n_1;
            n_1 = temp;
        }
        return n_1+n_2;
    }
};
