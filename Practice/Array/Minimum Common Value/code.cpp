class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, ans=INT_MAX;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                ans = nums1[i];
                break;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
