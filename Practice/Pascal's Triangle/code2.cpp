class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0; i<numRows; i++){
            vector<int> rows(i+1, 1);
            int mid = i >> 1;
            for(int j=1; j<=mid; j++){
                int val = ans[i-1][j-1] + ans[i-1][j];
                rows[j] = val;
                rows[rows.size()-j-1] = val;
            }
            ans[i] = rows;
        }
        return ans;
    }
};
