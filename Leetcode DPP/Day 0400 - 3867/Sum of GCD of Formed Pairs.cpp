class Solution {
public:
    int hcf(int a, int b) {
        // Euclidean algorithm
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int maxi = nums[0];
        vector<int> arr;
        
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            arr.push_back(hcf(nums[i], maxi));  // still using hcf
        }
        
        sort(arr.begin(), arr.end());  // keep if pairing requires sorted order
        
        for (int i = 0; i < n / 2; i++) {
            ans += hcf(arr[i], arr[n - i - 1]);  // still using hcf
        }
        
        return ans;
    }
};
