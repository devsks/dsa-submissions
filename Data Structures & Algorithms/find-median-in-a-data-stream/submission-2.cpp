class MedianFinder {
public:
    priority_queue<int,vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty())
            maxHeap.push(num);
        else if(minHeap.empty())
        {
            if(num <= maxHeap.top())
                maxHeap.push(num);
            else
                minHeap.push(num);
        }
        else
        {
            if(num <= minHeap.top())
                maxHeap.push(num);
            else if(num >= minHeap.top())
                minHeap.push(num);
            
        }
        int maxLen = maxHeap.size();
        int minLen = minHeap.size();

        cout<<maxLen<<" "<<0.0/2.0<<endl;

        if(minLen > maxLen+1)
        {
            int aux = minHeap.top();
            minHeap.pop();
            maxHeap.push(aux);
        }
        else if(maxLen > minLen+1)
        {
            int aux = maxHeap.top();
            maxHeap.pop();
            minHeap.push(aux);

        }
        
    }
    
    double findMedian() {
        int maxLen = maxHeap.size();
        int minLen = minHeap.size();
        if(minLen == maxLen)
        {
            return ((double)minHeap.top() + (double)maxHeap.top())/2.0;
        }
        else
        {
            if(minLen > maxLen)
                return (double)minHeap.top();
            else
                return (double)maxHeap.top();
        }
    }
};
/*
1 3 5 2 4 7 6 9 10

min -> [5,6,7,9,10]
max -> [1,2,3,4]
*/