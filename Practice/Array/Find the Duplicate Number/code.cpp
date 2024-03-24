class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]) != s.end(nums[i]))
                return nums[i];
            
            s.insert(nums[i]);
        }
        return -1;
    }
};
