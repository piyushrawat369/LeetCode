class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());   
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        for(int i=n-1; i>1; i--){
            if( nums[i] < sum - nums[i]){
                return sum;
            }
            else{
                sum -= nums[i];
            }
        }
        return -1;
    }
};
