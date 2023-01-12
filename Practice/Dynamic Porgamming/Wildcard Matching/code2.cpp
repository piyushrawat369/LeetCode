//recursion + memorization
//Runtime: 68 ms, faster than 58.99% of C++ online submissions for Wildcard Matching.
//Memory Usage: 28 MB, less than 11.54% of C++ online submissions for Wildcard Matching.
class Solution {
public:
    vector<vector<int>> memo;
    string s, p;
    
    bool isMatch(int i, int j){
        //p empty
        if(j == p.size()) return i == s.size();
        
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        bool first_match = (i < s.size()) && (p[j] == s[i] || p[j] == '?' || p[j] == '*');
        
        if(p[j] == '*'){
            memo[i][j] = (first_match && isMatch(i+1, j)) || isMatch(i, j+1);
        }else{
            memo[i][j] = first_match && isMatch(i+1, j+1);
        }
        
        return memo[i][j];
    }
    
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        int m = s.size(), n = p.size();
        memo = vector<vector<int>>(m+1, vector(n+1, -1));
        
        return isMatch(0, 0);
    }
};
