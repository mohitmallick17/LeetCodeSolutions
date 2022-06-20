class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // push num to small initially
        small.push(num);
        
        // if max(small) <= min(large) is not maintained
        if(!small.empty() and !large.empty() and small.top() > large.top()){
            int del = small.top();
            small.pop();
            large.push(del);
        }
        
        // if small.size > large.size + 1
        if(small.size() > large.size() + 1){
            int del = small.top();
            small.pop();
            large.push(del);
        }
        
        // if large.size > small.size + 1
        if(large.size() > small.size() + 1){
            int del = large.top();
            large.pop();
            small.push(del);
        }
    }
    
    double findMedian() {
        if(small.size() > large.size())
            return small.top();
        else if(large.size() > small.size())
            return large.top();
        else
            return (small.top() + large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */