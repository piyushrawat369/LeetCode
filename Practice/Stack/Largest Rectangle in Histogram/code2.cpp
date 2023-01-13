class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        heights.push_back(0);

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int curr = st.top();
                st.pop();

                ans = max(ans, heights[curr] * (st.empty()? i: i-1-st.top()));
            }
            st.push(i);
        }
        return ans;
    }
};
