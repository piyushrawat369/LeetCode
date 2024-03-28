class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mp;
        int ans = 0;

        for(int left=0, right=0; right<nums.size(); right++){
            mp[nums[right]]++;

            if(mp[nums[right]] > k){
                while(nums[left] != nums[right]){
                    mp[nums[left]]--;
                    left++;
                }
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans, 1 + right - left);
        }
        return ans;
    }
};
