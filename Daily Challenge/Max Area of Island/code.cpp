// Time Complexity: O(N * M) ___where N and M are the lengths of the sides of the grid
// Space Complexity: O(L) ___where L is the size of the largest island, representing the maximum recursion stack


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]) ans = max(ans, trav(grid, i, j));
            }
        }
        return ans;
    }

private: 
    int m,n;
    int trav(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || !grid[i][j])  
            return 0; 
        
        grid[i][j] = 0;
        return 1 + trav(grid, i-1, j) + trav(grid, i, j-1) + trav(grid, i+1, j)+ trav(grid, i, j+1);
    }
    
};
