class Solution {
public:
    int firstUniqChar(string s) {
        map<int,int> r;
        int n = s.size();
        for(int i=0; i<n; i++){
            r[s[i]]++;
        }
        for(int i=0; i<n; i++){
            if(r[s[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};
