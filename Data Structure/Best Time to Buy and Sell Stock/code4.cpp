int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxFromTail = 0;
        int profit = 0, maxProfit = 0;
        for(int i = n-1; i >= 0; i--){
            maxFromTail = max(maxFromTail, prices[i]);
            profit = max(maxFromTail - prices[i], 0);
            maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
