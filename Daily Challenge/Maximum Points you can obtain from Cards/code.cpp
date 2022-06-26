class Solution {
public:
    int maxScore(vector<int>& C, int k) {
        int total = 0;
        for(int i=0; i<k; i++){
            total += C[i];
        }
        int best = total;
        for(int i = k-1, j = C.size()-1 ; ~i; i--, j--){
            total += C[j] - C[i];
            best = max(total, best);
        }
        return best;
    }
};
