class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAreaSoFar =0;
        int low =0, high = heights.size()-1;

        while(low < high)
        {
            int w = high-low;
            int currArea = min(heights[high],heights[low])*w;
            maxAreaSoFar = max(maxAreaSoFar, currArea);

            if(heights[high] < heights[low])
                --high;
            else
                ++low;
        }
        return maxAreaSoFar;   
    }
};
