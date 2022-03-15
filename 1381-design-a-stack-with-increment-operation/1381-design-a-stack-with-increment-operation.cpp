class CustomStack {
    vector<int> stk, inc;
    int size;
public:
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x){
        if(stk.size() == size)return;
        stk.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        int i = stk.size() - 1;
        if(i < 0)return -1;
        if(i > 0)
            inc[i-1] += inc[i];
        int val = inc.back() + stk.back();
        stk.pop_back();
        inc.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        int index = min(k-1, (int)stk.size()-1);
        if(index >= 0)
            inc[index] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */