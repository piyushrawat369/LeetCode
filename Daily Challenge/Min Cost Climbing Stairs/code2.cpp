// Time Complexity: O(N)
// Space Complexity: O(N)


int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> result(n+1, 0);
        for(int i=2; i<=n; i++){
            result[i] = min(result[i-1] + cost[i-1], result[i-2] + cost[i-2]);
        }
        return result[n];
}
