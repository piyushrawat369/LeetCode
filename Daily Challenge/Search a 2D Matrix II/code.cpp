class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), i = 0, j = matrix[0].size()-1;
        while(i < n && ~j){
            int cell = matrix[i][j];
            if(cell == target) return true;
            else if(cell > target) j--;
            else i++; 
        }
        return false;
    }
};
