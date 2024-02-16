class Solution {
public:

    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto a: arr)    mp[a]++;

        vector<int> v;
        for(auto a: mp){
            v.push_back(a.second);
        }
        sort(v.begin(), v.end());
        int ans = 0;

        for(int i=0; i<v.size(); i++){
            if(k > v[i]){
                k -= v[i];
                v[i] = 0;
            }
            else{
                v[i] -= k;
                k = 0;
            }
            if(v[i] != 0){
                ans++;
            }
        }
        return ans;
    }
};



