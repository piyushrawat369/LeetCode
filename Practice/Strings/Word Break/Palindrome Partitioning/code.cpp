class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string s){
        int l = 0, r = s.length()-1;
        while(l<r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    void recurse(int i, string s, string curr, vector<string> &now){
        if(i == s.length()){
            if(curr.empty()){
                ans.push_back(now);
            }
            return;
        }
        curr.push_back(s[i]);
        if(isPal(curr)){
            now.push_back(curr);
            recurse(i+1, s, "", now);
            now.pop_back();
        }
        recurse(i+1, s, curr, now);
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        recurse(0, s, "", curr);
        return ans;
    }
};
