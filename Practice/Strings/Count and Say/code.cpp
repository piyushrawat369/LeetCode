class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string prev = countAndSay(n-1);
        string ans;

        int len = prev.length();
        for(int i=0; i<len;){
            int j = i;
            int count = 0;

            while(prev[i] == prev[j] && j < len){
                count++;
                j++;
            }
            char c = '0'+count;
            ans += c;
            ans += prev[i];
            i = j;
        }
        return ans;
    }
};
