int findMin(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++) {
        for(int j=0; j<numsSize-i-1; j++) {
            if(nums[j]>nums[j+1]) {
                nums[j]=nums[j]+nums[j+1];
                nums[j+1]=nums[j]-nums[j+1];
                nums[j]=nums[j]-nums[j+1];
            }
        }
    }
    return nums[0];
}