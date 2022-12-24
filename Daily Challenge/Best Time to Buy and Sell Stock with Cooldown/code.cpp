class Solution {
    private:
        vector<int> mem;

        int findmax(vector<int>& prices, int curr, int n){
            if(curr >= n)
                return 0;
            if(mem[curr] != -1)
                return mem[curr];
            
            int maxVal = 0;
            for(int i = curr+1; i<n; i++){
                if(prices[curr] < prices[i]){
                    maxVal = max(maxVal, prices[i] - prices[curr] + findmax(prices, i+2, n));
                }         
            }
            maxVal = max(maxVal, findmax(prices, curr+1, n));
            mem[curr] = maxVal;
            return maxVal;
        }
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            mem.resize(n+1, -1);
            return findmax(prices, 0, n);
        }
};
