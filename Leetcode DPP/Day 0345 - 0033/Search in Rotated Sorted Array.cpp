class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
            int mid=(r-l)/2+l;
            if(nums[mid]==tar) return mid;
            else if(nums[l]>tar) {
                if(nums[mid]>tar&&nums[mid]<nums[l]) {
                    r=mid-1;
                } else {
                    l=mid+1;
                }
            } else {
                if(nums[mid]<tar&&nums[mid]>=nums[l]) {
                    l=mid+1;
                } else {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};