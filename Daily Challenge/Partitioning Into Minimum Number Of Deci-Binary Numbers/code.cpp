class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        int ans;
        for(int i=0; i<n.length(); i++){
            if(n[i] > max){
                max = n[i];
            }
            
        }
        ans = max - 48;
        return ans;
    }
};
