class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        for(int i=0, j=0; i<s.size(), j<t.size(); i++, j++){
            m1[s[i]]++;
            m2[t[j]]++;
        }

        int ans = 0;

        for(auto it: m1){
            int freq = it.second;
            int num = it.first;

            if(!m2.count(num)){
                ans += freq;
            }
            else if(m2.count(num) && freq > m2[num]){
                freq -= m2[num];
                ans += freq;
            }
            else{
                continue;
            }
        }
        return ans;
    }
};
