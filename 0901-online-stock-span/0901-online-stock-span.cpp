class StockSpanner {
    stack<pair<int, int>> stk;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int pts = 1;
        while(!stk.empty() && stk.top().first <= price){
            pts += stk.top().second;
            stk.pop();
        }
        stk.push({price, pts});
        return pts;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */