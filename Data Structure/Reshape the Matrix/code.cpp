// Time Complexity: O(MN)
// Space Complexity: O(MN)


vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        if(row == 0){
            return mat;
        }
        
        int col = mat[0].size();
        if(col == 0){
            return mat;
        }
        
        int size1 = row*col;
        int size2 = r*c;
        if(size1 != size2){
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c,0));
        
        int k=0;
        int l=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[i][j] = mat[k][l];
                if(l == col-1){
                    k++;
                }
                l = (l+1)%col;
            }
        }
        return ans;
    }
