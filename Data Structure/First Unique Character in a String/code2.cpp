int firstUniqChar(string s) {
        vector<int> debut(26, -1);
        for(int i = 0; i < s.size(); i++) {
          if(debut[s[i] - 'a'] >= 0) {
            debut[s[i] - 'a'] = -2;
          }
          else if(debut[s[i] - 'a'] == -1) {
            debut[s[i] - 'a'] = i;
          }
        }
        int res = INT_MAX;
        for(int i = 0; i < 26; i++) {
          if(debut[i] >= 0) {
            res = min(res, debut[i]);
          }
        }
        return res == INT_MAX ? -1 : res;
   }
