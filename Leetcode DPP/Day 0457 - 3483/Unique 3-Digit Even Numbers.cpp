class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        // int no=0,ne=0,ne0=0;
        // for(int i=0;i<n;i++){
        //     if(digits[i]%2==0){
        //         if(digits[i]!=0){
        //             ne0++;
        //         } 
        //         ne++;
        //     } else {
        //         no++;
        //     }
        // }
        // cout<<n<<" "<<ne<<" "<<no<<" "<<ne0<<endl;
        // return no*(ne)*(ne-1)+no*(no-1)*ne+ne0*no*(ne-1)+ne0*(ne-1)*(ne-2);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(digits[i]!=0){
                        if(digits[i]%2==0){
                            if(i!=j){
                                if(digits[j]%2==0){
                                    if(i!=k&&j!=k&&digits[k]%2==0){
                                        mp[digits[i]*100+digits[j]*10+digits[k]]++;
                                    }
                                } else {
                                    if(i!=k&&j!=k&&digits[k]%2==0){
                                        mp[digits[i]*100+digits[j]*10+digits[k]]++;
                                    }
                                }  
                            }
                        } else {
                            if(i!=j){
                                if(digits[j]%2==0){
                                    if(i!=k&&j!=k&&digits[k]%2==0){
                                        mp[digits[i]*100+digits[j]*10+digits[k]]++;
                                    }
                                } else if(i!=j) {
                                    if(i!=k&&j!=k&&digits[k]%2==0){
                                        mp[digits[i]*100+digits[j]*10+digits[k]]++;
                                    }
                                }
                            }
                        }
                    }
                    
                }
            }
        }
        // for(auto i : mp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        return mp.size();
    }
};