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

        if(cnt > 0){
            s.erase(0,1);
            s += '1';
        }

        return s;
    }
};
