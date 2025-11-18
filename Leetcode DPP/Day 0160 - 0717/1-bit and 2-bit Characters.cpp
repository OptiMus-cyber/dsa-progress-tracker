class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0, n=bits.size();
        for(; i<n-1; i++) {
            if(bits[i]==1) i++;
        }
        return n!=i;
    }
};