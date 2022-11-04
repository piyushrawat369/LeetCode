class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans;
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                ans = i;
                break;
            }
            else{
                ans = -1;
            }
        }
        return ans;
    }
};
