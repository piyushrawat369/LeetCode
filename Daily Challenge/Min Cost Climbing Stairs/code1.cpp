// Time Complexity: O(N) 
// Space Complexity: O(1)

int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        for(int i=n-2; i>=0; i--){
            cost[i] += min(cost[i+1], cost[i+2]);
        }
        return min(cost[1], cost[0]);
  }
