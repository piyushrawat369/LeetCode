// Time Complexity: O(log N)
// Auxiliary Space: O(1)


int searchInsert(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int start = 0;
        while(start <= end){
            int mid = (start + end)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = start + 1;
            }
            else{
                end = end - 1;
            }
                
        }
        return end+1;
    }
