class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res=0;
        string s="";
        for(int i=max(num1,100); i<=num2; i++) {
            int j=i;
            while(j) {
                s+=('0'+(j%10));
                j/=10;
            }
            for(j=1; j<s.size()-1; j++) {
                if(s[j]>s[j-1]&&s[j]>s[j+1]) res++;
                if(s[j]<s[j-1]&&s[j]<s[j+1]) res++;
            }
            s="";
        }
        return res;
    }
};