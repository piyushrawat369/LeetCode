// Dynamic Programming

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftLower(n);
        vector<int> rightLower(n);
        int ans = 0;

        for(int i=0; i<n; i++){
            int p = i-1;

            while(p >=0 && heights[p]  >= heights[i])
                p = leftLower[p];

            leftLower[i] = p;
        }

        for(int i=n-1; i>=0; i--){
            int p = i+1;

            while(p < n && heights[p]  >= heights[i])
                p = rightLower[p];
                
            rightLower[i] = p;
        }

        for(int i=0; i<n; i++){
            ans = max(ans, heights[i] * (rightLower[i] - leftLower[i] - 1));
        }

        return ans;
    }
};
