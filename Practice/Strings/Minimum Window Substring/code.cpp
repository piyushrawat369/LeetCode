class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length() < t.length())
            return "";

        int end = 0, start = 0, startIndex = 0, minLen = INT_MAX;
        vector<int> mp(128, 0);
        int count = t.length();

        for(auto it: t){
            mp[it]++;
        }
        while(end < s.length()){
            if(mp[s[end++]]-- > 0){
                count--;
            }
            while(count == 0){
                if(end - start < minLen){
                    startIndex = start;
                    minLen = end - start;
                }
                
                if(mp[s[start++]]++ == 0){
                    count++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen); 
    }
};
