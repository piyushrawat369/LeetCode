class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size()-1;
        string s = "";

        if(chars.size() == 1){
            return 1;
        }
        int cnt = 0;

        for(int i=1; i<chars.size(); i++){
            if(chars[i] == chars[i-1]){
                cnt++;
            }
            else{
                s += chars[i-1];
                if(cnt >= 1){
                   s += to_string(cnt+1);
                   cnt = 0; 
                }
            }
        }
        if(chars[n] == chars[n-1]){
            s += chars[n];
            s += to_string(cnt+1);
        }
        else{
            s += chars[n];
        }
        

        for(int i=0; i<s.length(); i++){
            chars[i] = s[i];
        }
        return s.size();
    }
};


