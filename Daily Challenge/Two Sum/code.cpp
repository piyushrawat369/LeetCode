class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a = nums.size();
        for(int i=0; i<a; i++){
            for(int j=i+1; j<a; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};
