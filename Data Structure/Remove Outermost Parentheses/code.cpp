class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int start = 0, stack = 1;
        for(int i=1; i<s.length(); i++){
            if(s[i] == '(')
                stack++;
            else
                stack--;

            if(stack == 0){
                res += s.substr(start+1, i-start-1);
                start = i+ 1;
            }
        }
        return res;
    }
};
