class Solution {
    private int INF = 1000001;
    int[][][] dp;
    
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        
        dp = new int[m][target+1][n+1];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<=target; j++){
                for(int k=0; k<=n; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        
        int ans = dfs(houses, cost, m, n, target, 0, 0, 0);
        return ans < INF ? ans : -1;
    }
    public int dfs(int[] houses, int[][] cost, int m, int n, int target, int i, int nbr, int left){
        if(i == m){
            return nbr == target? 0 : INF;
        }
        if(nbr > target){
            return INF;
        }
        if(dp[i][nbr][left] != -1){
            return dp[i][nbr][left];
        }
        
        if(houses[i] == 0){
            int minCost = INF;  
            for(int c=1; c<=n; c++){
                int new_nbr = nbr;
                if(c != left){
                    new_nbr = nbr + 1;
                }
                minCost = Math.min(minCost, cost[i][c-1] + dfs(houses, cost, m, n, target, i+1, new_nbr, c));
            }
            dp[i][nbr][left] = minCost;
            return dp[i][nbr][left];
        }
        else{
            int new_nbr = nbr;
            if(houses[i] != left){
                new_nbr = nbr + 1;
            }
            dp[i][nbr][left] = dfs(houses, cost, m, n, target, i+1, new_nbr, houses[i]);
            return dp[i][nbr][left];
        }
    }
}
