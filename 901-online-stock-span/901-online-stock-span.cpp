class StockSpanner {
    stack<pair<int, int>> stk;
    int n;
public:
    StockSpanner() {
        n=0;
    }
    
    int next(int price) {
        while(!stk.empty() and stk.top().first <= price)
            stk.pop();
        int res = (stk.empty()) ? n+1 : n - stk.top().second;
        stk.push({price, n++});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */