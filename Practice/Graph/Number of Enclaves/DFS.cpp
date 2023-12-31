class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int r[], int c[]){
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<4; i++){
            int nrow = row + r[i];
            int ncol = col + c[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis, r, c);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int r[] = {-1, 0, +1, 0};
        int c[] = {0, -1, 0, +1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<m; i++){
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(0, i, grid, vis, r, c);
            }
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                dfs(n-1, i, grid, vis, r, c);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, grid, vis, r, c);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i, m-1, grid, vis, r, c);
            }
        }

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};
