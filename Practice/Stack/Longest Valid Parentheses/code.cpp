class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack = {-1};
        int ans = 0;

        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                stack.push_back(i);
            else if(stack.size() == 1) 
                stack[0] = i;
            else{
                stack.pop_back();
                ans = max(ans, i - stack.back());
            }
        }
        return ans;
    }
};
