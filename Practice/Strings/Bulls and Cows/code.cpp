class Solution {
public:
    string getHint(string secret, string guess) {
        map<int, int> mp1;
        map<int, int> mp2;
        int bull = 0, cow = 0;
        string ans = "";

        for(int i=0; i<secret.length(); i++){
            if(secret[i] == guess[i]){
                bull++;
                continue;
            }

            mp1[secret[i]]++;
            mp2[guess[i]]++;
        }

        for(auto it: mp1){
            if(mp2.count(it.first)){
                int cnt = min(it.second, mp2[it.first]);
                cow += cnt;
            }
                
        }

        ans = ans + to_string(bull) + 'A' + to_string(cow) + 'B';
        return ans;
    }
};
