class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n) {
            arr.push_back(n%10);
            n/=10;
        }
        int maxi=-1;
        for(int i=0; i<arr.size(); i++) {
            for(int j=0; j<arr.size(); j++) {
                if(i!=j) {
                    maxi=max(maxi, arr[i]*arr[j]);
                }
            } 
        }
        return maxi;
    }
};