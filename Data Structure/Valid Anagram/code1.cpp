bool isAnagram(string s, string t) {
        vector<int> a(126);
        for(auto c: s)  a[c]++;
        for(auto c: t)  a[c]--;
        
        for(int i=0; i<a.size(); i++){
            if(a[i] < 0 || a[i] > 0){
                return false;
            }
        }
        return true;
    }
