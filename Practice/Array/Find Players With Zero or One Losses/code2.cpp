class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> noloss;
        vector<int> oneloss;
        map<int,int> mpp;
        for(int i=0;i<matches.size();i++){
            mpp[matches[i][1]]++;
        }
        for(int i=0;i<matches.size();i++){
            if(mpp.find(matches[i][0]) == mpp.end()){
                mpp[matches[i][0]] = 0;
            }
            
        }
        for(auto it: mpp){
                if(it.second ==1){
                    oneloss.push_back(it.first);
                }
                if(it.second ==0){
                    noloss.push_back(it.first);
                }
            }
        return {noloss, oneloss};
    }
};
