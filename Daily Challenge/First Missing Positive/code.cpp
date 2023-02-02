class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for(int &it: nums){
            if(it > 0){
                st.insert(it);
            }
        }
        if(st.size() == 0)
            return 1;

        vector<int> v(st.begin(), st.end());

        sort(v.begin(), v.end());
 
        if(v[0] > 1)
            return 1;

        for(int i=0; i<v.size(); i++){
            if(v[i] != i+1){
                return i+1;
            }
        }
        
        return v.size()+1;
    }
};
