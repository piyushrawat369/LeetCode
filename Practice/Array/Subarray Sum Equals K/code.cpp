class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        int currSum = 0;
        int i=0;
        map<int, int> mp;
        while(i<n){
            currSum += nums[i];
            if(currSum == k)
                cnt += 1;
            if(mp.find(currSum-k) != mp.end()){
                cnt += mp[currSum-k];
            }
            mp[currSum]++;
            i += 1;
        }
        return cnt;
    }
};
