class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int len = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] != ' '){
                count++;
                len = count;
            }
            else{
                count = 0;
                if(len < count){
                    len = count;
                }
            }
        }
        return len;
    }
};
