int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestSum = 1000000000;
        
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int diff = 0;
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == target){
                    return sum;
                }
                
                if(abs(target - sum) < abs(target - closestSum)){
                    closestSum = sum;
                }
                
                if(sum > target){
                    k--;
                }
                    
                else{
                    j++;
                }
            }
        }
        return closestSum;
    }
