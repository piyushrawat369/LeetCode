class Solution {
    private int INF = 1000001;
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        
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
        if(houses[i] == 0){
            int minCost = INF;  
            for(int c=1; c<=n; c++){
                int new_nbr = nbr;
                if(c != left){
                    new_nbr = nbr + 1;
                }
                minCost = Math.min(minCost, cost[i][c-1] + dfs(houses, cost, m, n, target, i+1, new_nbr, c));
            }
            return minCost;
        }
        else{
            int new_nbr = nbr;
            if(houses[i] != left){
                new_nbr = nbr + 1;
            }
            return dfs(houses, cost, m, n, target, i+1, new_nbr, houses[i]);
        }
    }
}
