class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0, prod = 1;

        if(k <= 1)
            return 0;

        while(right < nums.size()){
            prod *= nums[right];
            while(prod >= k)    prod /= nums[left++];
            count += 1 + (right - left);
            right++;
        }
        return count;
    }
};
