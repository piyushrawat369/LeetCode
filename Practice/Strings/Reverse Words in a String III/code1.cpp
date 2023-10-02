class Solution {
public:
    string reverseWords(string s) {
        string a = "";
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                reverse(a.begin(), a.end());
                ans += a + " ";
                a = "";
            }
            else{
                a += s[i];
            }
        }
        reverse(a.begin(), a.end());
        ans += a;
        return ans;
    }
};
