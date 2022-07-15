bool canConstruct(string ransomNote, string magazine) {
        int r[26] = {0};
        int m[26] = {0};
        for(auto i: ransomNote) r[i - 'a']++;
        for(auto j: magazine) m[j - 'a']++;
        
        for(int i=0; i<26; i++)
            if(r[i] > m[i]) return false;
       
        return true;
    }
