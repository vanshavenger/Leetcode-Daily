class StockSpanner {
public:
    stack<pair<int,int>> stk;
    int i;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        while(!stk.empty() && stk.top().first <= price){
            stk.pop();
        }
        if(stk.empty()){
            stk.push({price,i});
            i++;
            return i;
        } 
        int ans = i - stk.top().second;
        stk.push({price,i});
        i++;
        
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
