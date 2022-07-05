// Time complexity : O(n^3)
// Space complexity : O(1)
// Time Limit Exceeded

class Solution {
private: 
    bool contains(vector<int>& nums, int num){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == num){
                return true;
            }
        }
        return false;
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        int longestStreak = 0;
        
        for(int num: nums){
            int currentNum = num;
            int currentStreak = 1;
            
            while(contains(nums, currentNum + 1)){
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
        return longestStreak;
    }
};
