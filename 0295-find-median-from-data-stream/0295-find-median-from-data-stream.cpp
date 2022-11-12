class MedianFinder {
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int minhTop = minH.empty() ? INT_MAX : minH.top();
        int maxhTop = maxH.empty() ? INT_MIN : maxH.top();
        
        if(num <= minhTop)
            maxH.push(num);
        else
            minH.push(num);
        
        if(abs((int)maxH.size() - (int)minH.size()) > 1){
            if(maxH.size() > minH.size()){
                minH.push(maxH.top());
                maxH.pop();
            }else{
                maxH.push(minH.top());
                minH.pop();
            }
        }
        
    }
    
    double findMedian() {
        int size = minH.size() + maxH.size();
        if(size & 1){
            
            if(maxH.size() > minH.size()){
                return maxH.top();
            }else{
                return minH.top();
            }
        }
        return (maxH.top() + minH.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */