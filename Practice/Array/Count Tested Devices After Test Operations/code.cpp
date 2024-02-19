class Solution {
public:
    int countTestedDevices(vector<int>& b) {
        int n = b.size();
        int res = 0;
        for(int i=0; i<n; i++){
            if(b[i] - res > 0){
                res++;
            }
        }
        return res;
    }
};
