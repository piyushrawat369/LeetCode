class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.length() == 0)
            return 0;
        
        if(needle.length() > haystack.length())
            return -1;
        
        //check if same string
        if(haystack.compare(needle) == 0)
            return 0;
        for(int i = 0; i < haystack.length(); i++){
            
            //get a substring from current index to the length of needle
            if(haystack.substr(i, needle.length()) == needle)
                return i;
        }
        return -1;
    }
};
