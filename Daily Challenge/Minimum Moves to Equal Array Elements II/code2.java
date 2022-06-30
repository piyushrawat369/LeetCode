public int minMoves2(int[] nums) {
        int n = nums.length;
        int m = n-1;
        int steps = 0;
        
        Arrays.sort(nums);
        
        for(int i=0; i<n/2; i++){
            steps += Math.abs(nums[i] - nums[m-i]);
        }
        
        return steps;
    }
