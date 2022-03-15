class CustomStack {
    vector<int> stk;
    int size;
    int index;
public:
    CustomStack(int maxSize) {
        size=maxSize;
        stk.resize(size);
        index=0;
    }
    
    void push(int x){
        if(index==size)return;
        stk[index] = x;
        index++;
    }
    
    int pop() {
        if(index==0)return -1;
        index--;
        int val = stk[index];
        return val;
    }
    
    void increment(int k, int val) {
        for(int i=0;i < min(k, index);i++){
            stk[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */