int findMin(int* nums, int numsSize) {
    int l=0, r=numsSize-1, key=nums[0];
    while(l<r) {
        int mid=(r-l)/2+l;
        // if(nums[l]<nums[r]) return nums[l];
        if(nums[mid]>nums[r]) {
            l=mid+1;
        } else if(nums[mid]<nums[r]) {
            r=mid; 
        } else r--;
    }
    if(nums[l]>key) return key;
    return nums[l];
}
