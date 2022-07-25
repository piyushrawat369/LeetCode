// equal_range()

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        pair<vector<int>::iterator, vector<int>::iterator> range;
        
        range = equal_range(nums.begin(), nums.end(), target);
        int tleft = distance(nums.begin(), range.first);
        
        if(tleft == nums.size() || nums[tleft] != target) return {-1, -1};
        
        return {tleft, (int)distance(nums.begin(), range.second) - 1};
    }
};
