// Time limit Exceeded

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            if(i+1 < n && heights[i+1] >= heights[i]){
                continue;
            }
            int minH = INT_MAX;

            for(int j=i; j>=0; j--){
                minH = min(minH, heights[j]);
                ans = max(ans, minH * (i-j+1));
            }
        }
        
        return ans;
    }
};
