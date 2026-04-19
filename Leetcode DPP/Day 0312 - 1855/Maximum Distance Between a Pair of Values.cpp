class Solution {
public:
    int maxDistance(vector<int>& n1, vector<int>& n2) {
        int i=0, j=0;
        int res=0;
        while(i<n1.size()) {
            while((j+1)!=n2.size()&&n1[i]<=n2[j+1]) {
                
            j++;
        }
         if(j==n2.size()) continue;
        res=max(res, j-i);
            i++;
        }
        return res;
    }
    
};