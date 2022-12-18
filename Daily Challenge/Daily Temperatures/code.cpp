class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int a = t.size();
        vector<int> ans(a);
        stack<int> st;
        for(int i = a-1; i >= 0; i--){
            while(!st.empty() && t[st.top()] <= t[i]){
                st.pop();
            }
            ans[i] = st.empty()? 0: st.top()-i;
            st.push(i);
        }
        return ans;
    }
};
