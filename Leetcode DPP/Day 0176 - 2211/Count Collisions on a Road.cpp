class Solution {
public:
    int conv(char c) {
        if(c=='L') return -1;
        if(c=='R') return 1;
        return 0;
    }
    int countCollisions(string dir) {
        int cnt=0, curr, next;
        bool f=false;
        int idx=-1;
        for(idx=dir.size()-1; idx>=0; idx--) 
            if(dir[idx]=='S'||dir[idx]=='L')
                break;
        for(int i=0; i<dir.size()-1; i++) {
            if(f&&dir[i]=='L') curr=0;
            else curr=conv(dir[i]);
            if((i+1)<=idx&&dir[i+1]=='R') next=1;
            else next=conv(dir[i+1])+1;
            if(curr==next) cnt++;
            else if(curr>next) cnt+=2;
            if(dir[i]=='S'||dir[i]=='R') f=true;
            // cout<<curr<<" "<<next<<" "<<cnt<<endl;
        }
        return cnt;
    }
};