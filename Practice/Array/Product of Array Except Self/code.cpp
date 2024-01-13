class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftNums(n, 1);
        vector<int> rightNums(n, 1);
        
        int leftPro = 1;
        int rightPro = 1;

        for(int i=0; i<n; i++){
            leftNums[i] = leftPro;
            leftPro *= nums[i];
        }
        for(int i=n-1; i>=0; i--){
            rightNums[i] = rightPro;
            rightPro *= nums[i];
        }
        for(int i=0; i<n; i++){
            nums[i] = leftNums[i] * rightNums[i];
        }
        return nums;
    }
};
