bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(126);
        
        for(auto c: magazine)
            ++count[c];
        for(auto c: ransomNote)
            if(--count[c] < 0)
                return false;
        
        return true;
        
    }
