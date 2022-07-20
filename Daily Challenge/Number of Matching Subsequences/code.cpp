class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int total = 0, k = s.size();
        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        for(auto st: m){
            int index1 = 0, index2 = 0;
            string p = st.first;
            int n = p.size();
            while(index1 < k && index2 < n){
                if(s[index1] == p[index2]){
                    index1++;
                    index2++;
                }
                else{
                    index1++;
                }
            }
            if(index2 == n){
                total += st.second;
            }
        }
        return total;
    }
};
