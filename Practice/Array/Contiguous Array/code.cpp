class Solution {
public:
    int findMaxLength(vector<int> nums) {
        unordered_map<int, int> mp;
  
        int sum = 0, maxx = 0; 
        int n = nums.size();
        mp[0] = -1;

        for(int i=0; i<n; i++){
            sum += nums[i] == 0 ? -1: 1;

            if(mp.find(sum) != mp.end())
                maxx = max(maxx, i - mp[sum]);
            
            else
                mp[sum] = i;
            
        }
        return maxx;
    }
        
};


