class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyd = 0;
        int selld = 1;
        int profit = 0, maxp = 0;
        while(selld < prices.size()) {
            profit = prices[selld] - prices[buyd];
            if(profit > 0 ) {
                maxp = max(profit, maxp);
            } else {
                buyd = selld;
            }
            selld++;
        }
        return maxp;
    }
};
