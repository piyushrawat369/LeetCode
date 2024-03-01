class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1')
                cnt++;
        }
        sort(s.begin(), s.end(), greater<char>());

        cnt -= 1;

        if(cnt >= 0){
            char temp = s[n-1];
            s[n-1] = s[cnt];
            s[cnt] = temp;
        }

        return s;
    }
};
